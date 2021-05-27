#ifndef MFSET_H_
#define MFSET_H_
#include <vector>
using namespace std;

class MFSet {
public:
	MFSet(int n);
	int find(int x);	//����Ԫ��x�ļ���
	void merge(int i,int j);	//�ϲ�Ԫ��i,j���ڼ���
private:
	void link(int i,int j);
	vector<int> par;	//��¼��Ԫ���������ĸ�
	vector<int> rank;	//��¼�������ܵ����߶�
};

#endif /* MFSET_H_ */
