#ifndef __EVENTLOOP_H
#define __EVENTLOOP_H

#include "amqpcpp.h"
#include "amqpcpp/libevent.h"
#include "Concurrent.h"
#include "event2/event.h"

class EventLoop : public Runnable{
public:
    EventLoop(AMQP::Address addr);
    ~EventLoop();
    AMQP::TcpConnection *connection() const;
private:
    void run();
    AMQP::TcpConnection *tcpConn;
    event_base *evbase;
    AMQP::LibEventHandler *handler;
};

#endif