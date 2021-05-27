#include "Maze.h"
#include "Stack.h"
#include "Point.h"
#include "Constants.h"
#include "Solution.h"
#include <iostream>
using namespace std;

Maze::Maze(int m,int n){
	int r;
	for(int i = 0; i < m; i++){
		vector<char> row;
		vector<Point*> vex;
		for(int j = 0; j < n; j++){
			cin>>r;
			row.push_back(r ? '#' : ' ');
			//若为通路则构造坐标类
			if(!r){
				vex.push_back(new Point(i,j));
				//连接相邻通路
				if(i > 0 && _map[i - 1][j] == ' '){
					vex[j]->adj.push_back(_points[i - 1][j]);
					_points[i - 1][j]->adj.push_back(vex[j]);
				}
				if(j > 0 && row[j - 1] == ' '){
					vex[j]->adj.push_back(vex[j - 1]);
					vex[j - 1]->adj.push_back(vex[j]);
				}
			}else{
				vex.push_back(nullptr);
			}
		}
		_map.push_back(row);
		_points.push_back(vex);
	}
	_rows = m;
	_cols = n;
	_count = 0;
	setStart(1,1);
	setEnd(m,n);
}

Maze::~Maze(){
	for(int i = 0; i < _rows; i++)
		for(int j = 0; j < _cols; j++)
			if(_map[i][j] == ' ')
				delete _points[i][j];
}

void Maze::setStart(int x,int y){
	_start_x = x - 1;
	_start_y = y - 1;
}

void Maze::setEnd(int x,int y){
	_end_x = x - 1;
	_end_y = y - 1;
}

void Maze::run(){
	Stack<Point*> sol;	//存放解的栈
	for(int i = 0; i < _rows; i++)
		for(int j = 0; j < _cols; j++)
			if(_map[i][j] == ' ')
				_points[i][j]->searched = false;
	DFS(sol,_points[_start_x][_start_y]);	//深度优先搜索
	//无解情况
	if(!_count)
		cout<<"No way."<<endl;
}

void Maze::singleSol(){
	Stack<Solution> sol;
	for(int i = 0; i < _rows; i++)
		for(int j = 0; j < _cols; j++)
			if(_map[i][j] == ' ')
				_points[i][j]->searched = false;
	bool flag = false;
	int x = _start_y,y = _start_y;
	do{
		//当前位置可通过，并且未搜索过
		if(passable(x,y) && !_points[x][y]->searched){
			_points[x][y]->searched = true;
			if(x == _end_x && y == _end_y)
				flag = true;
			else{
				//每次先向东走
				sol.push(Solution(x,y,EAST));
				y++;
			}
		}else
			//当前位置不可通过，或已被搜索过
			if(!sol.empty()){
				Solution e = sol.top();
				sol.pop();
				//若上一个点已被搜索完，继续回退
				while(e.comp == NORTH && !sol.empty()){
					e = sol.top();
					sol.pop();
				}
				//若未被搜索完
				if(e.comp < NORTH){
					e.comp++;
					x = e.x;
					y = e.y;
					sol.push(Solution(x,y,e.comp));
					switch(e.comp){
					case WEST:
						y--;
						break;
					case SOUTH:
						x++;
						break;
					case NORTH:
						x--;
						break;
					}
				}
			}
	}while(!sol.empty() && !flag);
	if(!flag)
		cout<<"No way."<<endl;
	else{
		Node<Solution>* p = sol._top->next;
			//自底向上输出
			string str = "";
			for(int i = 0; i < sol._size; i++){
				str = "(" + to_string(p->data.x + 1) + ","
						+ to_string(p->data.y + 1) + ","
						+ to_string(p->data.comp) + ") "
						+ str;
				p = p->next;
			}
			cout<<str;
			cout<<endl;
	}
}

void Maze::DFS(Stack<Point*>& sol,Point* p){
	sol.push(p);
	//若到达终点，则sol为一个解，输出该解
	if(p->x == _end_x && p->y == _end_y){
		vector<vector<char> > maze = _map;
		Node<Point*>* p = sol._top->next;
		//将选择路线字符改为'*'
		for(int i = 0; i < sol._size; i++){
			maze[p->data->x][p->data->y] = '*';
			p = p->next;
		}
		maze[_start_x][_start_y] = '@';
		maze[_end_x][_end_y] = '%';
		//输出解
		cout<<"solution "<<(++_count)<<":"<<endl;
		for(int i = 0; i < _rows; i++){
			for(int j = 0; j < _cols; j++)
				cout<<maze[i][j]<<" ";
			cout<<endl;
		}
		sol.pop();
		return;
	}
	//若未到终点，继续调用深度优先搜索
	p->searched = true;
	list<Point*>::iterator it = p->adj.begin();
	while(it != p->adj.end()){
		if(!(*it)->searched){
			DFS(sol,*it);
		}
		it++;
	}
	//经过该点的路线已全部搜索，回退至上一点
	sol.pop();
	p->searched = false;
}

bool Maze::passable(int x,int y){
	bool flag = true;
	if(x < 0 || x >= _rows)
		flag = false;
	if(y <  0 || y >= _cols)
		flag = false;
	if(flag && _map[x][y] == '#')
		flag = false;
	return flag;
}
