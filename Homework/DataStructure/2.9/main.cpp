#include <iostream>
#include "Maze.h"
using namespace std;

int main(){
	int m,n,x,y;
	cout<<"Input maze."<<endl;
	while(cin>>m>>n){
		//�����Թ�
		Maze maze(m,n);
		//�������
		cout<<"Input the start point."<<endl;
		cin>>x>>y;
		maze.setStart(x,y);
		//�����յ�
		cout<<"Input the end point."<<endl;
		cin>>x>>y;
		maze.setEnd(x,y);
		//��Ⲣ������п��ܽ�
		maze.run();

		maze.singleSol();
		cout<<"Input maze."<<endl;
	}
}
