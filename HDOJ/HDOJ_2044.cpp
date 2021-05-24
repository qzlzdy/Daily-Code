//============================================================================
// Name        : HDOJ_2044.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : 一只小蜜蜂...
//============================================================================
#include <iostream>
#include <vector>
using namespace std;
long long func(vector<long long>& memo,unsigned int i){
    if(i <= memo.size())
        return memo[i - 1];
    memo.push_back(func(memo,i - 2) + func(memo,i - 1));
    return memo[i - 1];
}
int main(){
    int N,a,b;
    vector<long long> memo{1,2};
    cin>>N;
    while(N--){
        cin>>a>>b;
        cout<<func(memo,b - a)<<endl;
    }
}