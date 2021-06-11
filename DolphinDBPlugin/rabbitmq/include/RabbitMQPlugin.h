#ifndef __RABBITMQPLUGIN_H
#define __RABBITMQPLUGIN_H

#include "CoreConcept.h"

#include <vector>

extern "C" ConstantSP connection(Heap *heap, std::vector<ConstantSP> &arguments);
extern "C" ConstantSP connectionAMQP(Heap *heap, std::vector<ConstantSP> &arguments);
extern "C" ConstantSP channel(Heap *heap, std::vector<ConstantSP> &arguments);
extern "C" ConstantSP declareQueue(Heap *heap, std::vector<ConstantSP> &arguments);
extern "C" ConstantSP declareExchange(Heap *heap, std::vector<ConstantSP> &arguments);
extern "C" ConstantSP publish(Heap *heap, std::vector<ConstantSP> &arguments);
// extern "C" ConstantSP consume(Heap *heap, std::vector<ConstantSP> &arguments);

#endif