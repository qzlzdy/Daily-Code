//
// Created by ypfan on 2020/12/3.
//

#include "Session.h"

ConstantSP SubscriptionEventHandler::getVector(const Element& element){
    auto result = Util::createVector(DT_ANY,0);
    for(int i = 0;i<(int)element.numElements();i++)
        result->append(blp_to_dolphindb(element.getValueAsElement(i)));
    return result;
}

ConstantSP SubscriptionEventHandler::getDict(const Element& element){
    auto result = Util::createDictionary(DT_STRING, nullptr,DT_ANY, nullptr);
    for(int i = 0;i<(int)element.numElements();i++)
        result->set(element.getValueAsElement(i).getValueAsString(),blp_to_dolphindb(element));
    return result;
}

ConstantSP SubscriptionEventHandler::blp_to_dolphindb(const Element& element){
    ConstantSP result;
    Datetime time;
    switch (element.datatype()) {
        case BLPAPI_DATATYPE_BOOL:
            result = Util::createConstant(DT_BOOL);
            result->setBool(0, element.getValueAsBool());
            break;
        case BLPAPI_DATATYPE_CHAR:
            result = Util::createConstant(DT_CHAR);
            result->setChar(element.getValueAsChar());
            break;
        case BLPAPI_DATATYPE_INT32:
            result = Util::createConstant(DT_INT);
            result->setInt(element.getValueAsInt32());
            break;
        case BLPAPI_DATATYPE_INT64:
            result = Util::createConstant(DT_LONG);
            result->setLong(element.getValueAsInt64());
            break;
        case BLPAPI_DATATYPE_FLOAT32:
            result = Util::createConstant(DT_FLOAT);
            result->setFloat(element.getValueAsFloat32());
            break;
        case BLPAPI_DATATYPE_FLOAT64:
            result = Util::createConstant(DT_DOUBLE);
            result->setDouble(element.getValueAsFloat64());
            break;
        case BLPAPI_DATATYPE_DATE:
            result = Util::createConstant(DT_DATE);
            time = element.getValueAsDatetime();
            result->setInt(Util::countDays(time.year(),time.month(),time.day()));
            break;
        case BLPAPI_DATATYPE_TIME:
            result = Util::createConstant(DT_TIME);
            time = element.getValueAsDatetime();
            result->setInt(time.hours()*3600000+time.minutes()*60000+time.seconds()*1000+time.milliseconds());
            break;
        case BLPAPI_DATATYPE_DATETIME:
            result = Util::createConstant(DT_DATETIME);
            time = element.getValueAsDatetime();
            //result->setLong(static_cast<long long>(Util::countDays(time.year(),time.month(),time.day()))*86400000L+(time.hours()*3600+time.minutes()*60+time.seconds())*1000L+time.milliseconds());
            result->setInt(time.hours()*3600000+time.minutes()*60000+time.seconds()*1000+time.milliseconds());
            break;
        case BLPAPI_DATATYPE_SEQUENCE:
            if(element.isArray())
                result = getVector(element);
            else
                result = getDict(element);
            break;
        default:
            result = Util::createConstant(DT_STRING);
            result->setString(element.getValueAsString());
            break;
    }
    return result;
}

ConstantSP SubscriptionEventHandler::getConstantVect(blpapi_DataType_t type){
    ConstantSP result;
    switch (type) {
        case BLPAPI_DATATYPE_BOOL:
            result = Util::createVector(DT_BOOL,0);
            break;
        case BLPAPI_DATATYPE_CHAR:
            result = Util::createVector(DT_CHAR,0);
            break;
        case BLPAPI_DATATYPE_INT32:
            result = Util::createVector(DT_INT,0);
            break;
        case BLPAPI_DATATYPE_INT64:
            result = Util::createVector(DT_LONG,0);
            break;
        case BLPAPI_DATATYPE_FLOAT32:
            result = Util::createVector(DT_FLOAT,0);
            break;
        case BLPAPI_DATATYPE_FLOAT64:
            result = Util::createVector(DT_DOUBLE,0);
            break;
        case BLPAPI_DATATYPE_DATE:
            result = Util::createVector(DT_DATE,0);
            break;
        case BLPAPI_DATATYPE_TIME:
            result = Util::createVector(DT_TIME,0);
            break;
        case BLPAPI_DATATYPE_DATETIME:
            result = Util::createVector(DT_TIME,0);
            break;
        case BLPAPI_DATATYPE_SEQUENCE:
            result = Util::createVector(DT_ANY,0);
            break;
        default:
            result = Util::createVector(DT_STRING,0);
            break;
    }
    return result;
}

SubscriptionEventHandler::SubscriptionEventHandler(Heap* heap, const ConstantSP& handle, const ConstantSP& subname, const ConstantSP& subindex)
        :heap_(heap),handle_(handle),subname_(subname),subindex_(subindex){}

