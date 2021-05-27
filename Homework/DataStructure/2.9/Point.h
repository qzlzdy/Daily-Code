#ifndef POINT_H_
#define POINT_H_
#include <list>
using namespace std;

class Point {
public:
	Point(int pos_x = 0,int pos_y = 0);
	int x,y;	//坐标
	bool searched;		//搜索标记，供搜索算法使用
	list<Point*> adj;	//保持相邻结点地址
};

#endif /* POINT_H_ */
