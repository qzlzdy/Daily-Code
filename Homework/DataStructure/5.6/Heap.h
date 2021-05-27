#ifndef HEAP_H_
#define HEAP_H_
#include <vector>
#include "Edge.h"
using namespace std;

void heapify(vector<Edge>& edges,int i);	//维护以i为堆顶的堆的性质
void buildHeap(vector<Edge>& edges);	//建堆
void heapsort(vector<Edge>& edges);		//堆排序

#endif /* HEAP_H_ */
