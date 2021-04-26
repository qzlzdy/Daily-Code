//============================================================================
// Name        : HDOJ_1031.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : Design T-Shirt
//============================================================================
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <functional>
using namespace std;
class Item{
public:
    Item(int n);
    int id;
    double score;
};
Item::Item(int n){
    id = n;
    score = 0;
}
bool cmp(Item& A,Item& B){
    if(A.score == B.score)
        return A.id < B.id;
    return A.score > B.score;
}
int main(){
    int N,M,K;
    while(cin>>N>>M>>K){
        vector<Item> items;
        for(int i = 0; i < M; i++)
            items.push_back(Item(i + 1));
        double t;
        for(int i = 0; i < N * M; i++){
            cin>>t;
            items[i % M].score += t;
        }
        sort(items.begin(),items.end(),cmp);
        set<int,greater<int> > sel;
        for(int i = 0; i < K; i++)
            sel.insert(items[i].id);
        int cnt = 0;
        for(auto &it : sel)
            cout<<it<<" \n"[(++cnt) == K];
    }
}
