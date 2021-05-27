#ifndef MAZE_H_
#define MAZE_H_
#include <vector>
#include "Point.h"
#include "Stack.h"
using namespace std;

class Maze {
public:
	Maze(int m,int n);	//O(m*n)
	~Maze();	//O(m*n)
	void setStart(int x,int y);		//设置起点	O(1)
	void setEnd(int x,int y);		//设置终点	O(1)
	void run();		//求解迷宫	O(m*n)
	void singleSol();	//获得单个解，已三元组形式输出		O(m*n)
private:
	void DFS(Stack<Point*>& sol,Point* p);		//深度优先搜索，供run方法调用		O(m*n)
	bool passable(int x,int y);		//判断位置是否为通路	O(1)
	vector<vector<Point*> > _points;
	vector<vector<char> > _map;
	int _count;		//记录解的个数
	int _rows,_cols;	//保持迷宫的大小
	int _start_x,_start_y;		//记录起点位置
	int _end_x,_end_y;		//记录终点位置
};

#endif /* MAZE_H_ */
