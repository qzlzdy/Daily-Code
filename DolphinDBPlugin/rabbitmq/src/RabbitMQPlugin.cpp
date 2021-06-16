#include "RabbitMQPlugin.h"

#include "amqpcpp.h"
#include "amqpcpp/libevent.h"
#include "event2/event.h"
#include "EventLoop.h"
#include "dolphindb.pb.h"
#include "ScalarImp.h"
#include "ConstantMarshall.h"

#include <cassert>
#include <sstream>
#include <string>
#include <thread>

using namespace std;

unordered_map<AMQP::TcpConnection *, ThreadSP> conns;

static AMQP::TcpConnection *connect(AMQP::Address &addr){
    SmartPointer<EventLoop> loop = new EventLoop(addr);
    AMQP::TcpConnection *connection = loop->connection();
    ThreadSP thread = new Thread(loop);
    conns[connection] = thread;
    thread->start();
    return connection;
}

static AMQP::TcpConnection *connect(string &host, int port, string &username, string &password, string &vhost){
    AMQP::Login login(username, password);
    AMQP::Address address(host, port, login, vhost);
    return connect(address);
}

static void onConnectionClose(Heap *heap, vector<ConstantSP> &arguments){
    AMQP::TcpConnection *connection = reinterpret_cast<AMQP::TcpConnection *>(arguments[0]->getLong());
    conns.erase(connection);
}

ConstantSP connection(Heap *heap, vector<ConstantSP> &arguments){
    if(arguments[0]->getType() != DT_STRING){
        throw IllegalArgumentException(__FUNCTION__, "host must be a string");
    }
    string host = arguments[0]->getString();

    int port = 5672;
    if(arguments.size() > 1 && !arguments[1]->isNull()){
        if(arguments[1]->getCategory() != INTEGRAL){
            throw IllegalArgumentException(__FUNCTION__, "port must be a integral type");
        }
        port = arguments[1]->getInt();
    }

    string username = "guest";
    if(arguments.size() > 2 && !arguments[2]->isNull()){
        if(arguments[2]->getType() != DT_STRING){
            throw IllegalArgumentException(__FUNCTION__, "username must be a string");
        }
        username = arguments[2]->getString();
    }

    string password = "guest";
    if(arguments.size() > 3 && !arguments[3]->isNull()){
        if(arguments[3]->getType() != DT_STRING){
            throw IllegalArgumentException(__FUNCTION__, "password must be a string");
        }
        password = arguments[3]->getString();
    }

    string vhost = "/";
    if(arguments.size() > 4 && !arguments[4]->isNull()){
        if(arguments[4]->getType() != DT_STRING){
            throw IllegalArgumentException(__FUNCTION__, "vhost must be a string");
        }
        vhost = arguments[4]->getString();
    }
    
    AMQP::TcpConnection *connection = connect(host, port, username, password, vhost);
    FunctionDefSP onClose = Util::createSystemProcedure("onEventClose", onConnectionClose, 1, 1);
    return Util::createResource(reinterpret_cast<long long>(connection), "RabbitMQ connection handle", onClose, heap->currentSession());
}

static AMQP::TcpConnection *connect(string uri){
    AMQP::Address address(uri);
    return connect(address);
}

ConstantSP connectionAMQP(Heap *heap, vector<ConstantSP> &arguments){
    if(arguments[0]->getType() != DT_STRING){
        throw IllegalArgumentException(__FUNCTION__, "amqpURI must be a string");
    }
    string amqpURI = arguments[0]->getString();
    AMQP::TcpConnection *connection = connect(amqpURI);
    FunctionDefSP onClose = Util::createSystemProcedure("onConnectionClose", onConnectionClose, 1, 1);
    return Util::createResource(reinterpret_cast<long long>(connection), "RabbitMQ connection handle", onClose, heap->currentSession());
}

static void onChannelClose(Heap *heap, vector<ConstantSP> &arguments){
    AMQP::TcpChannel *channel = reinterpret_cast<AMQP::TcpChannel *>(arguments[0]->getLong());
    delete channel;
}

