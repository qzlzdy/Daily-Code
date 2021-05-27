#ifndef HEAP_H_
#define HEAP_H_
#include <vector>
#include "Edge.h"
using namespace std;

void heapify(vector<Edge>& edges,int i);	//ά����iΪ�Ѷ��Ķѵ�����
void buildHeap(vector<Edge>& edges);	//����
void heapsort(vector<Edge>& edges);		//������

#endif /* HEAP_H_ */