bool SubscriptionEventHandler::processEvent(const Event& event, blpapi::Session* session){
    vector<string> colNames;
    colNames.emplace_back("name");
    for(int i = 0;i<subindex_->size();i++)
        colNames.push_back(subindex_->get(i)->getString());
    vector<ConstantSP> cols;
    MessageIterator msgIter(event);
    string dataEvent("MarketDataEvents");
    VectorSP parser;
    int message_num;
    bool flag = true;
    try {
        while(msgIter.next()){
            if (msgIter.message().messageType().string() == dataEvent) {
                if(flag)
                    cols.emplace_back(Util::createVector(DT_STRING,0));
                parser = cols[0];
                parser->append(subname_->get(msgIter.message().correlationId().asInteger()));
                message_num = msgIter.message().asElement().numElements();
                for (int i = 0; i < message_num; i++) {
                    if (flag)
                        cols.emplace_back(getConstantVect(static_cast<blpapi_DataType_t>(msgIter.message().asElement().getElement(i).datatype())));
                    parser = cols[i+1];
                    parser->append(blp_to_dolphindb(msgIter.message().asElement().getElement(i)));
                }
                flag = false;
            }
        }
        auto table_insert = Util::createTable(colNames, cols);

        if (handle_->isTable()) {
            TableSP result = handle_;
            if (result->isSegmentedTable()) {
                vector<ConstantSP> args = {result, table_insert};
                heap_->currentSession()->getFunctionDef("append!")->call(heap_, args);
            } else {
                INDEX insertedRows = table_insert->size();
                string errMsg;
                vector<ConstantSP> args = {table_insert};
                bool add = result->append(args, insertedRows, errMsg);
                if (!add) {
                    LOG_ERR(errMsg);
                }
            }
        } else {
            vector<ConstantSP> args = {table_insert};
            ((FunctionDefSP) handle_)->call(heap_, args);
        }
    }
    catch(TraceableException &exception){
        LOG_ERR(exception.what());
    }
    catch (Exception &exception) {
        LOG_ERR(exception.what());
    }

    return true;
}

BlpapiConn::BlpapiConn(Heap *heap, string ipaddress, int port, string service, string appname, ConstantSP handler, const ConstantSP& subname, const ConstantSP& subindex,bool* isStop)
        :ipaddress_(std::move(ipaddress)),port_(port),service_(std::move(service)),appname_(std::move(appname)),subname_(subname),subindex_(subindex),handle_(handler),heap_(heap),isStop_(isStop){
    session_ = heap->currentSession()->copy();
    session_->setUser(heap->currentSession()->getUser());
    session_->setOutput(new DummyOutput);
    eventHandler_ = new SubscriptionEventHandler(heap_,handle_,subname_,subindex_);
}

BlpapiConn::~BlpapiConn(){
    LOG_INFO("BlpapiConn::~BlpapiConn()");
    delete blp_sesson_;
    delete eventHandler_;
}

void BlpapiConn::run(){
    SessionOptions sessionOptions;
    sessionOptions.setServerHost(ipaddress_.c_str());
    sessionOptions.setServerPort(port_);
    AuthApplication authApp(appname_.c_str());
    AuthOptions autoOption(authApp);
    sessionOptions.setSessionIdentityOptions(autoOption);

    blp_sesson_ = new blpapi::Session(sessionOptions,eventHandler_);
    if(!blp_sesson_->start()){
        LOG_ERR("Failed to start session.");
        return;
    }
    if(!blp_sesson_->openService(service_.c_str())){
        LOG_ERR("Failed to open " + service_);
        return;
    }
    CorrelationId subscriptionId((long long )2);
    SubscriptionList subscriptions;
    int subSize = subname_->size();
    string subIndex = subindex_->get(0)->getString();
    for(int i = 1;i<subindex_->size();i++){
        subIndex+=",";
        subIndex+=subindex_->get(i)->getString();
    }
    try {
        for (int i = 0; i < subSize; i++)
            subscriptions.add(subname_->get(i)->getString().c_str(), subIndex.c_str(), "", CorrelationId(i));
        blp_sesson_->subscribe(subscriptions);
        while (true) {
            if(*isStop_){
                blp_sesson_->stop();
                break;
            }
        }
    }
    catch(Exception &exception){
        LOG_ERR(exception.what());
    }
}

SubConnection::SubConnection(Heap* heap, string ipaddress, int port, string service, string appname, ConstantSP handler, const ConstantSP& subname, const ConstantSP& subindex)
        :ipaddress_(std::move(ipaddress)),port_(port),service_(std::move(service)),appname_(std::move(appname)),handler_(handler),subname_(subname),subindex_(subindex){
    createTime_ = Util::getEpochTime();
    session_ = heap->currentSession()->copy();
    session_->setUser(heap->currentSession()->getUser());
    isStop = new bool(false);

    SmartPointer<BlpapiConn> conn = new BlpapiConn(heap, ipaddress_, port_, service_, appname_, handler_, subname_, subindex_,isStop);
    thread_ = new Thread(conn);
    thread_->start();
}

SubConnection::~SubConnection()
{
    LOG_INFO("SubConnection::~SubConnection()");
    thread delayDelete(waitThreadExit, thread_, isStop);
    delayDelete.detach();
}

string SubConnection::getAddress(){
    return ipaddress_+":"+to_string(port_);
}
long long SubConnection::getCreateTime() const{
    return createTime_;
}
string SubConnection::getService(){
    return service_;
}
string SubConnection::getAppName(){
    return appname_;
}
SessionSP SubConnection::getSession(){
    return session_;
}
void SubConnection::cancelThread(){
    *isStop = true;
    //thread_->cancel();
}

void SubConnection::waitThreadExit(ThreadSP t, bool *isStop){
    t->join();
    delete isStop;
}