ConstantSP channel(Heap *heap, vector<ConstantSP> &arguments){
    if(arguments[0]->getType() != DT_RESOURCE || arguments[0]->getString() != "RabbitMQ connection handle"){
        throw IllegalArgumentException(__FUNCTION__, "channel must be a RabbitMQ connection channel handle");
    }
    AMQP::TcpConnection *connection = reinterpret_cast<AMQP::TcpConnection *>(arguments[0]->getLong());
    AMQP::TcpChannel *channel = new AMQP::TcpChannel(connection);
    FunctionDefSP onClose = Util::createSystemProcedure("onChannelClose", onChannelClose, 1, 1);
    return Util::createResource(reinterpret_cast<long long>(channel), "RabbitMQ channel handle", onClose, heap->currentSession());
}

static int parseFlags(const VectorSP &vec){
    int flags = 0;
    for(INDEX i = 0; i < vec->size(); ++i){
        string flag = vec->get(i)->getString();
        if(flag == "durable"){
            flags |= AMQP::durable;
        }
        else if(flag == "autodelete"){
            flags |= AMQP::autodelete;
        }
        else if(flag == "passive"){
            flags |= AMQP::passive;
        }
        else if(flag == "exclusive"){
            flags |= AMQP::exclusive;
        }
        else if(flag == "internal"){
            flags |= AMQP::internal;
        }
        else{
            throw IllegalArgumentException(__FUNCTION__, "unknown flag '" + flag + "'");
        }
    }
    return flags;
}

ConstantSP declareQueue(Heap *heap, vector<ConstantSP> &arguments){
    if(arguments[0]->getType() != DT_RESOURCE || arguments[0]->getString() != "RabbitMQ channel handle"){
        throw IllegalArgumentException(__FUNCTION__, "channel must be a RabbitMQ connection channel handle");
    }
    AMQP::TcpChannel *channel = reinterpret_cast<AMQP::TcpChannel *>(arguments[0]->getLong());

    string name = "";
    if(arguments.size() > 1 && !arguments[1]->isNull()){
        if(arguments[1]->getType() != DT_STRING){
            throw IllegalArgumentException(__FUNCTION__, "name must be a string");
        }
        name = arguments[1]->getString();
    }

    int flags = 0;
    if(arguments.size() > 2 && !arguments[2]->isNull()){
        if(arguments[2]->getForm() != DF_VECTOR){
            throw IllegalArgumentException(__FUNCTION__, "flags must be a string vector");
        }
        flags = parseFlags(arguments[2]);
    }

    auto onDeclareSuccess = [](const string &name, uint32_t messageCount, uint32_t consumerCount){
        cout << "Queue '" << name << "' has been declared with " << messageCount << " messages and " << consumerCount << " consumers" << endl;
    };

    auto onDeclareError = [](const char *message){
        cerr << "Queue declared failed because " << message << endl;
    };

    if(name == ""){
        channel->declareQueue(flags).onSuccess(onDeclareSuccess).onError(onDeclareError);
    }
    else{
        channel->declareQueue(name, flags).onSuccess(onDeclareSuccess).onError(onDeclareError);
    }

    return new Void();
}

static AMQP::ExchangeType parseType(string type){
    if(type == "fanout"){
        return AMQP::ExchangeType::fanout;
    }
    else if(type == "direct"){
        return AMQP::ExchangeType::direct;
    }
    else if(type == "topic"){
        return AMQP::ExchangeType::topic;
    }
    else if(type == "headers"){
        return AMQP::ExchangeType::headers;
    }
    else if(type == "consistent_hash"){
        return AMQP::ExchangeType::consistent_hash;
    }
    else{
        throw IllegalArgumentException(__FUNCTION__, "unknown type '" + type + "'");
    }
}

