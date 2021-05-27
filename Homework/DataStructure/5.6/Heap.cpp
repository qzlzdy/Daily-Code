#include "Heap.h"

void heapify(vector<Edge>& edges,int i){
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int min = i;
	if(l < edges.size() && edges[min].weight > edges[l].weight)
		min = l;
	if(r < edges.size() && edges[min].weight> edges[r].weight)
		min = r;
	if(min != i){
		Edge edge = edges[i];
		edges[i] = edges[min];
		edges[min] = edge;
		heapify(edges,min);
	}
}

void buildHeap(vector<Edge>& edges){
	for(int i = (edges.size() - 1) / 2; i >= 0; i--)
		heapify(edges,i);
}

void heapsort(vector<Edge>& edges){
	buildHeap(edges);
	vector<Edge> sorted;
	while(!edges.empty()){
		sorted.push_back(edges[0]);
		edges[0] = edges.back();
		edges.pop_back();
		heapify(edges,0);
	}
	edges = sorted;
}
