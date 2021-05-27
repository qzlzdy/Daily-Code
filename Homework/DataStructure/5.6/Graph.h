#ifndef GRAPH_H_
#define GRAPH_H_
#include <vector>
#include "MFSet.h"
#include "Edge.h"
using namespace std;

class Graph {
public:
	Graph(int n,bool rangen);
	void Kruskal();		//最小生成树算法
private:
	int _size;
	MFSet mfset;
	vector<Edge> edges;
};

#endif /* GRAPH_H_ */
