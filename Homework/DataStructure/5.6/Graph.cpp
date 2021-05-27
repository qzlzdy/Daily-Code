#include "Graph.h"
#include <iostream>
#include <ctime>
#include <random>
#include "Heap.h"
using namespace std;

Graph::Graph(int n,bool rangen):mfset(n){
	_size = n;
	//随机生成边的权重
	if(rangen){
		//生成服从正态分布的随机数
		random_device rd{};
		mt19937_64 gen{rd()};
		gen.seed(time(nullptr));
		normal_distribution<> d{50,17};		// X ~ N(50,17^2)
		for(int i = 0; i < n; i++)
			for(int j = i + 1; j < n; j++){
				int w = d(gen);
				edges.push_back(Edge(i,j,w));
				cout<<i<<" "<<j<<" "<<w<<endl;
			}
	//或用户输入
	}else{
		int i,j,w,m;
		cin>>m;
		while(m--){
			cin>>i>>j>>w;
			edges.push_back(Edge(i,j,w));
		}
	}
	cout<<"================================"<<endl;
	//堆排序
	heapsort(edges);
}

void Graph::Kruskal(){
	for(auto &it : edges)
		if(mfset.find(it.i) != mfset.find(it.j)){
			mfset.merge(it.i,it.j);
			cout<<it.i<<" "<<it.j<<" "<<it.weight<<endl;
		}
}