ConstantSP declareExchange(Heap *heap, vector<ConstantSP> &arguments){
    if(arguments[0]->getType() != DT_RESOURCE || arguments[0]->getString() != "RabbitMQ channel handle"){
        throw IllegalArgumentException(__FUNCTION__, "channel must be a RabbitMQ connection channel handle");
    }
    AMQP::TcpChannel *channel = reinterpret_cast<AMQP::TcpChannel *>(arguments[0]->getLong());
    
    string name = "";
    if(arguments.size() > 1 && !arguments[1]->isNull()){
        if(arguments[1]->getType() != DT_STRING){
            throw IllegalArgumentException(__FUNCTION__, "name must be a string");
        }
        name = arguments[1]->getString();
    }

    AMQP::ExchangeType type = AMQP::ExchangeType::fanout;
    if(arguments.size() > 2 && !arguments[2]->isNull()){
        if(arguments[2]->getType() != DT_STRING){
            throw IllegalArgumentException(__FUNCTION__, "type must be a string");
        }
        type = parseType(arguments[2]->getString());
    }

    int flags = 0;
    if(arguments.size() > 3 && !arguments[3]->isNull()){
        if(arguments[3]->getType() != DT_STRING){
            throw IllegalArgumentException(__FUNCTION__, "flags must be a string vector");
        }
        flags = parseFlags(arguments[3]);
    }

    auto onDeclareSuccess = [](){
        cout << "Exchange declare succeed" << endl;
    };

    auto onDeclareError = [](const char *message){
        cerr << "Exchange declare failed because " << message << endl;
    };

    if(name == ""){
        channel->declareExchange(type, flags).onSuccess(onDeclareSuccess).onError(onDeclareError);
    }
    else{
        channel->declareExchange(name, type, flags).onSuccess(onDeclareSuccess).onError(onDeclareError);
    }

    return new Void();
}

static ddbprotobuf::Scalar protobufSerialize(const ConstantSP &ddbScalar){
    assert(ddbScalar->getForm() == DF_SCALAR);
    ddbprotobuf::Scalar pbScalar;
    pbScalar.set_is_null(ddbScalar->isNull());
    switch(ddbScalar->getType()){
    case DT_BOOL:
        pbScalar.set_dt_bool(ddbScalar->getBool());
        break;
    case DT_CHAR:
    case DT_SHORT:
    case DT_INT:
    case DT_DATE:
    case DT_MONTH:
    case DT_TIME:
    case DT_MINUTE:
    case DT_SECOND:
    case DT_DATETIME:
        pbScalar.set_dt_int(ddbScalar->getInt());
        break;
    case DT_LONG:
    case DT_TIMESTAMP:
    case DT_NANOTIME:
    case DT_NANOTIMESTAMP:
        pbScalar.set_dt_long(ddbScalar->getLong());
        break;
    case DT_FLOAT:
        pbScalar.set_dt_float(ddbScalar->getFloat());
        break;
    case DT_DOUBLE:
        pbScalar.set_dt_double(ddbScalar->getDouble());
        break;
    case DT_STRING:
    case DT_SYMBOL:
        pbScalar.set_dt_string(ddbScalar->getString());
        break;
    default:
        throw RuntimeException("can not serialize " + Util::getDataTypeString(ddbScalar->getType()) + " type");
    }
    return pbScalar;
}

static ddbprotobuf::Vector protobufSerialize(const VectorSP &ddbVector){
    ddbprotobuf::Vector pbVector;
    for(INDEX i = 0; i < ddbVector->size(); ++i){
        ddbprotobuf::Scalar *pbScalar = pbVector.add_elements();
        *pbScalar = protobufSerialize(ddbVector->get(i));
    }
    return pbVector;
}

static ddbprotobuf::Table protobufSerialize(const TableSP &ddbTable){
    ddbprotobuf::Table pbTable;
    for(INDEX i = 0; i < ddbTable->columns(); ++i){
        ddbprotobuf::Vector *pbVector = pbTable.add_columns();
        *pbVector = protobufSerialize(static_cast<VectorSP>(ddbTable->getColumn(i)));
    }
    return pbTable;
}

static ddbprotobuf::Dictionary protobufSerialize(const DictionarySP &ddbDictionary){
    ddbprotobuf::Dictionary pbDict;
    pbDict.set_allocated_keys(new ddbprotobuf::Vector(protobufSerialize(static_cast<VectorSP>(ddbDictionary->keys()))));
    pbDict.set_allocated_values(new ddbprotobuf::Vector(protobufSerialize(static_cast<VectorSP>(ddbDictionary->values()))));
    return pbDict;
}

static string marshallSerializeToString(const ConstantSP &obj){
    DataOutputStreamSP buffer = new DataOutputStream;
    ConstantMarshallFactory marshallFactory(buffer);
    ConstantMarshall *marshall = marshallFactory.getConstantMarshall(obj->getForm());
    IO_ERR ret;
    marshall->start(obj, true, ret);
    string data(buffer->getBuffer(), buffer->size());
    ret = buffer->flush();
    return data;
}

