#ifndef BLOOMBERGPLUGIN_PLUGIN_BLOOMBERG_H
#define BLOOMBERGPLUGIN_PLUGIN_BLOOMBERG_H

#include "CoreConcept.h"
#include "Exceptions.h"
#include "Util.h"
#include "Types.h"
#include "Concurrent.h"
#include "ScalarImp.h"
#include "Session.h"
#include <blpapi_session.h>
#include <blpapi_correlationid.h>
#include <blpapi_event.h>
#include <blpapi_message.h>
#include <blpapi_request.h>
#include <blpapi_subscriptionlist.h>

#include <iostream>
#include <string>
#include <utility>

using namespace std;
using namespace BloombergLP;
using namespace blpapi;

DictionarySP status_dict = Util::createDictionary(DT_STRING,nullptr,DT_ANY,nullptr);

extern "C" ConstantSP test(Heap *heap, vector<ConstantSP> args);

extern "C" ConstantSP bloomSubscribe(Heap *heap, vector<ConstantSP> args);

extern "C" ConstantSP bloomUnsubscribe(Heap *heap, vector<ConstantSP> args);

extern "C" ConstantSP bloomGetSubScribeStatus(Heap *heap, vector<ConstantSP> args);

static bool is_ipv4_str(const char* ipv4);

template<typename T>
static void blpapiOnClose(Heap *heap, vector<ConstantSP> &args);

#endif //BLOOMBERGPLUGIN_PLUGIN_BLOOMBERG_H