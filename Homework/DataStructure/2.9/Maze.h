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
	void setStart(int x,int y);		//�������	O(1)
	void setEnd(int x,int y);		//�����յ�	O(1)
	void run();		//����Թ�	O(m*n)
	void singleSol();	//��õ����⣬����Ԫ����ʽ���		O(m*n)
private:
	void DFS(Stack<Point*>& sol,Point* p);		//���������������run��������		O(m*n)
	bool passable(int x,int y);		//�ж�λ���Ƿ�Ϊͨ·	O(1)
	vector<vector<Point*> > _points;
	vector<vector<char> > _map;
	int _count;		//��¼��ĸ���
	int _rows,_cols;	//�����Թ��Ĵ�С
	int _start_x,_start_y;		//��¼���λ��
	int _end_x,_end_y;		//��¼�յ�λ��
};

#endif /* MAZE_H_ */
