//============================================================================
// Name        : HDOJ_2501.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : Tiling_easy version
//============================================================================
#include <iostream>
#include <vector>
using namespace std;
int func(vector<int>& memo,unsigned int i){
    if(i <= memo.size())
        return memo[i - 1];
    memo.push_back(2 * func(memo,i - 2) + func(memo,i - 1));
    return memo[i - 1];
}
int main(){
    int T,N;
    vector<int> memo{1,3};
    cin>>T;
    while(T--){
        cin>>N;
        cout<<func(memo,N)<<endl;
    }
}