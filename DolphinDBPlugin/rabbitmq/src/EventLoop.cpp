#include "EventLoop.h"

#include "Exceptions.h"

#include <iostream>

using namespace std;

EventLoop::EventLoop(AMQP::Address addr){
    evbase = event_base_new();
    handler = new AMQP::LibEventHandler(evbase);
    tcpConn = new AMQP::TcpConnection(handler, addr);
}

EventLoop::~EventLoop(){
    tcpConn->close();
    delete tcpConn;
    delete handler;
    event_base_free(evbase);
}

AMQP::TcpConnection *EventLoop::connection() const{
    return tcpConn;
}

void EventLoop::run(){
    int result = event_base_dispatch(evbase);
    if(result == -1){
        throw RuntimeException("error occurred when dispatch event loop");
    }
    else if(result == 1){
        cerr << "event loop exited because no events were pending or active" << endl;
    }
}