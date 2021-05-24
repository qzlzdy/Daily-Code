#include "plugin_bloomberg.h"

ConstantSP bloomSubscribe(Heap *heap, vector<ConstantSP> args)
{
    const auto usage = string("Usage: subscribe(ipaddress, port, service, appname, handler, subname, subindex )");

    if(args[0]->getType()!=DT_STRING /*|| !is_ipv4_str(args[0]->getString().c_str())*/)
        throw IllegalArgumentException(__FUNCTION__, usage + "ipaddress must be a legal string.");
    if(args[1]->getType()!=DT_INT)
        throw IllegalArgumentException(__FUNCTION__, usage + "port should be an integer.");
    if(args[2]->getType()!=DT_STRING)
        throw IllegalArgumentException(__FUNCTION__, usage + "service should be a string.");
    if(args[3]->getType()!=DT_STRING)
        throw IllegalArgumentException(__FUNCTION__, usage + "appname should be a string.");
    if(!(args[4]->getType()==DT_FUNCTIONDEF || args[4]->isTable()))
        throw IllegalArgumentException(__FUNCTION__, usage + "handler should be a function or a table.");
    if(args[4]->getType() == DT_FUNCTIONDEF){
        FunctionDefSP handle = args[4];
        if(handle->getParamCount() != 1)
            throw IllegalArgumentException(__FUNCTION__, usage + "handle function must accept only one param.");
    }
    if(args[5]->getForm()!=DF_VECTOR || args[5]->getType()!=DT_STRING)
        throw IllegalArgumentException(__FUNCTION__ ,usage + "subname should be a string vector");
    if(args[6]->getForm()!=DF_VECTOR || args[6]->getType()!=DT_STRING)
        throw IllegalArgumentException(__FUNCTION__ ,usage + "subindex should be a string vector");

    std::unique_ptr<SubConnection> cup(new SubConnection(heap, args[0]->getString(), args[1]->getInt(), args[2]->getString(), args[3]->getString(), args[4], args[5], args[6]));
    FunctionDefSP onClose(Util::createSystemProcedure("blpapi subscription connection onClose()", blpapiOnClose<SubConnection>, 1, 1));
    ConstantSP conn = Util::createResource(
            (long long)cup.release(),
            "blpapi subscribe connection",
            onClose,
            heap->currentSession()
    );
    status_dict->set(std::to_string(conn->getLong()),conn);

    return conn;
}

ConstantSP bloomUnsubscribe(Heap *heap, vector<ConstantSP> args)
{
    std::string usage = "Usage: unsubscribe(connection or connection ID). ";
    SubConnection *sc = nullptr;
    string key;
    ConstantSP conn = nullptr;
    auto handle = args[0];
    switch (handle->getType()){
        case DT_RESOURCE:
            sc = (SubConnection *)(handle->getLong());
            key = std::to_string(handle->getLong());
            conn = status_dict->getMember(key);
            if(conn->isNothing())
                throw IllegalArgumentException(__FUNCTION__, "Invalid connection object.");
            break;
        case DT_STRING:
            key = handle->getString();
            conn = status_dict->getMember(key);
            if(conn->isNothing())
                throw IllegalArgumentException(__FUNCTION__, "Invalid connection string.");
            else
                sc = (SubConnection *)(conn->getLong());
            break;
        case DT_LONG:
            key = std::to_string(handle->getLong());
            conn = status_dict->getMember(key);
            if(conn->isNothing())
                throw IllegalArgumentException(__FUNCTION__, "Invalid connection integer.");
            else
                sc = (SubConnection *)(conn->getLong());
            break;
        case DT_INT:
            key = std::to_string(handle->getInt());
            conn = status_dict->getMember(key);
            if(conn->isNothing())
                throw IllegalArgumentException(__FUNCTION__, "Invalid connection integer.");
            else
                sc = (SubConnection *)(conn->getLong());
            break;
        default:
            throw IllegalArgumentException(__FUNCTION__, "Invalid connection object.");
    }

    bool bRemoved=status_dict->remove(new String(key));
    if (bRemoved && sc != nullptr) {
        sc->cancelThread();
        cout << "subscription: " << conn->getLong() << " : " << sc->getAddress() << " is stopped" << endl;
    }

    return new Void();
}

ConstantSP bloomGetSubScribeStatus(Heap *heap, vector<ConstantSP> args)
{
    int size = status_dict->size();
    ConstantSP connectionIdVec = Util::createVector(DT_STRING, size);
    ConstantSP userVec = Util::createVector(DT_STRING, size);
    ConstantSP addressVec = Util::createVector(DT_STRING,size);
    ConstantSP serviceVec = Util::createVector(DT_STRING, size);
    ConstantSP appVec = Util::createVector(DT_STRING, size);
    ConstantSP timestampVec = Util::createVector(DT_TIMESTAMP, size);
    VectorSP keys = status_dict->keys();
    for(int i = 0; i < keys->size();i++){
        string key = keys->getString(i);
        connectionIdVec->setString(i,key);
        ConstantSP conn = status_dict->getMember(key);
        auto *sc = (SubConnection *)(conn->getLong());
        addressVec->setString(i,sc->getAddress());
        serviceVec->setString(i,sc->getService());
        appVec->setString(i,sc->getAppName());
        timestampVec->setLong(i,sc->getCreateTime());
        userVec->setString(i,sc->getSession()->getUser()->getUserId());
    }

    vector<string> colNames = {"subscriptionId","user","address","service","appname","createTimestamp"};
    vector<ConstantSP> cols = {connectionIdVec,userVec,addressVec,serviceVec,appVec,timestampVec};
    return Util::createTable(colNames,cols);
}


static bool is_ipv4_str(const char* ipv4)
{
    if (!ipv4 || !ipv4[0])
        return false;

    size_t len = strlen(ipv4);
    if (len < 7 || len > 15)
        return false;

    int num[4] = {0};
    char c = 0;

    if (sscanf(ipv4, "%d.%d.%d.%d%c", num, num+1, num+2, num+3, &c) != 4)
        return false;

    for (int i : num)
        if (i < 0 || i > 255)
            return false;

    return true;
}

template<typename T>
static void blpapiOnClose(Heap *heap, vector<ConstantSP> &args) {
    T* pObject = (T*)(args[0]->getLong());
    if(pObject!= nullptr) {
        delete (T *) (args[0]->getLong());
        args[0]->setLong(0);
    }
}