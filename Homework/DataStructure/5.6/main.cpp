#include <iostream>
#include "Heap.h"
#include "Graph.h"
using namespace std;

int main(){
	int n;
	bool rangen;
	while(cin>>n){
		cin>>rangen;
		Graph graph(n,rangen);
		graph.Kruskal();
	}
}