static string protobufSerializeToString(const ConstantSP &obj){
    string data;
    ddbprotobuf::DolphinMessage ddbMessage;
    ddbprotobuf::Scalar *pbScalar;
    ddbprotobuf::Vector *pbVector;
    ddbprotobuf::Table *pbTable;
    ddbprotobuf::Dictionary *pbDictionary;
    switch(obj->getForm()){
    case DF_SCALAR:
        pbScalar = new ddbprotobuf::Scalar(protobufSerialize(obj));
        ddbMessage.set_allocated_df_scalar(pbScalar);
        break;
    case DF_VECTOR:
        pbVector = new ddbprotobuf::Vector(protobufSerialize(static_cast<VectorSP>(obj)));
        ddbMessage.set_allocated_df_vector(pbVector);
        break;
    case DF_TABLE:
        pbTable = new ddbprotobuf::Table(protobufSerialize(static_cast<TableSP>(obj)));
        ddbMessage.set_allocated_df_table(pbTable);
        break;
    case DF_DICTIONARY:
        pbDictionary = new ddbprotobuf::Dictionary(protobufSerialize(static_cast<DictionarySP>(obj)));
        ddbMessage.set_allocated_df_dictionary(pbDictionary);
        break;
    default:
        throw RuntimeException("can not serialize " + Util::getDataFormString(obj->getForm()) + " form");
    }
    ddbMessage.SerializeToString(&data);
    return data;
}

static void publish(AMQP::TcpChannel *channel, const string &exchange, const string &routingKey, const ConstantSP &message, string &format){
    string data;
    if(format == "default"){
        data = marshallSerializeToString(message);
    }
    else if(format == "bytestream"){
        if(message->getType() != DT_STRING){
            throw IllegalArgumentException(__FUNCTION__, "message must be a string with bytestream format");
        }
        data = message->getString();
    }
    else if(format == "protobuf"){
        data = protobufSerializeToString(message);
    }
    else{
        throw RuntimeException("unsupport format: " + format);
    }
    channel->publish(exchange, routingKey, data);
}

ConstantSP publish(Heap *heap, vector<ConstantSP> &arguments){
    if(arguments[0]->getType() != DT_RESOURCE || arguments[0]->getString() != "RabbitMQ channel handle"){
        throw IllegalArgumentException(__FUNCTION__, "channel must be a RabbitMQ connection channel handle");
    }
    AMQP::TcpChannel *channel = reinterpret_cast<AMQP::TcpChannel *>(arguments[0]->getLong());

    if(arguments[1]->getType() != DT_STRING){
        throw IllegalArgumentException(__FUNCTION__, "exchange must be a string");
    }
    string exchange = arguments[1]->getString();

    if(arguments[2]->getType() != DT_STRING){
        throw IllegalArgumentException(__FUNCTION__, "routing key must be a string");
    }
    string routingKey = arguments[2]->getString();

    ConstantSP message = arguments[3];

    string format = "default";
    if(arguments.size() > 4 && !arguments[4]->isNull()){
        if(arguments[4]->getType() != DT_STRING){
            throw IllegalArgumentException(__FUNCTION__, "format must be a string");
        }
        format = arguments[4]->getString();
    }

    publish(channel, exchange, routingKey, message, format);    
    return new Void();
}

static ConstantSP unserialize(const ddbprotobuf::Scalar &pbScalar){
    ConstantSP ddbScalar;
    switch(pbScalar.type_case()){
    case ddbprotobuf::Scalar::kDtBoolFieldNumber:
        ddbScalar = new Bool(pbScalar.dt_bool());
        break;
    case ddbprotobuf::Scalar::kDtIntFieldNumber:
        ddbScalar = new Int(pbScalar.dt_int());
        break;
    case ddbprotobuf::Scalar::kDtLongFieldNumber:
        ddbScalar = new Long(pbScalar.dt_long());
        break;
    case ddbprotobuf::Scalar::kDtFloatFieldNumber:
        ddbScalar = new Float(pbScalar.dt_float());
        break;
    case ddbprotobuf::Scalar::kDtDoubleFieldNumber:
        ddbScalar = new Double(pbScalar.dt_double());
        break;
    case ddbprotobuf::Scalar::kDtStringFieldNumber:
        ddbScalar = new String(pbScalar.dt_string());
        break;
    default:
        throw RuntimeException("unknown field number in Scalar");
    }
    if(pbScalar.is_null()){
        ddbScalar->setNull();
    }
    return ddbScalar;
}

