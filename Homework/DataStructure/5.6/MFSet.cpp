#include "MFSet.h"

MFSet::MFSet(int n){
	for(int i = 0; i < n; i++)
		par.push_back(i);
	rank = vector<int>(n,0);
}

int MFSet::find(int x){
	//�ݹ�ʱ�ز���·�������ҵ���
	//����ʱ�����������¸���ÿ����㣬ʹ��ֱ��ָ���
	if(par[x] != x)
		par[x] = find(par[x]);
	return par[x];
}

void MFSet::merge(int i,int j){
	link(find(i),find(j));
}

void MFSet::link(int i,int j){
	//���Ƚ�С�ļ��ϲ���ϴ�ļ�����
	if(rank[i] > rank[j])
		par[j] = i;
	else{
		par[i] = j;
		if(rank[i] == rank[j])
			rank[j]++;
	}
}
