#include <iostream>
#include "Maze.h"
using namespace std;

int main(){
	int m,n,x,y;
	cout<<"Input maze."<<endl;
	while(cin>>m>>n){
		//构造迷宫
		Maze maze(m,n);
		//设置起点
		cout<<"Input the start point."<<endl;
		cin>>x>>y;
		maze.setStart(x,y);
		//设置终点
		cout<<"Input the end point."<<endl;
		cin>>x>>y;
		maze.setEnd(x,y);
		//求解并输出所有可能解
		maze.run();

		maze.singleSol();
		cout<<"Input maze."<<endl;
	}
}