static VectorSP unserialize(const ddbprotobuf::Vector &pbVector, bool isTableColumn = false){
    VectorSP ddbVector = Util::createVector(DT_ANY, 0);
    for(int i = 0; i < pbVector.elements_size(); ++i){
        ConstantSP ddbScalar = unserialize(pbVector.elements(i));
        if(isTableColumn && ddbVector->size() == 0){
            ddbVector = Util::createVector(ddbScalar->getType(), 0);
        }
        ddbVector->append(ddbScalar);
    }
    return ddbVector;
}

static TableSP unserialize(const ddbprotobuf::Table &pbTable){
    vector<string> colNames;
    vector<ConstantSP> cols;
    for(int i = 0; i < pbTable.columns_size(); ++i){
        colNames.push_back("col" + to_string(i));
        cols.push_back(unserialize(pbTable.columns(i), true));
    }
    return Util::createTable(colNames, cols);
}

static DictionarySP unserialize(const ddbprotobuf::Dictionary &pbDict){
    VectorSP keys = unserialize(pbDict.keys());
    VectorSP values = unserialize(pbDict.values());
    if(keys->size() == 0){
        return Util::createDictionary(DT_INT, nullptr, DT_ANY, nullptr);
    }
    DictionarySP ddbDictionary = Util::createDictionary(keys->get(0)->getType(), nullptr, DT_ANY, nullptr);
    for(INDEX i = 0; i < keys->size(); ++i){
        ddbDictionary->set(keys->get(i), values->get(i));
    }
    return ddbDictionary;
}

static ConstantSP test(const string &data){
    ddbprotobuf::DolphinMessage recv;
    recv.ParseFromString(data);
    switch(recv.form_case()){
    case ddbprotobuf::DolphinMessage::kDfScalarFieldNumber:
        return unserialize(recv.df_scalar());
    case ddbprotobuf::DolphinMessage::kDfVectorFieldNumber:
        return unserialize(recv.df_vector());
    case ddbprotobuf::DolphinMessage::kDfTableFieldNumber:
        return unserialize(recv.df_table());
    case ddbprotobuf::DolphinMessage::kDfDictionaryFieldNumber:
        return unserialize(recv.df_dictionary());
    default:
        throw RuntimeException("unknown field number in DolphinMessage");
    }
}

AMQP::TcpChannel *ch;
TableSP table;
ConstantSP consume(Heap *heap, vector<ConstantSP> &arguments){
    if(arguments[0]->getType() != DT_RESOURCE || arguments[0]->getString() != "RabbitMQ connection handle"){
        throw IllegalArgumentException(__FUNCTION__, "channel must be a RabbitMQ connection channel handle");
    }
    AMQP::TcpConnection *connection = reinterpret_cast<AMQP::TcpConnection *>(arguments[0]->getLong());
    ch = new AMQP::TcpChannel(connection);

    table = arguments[1];

    auto startCb = [](const string &consumertag){
        cout << "consume operation started: " << consumertag << endl;
    };

    auto errorCb = [](const char *message){
        cout << "consume operation failed: " << message << endl;
    };

    auto messageCb = [](const AMQP::Message &message, uint64_t deliveryTag, bool redelivered){
        string data(message.body(), message.bodySize());
        TableSP X = test(data);
        vector<ConstantSP> V;
        for(INDEX i = 0; i < X->columns(); ++i){
            V.push_back(X->getColumn(i));
        }
        INDEX insertRow;
        string errMsg;
        table->append(V, insertRow, errMsg);
        cerr << errMsg << endl;

        ch->ack(deliveryTag); 
    };
    
    ch->consume("test", "xxx").onReceived(messageCb).onSuccess(startCb).onError(errorCb);
    return new Void();
}

#include <utili
