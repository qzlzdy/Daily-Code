#ifndef MFSET_H_
#define MFSET_H_
#include <vector>
using namespace std;

class MFSet {
public:
	MFSet(int n);
	int find(int x);	//查找元素x的集合
	void merge(int i,int j);	//合并元素i,j所在集合
private:
	void link(int i,int j);
	vector<int> par;	//记录个元素所在树的根
	vector<int> rank;	//记录该树可能的最大高度
};

#endif /* MFSET_H_ */
