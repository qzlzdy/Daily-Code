//
// Created by ypfan on 2020/12/3.
//

#ifndef BLOOMBERGPLUGIN_SESSION_H
#define BLOOMBERGPLUGIN_SESSION_H

#include "CoreConcept.h"
#include "Exceptions.h"
#include "Util.h"
#include "Types.h"
#include "Concurrent.h"
#include "ScalarImp.h"
#include "Logger.h"
#include <blpapi_session.h>
#include <blpapi_correlationid.h>
#include <blpapi_event.h>
#include <blpapi_message.h>
#include <blpapi_request.h>
#include <blpapi_subscriptionlist.h>

#include <iostream>
#include <string>
#include <utility>
#include <thread>

using namespace std;
using namespace BloombergLP;
using namespace blpapi;

class DummyOutput: public Output{
public:
    virtual bool timeElapsed(long long nanoSeconds){return true;}
    virtual bool write(const ConstantSP& obj){return true;}
    virtual bool message(const string& msg){return true;}
    virtual void enableIntermediateMessage(bool enabled) {}
    virtual IO_ERR done(){return OK;}
    virtual IO_ERR done(const string& errMsg){return OK;}
    virtual bool start(){return true;}
    virtual bool start(const string& message){return true;}
    virtual IO_ERR writeReady(){return OK;}
    virtual ~DummyOutput(){}
    virtual OUTPUT_TYPE getOutputType() const {return STDOUT;}
    virtual void close() {}
    virtual void setWindow(INDEX index,INDEX size){};
    virtual IO_ERR flush() {return OK;}
};

class SubscriptionEventHandler: public EventHandler
{
private:
    Heap* heap_{};
    ConstantSP handle_;
    ConstantSP subname_;
    ConstantSP subindex_;
public:
    SubscriptionEventHandler()=default;
    SubscriptionEventHandler(Heap* heap, const ConstantSP& handle, const ConstantSP& subname, const ConstantSP& subindex);
    static ConstantSP getVector(const Element& element);
    static ConstantSP getDict(const Element& element);
    static ConstantSP blp_to_dolphindb(const Element& element);
    static ConstantSP getConstantVect(blpapi_DataType_t type);
    bool processEvent(const Event& event, blpapi::Session* session) override;
};

class BlpapiConn: public Runnable
{
private:
    string ipaddress_;
    int port_{};
    string service_;
    string appname_;
    ConstantSP subname_;
    ConstantSP subindex_;
    SessionSP session_;
    ConstantSP handle_;
    Heap* heap_{};
    blpapi::Session* blp_sesson_{};
    bool* isStop_{};
    SubscriptionEventHandler* eventHandler_{};
public:
    BlpapiConn()= default;
    BlpapiConn(Heap *heap, string ipaddress, int port, string service, string appname, ConstantSP handler, const ConstantSP& subname, const ConstantSP& subindex,bool* isStop);
    ~BlpapiConn() override;

    void run() override;
};

class SubConnection{
private:
    string ipaddress_;
    int port_{};
    string service_;
    string appname_;
    ConstantSP handler_;
    ConstantSP subname_;
    ConstantSP subindex_;
    long long createTime_{};
    ThreadSP thread_;
    SessionSP session_;
    bool* isStop{};
    static void waitThreadExit(ThreadSP t, bool *isStop);
public:
    SubConnection() = default;
    SubConnection(Heap* heap, string ipaddress, int port, string service, string appname, ConstantSP handler, const ConstantSP& subname, const ConstantSP& subindex);
    ~SubConnection();

    string getAddress();

    long long getCreateTime() const;

    string getService();

    string getAppName();

    SessionSP getSession();

    void cancelThread();
};


#endif //BLOOMBERGPLUGIN_SESSION_H
