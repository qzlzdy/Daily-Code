#ifndef POINT_H_
#define POINT_H_
#include <list>
using namespace std;

class Point {
public:
	Point(int pos_x = 0,int pos_y = 0);
	int x,y;	//����
	bool searched;		//������ǣ��������㷨ʹ��
	list<Point*> adj;	//�������ڽ���ַ
};

#endif /* POINT_H_ */
