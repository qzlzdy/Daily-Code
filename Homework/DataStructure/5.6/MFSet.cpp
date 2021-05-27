#include "MFSet.h"

MFSet::MFSet(int n){
	for(int i = 0; i < n; i++)
		par.push_back(i);
	rank = vector<int>(n,0);
}

int MFSet::find(int x){
	//递归时沿查找路径向上找到根
	//回溯时沿搜索树向下更新每个结点，使其直接指向根
	if(par[x] != x)
		par[x] = find(par[x]);
	return par[x];
}

void MFSet::merge(int i,int j){
	link(find(i),find(j));
}

void MFSet::link(int i,int j){
	//将秩较小的集合并入较大的集合中
	if(rank[i] > rank[j])
		par[j] = i;
	else{
		par[i] = j;
		if(rank[i] == rank[j])
			rank[j]++;
	}
}
