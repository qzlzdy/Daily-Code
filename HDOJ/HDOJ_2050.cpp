//============================================================================
// Name        : HDOJ_2050.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : 折线分割平面
//============================================================================
#include <iostream>
#include <vector>
using namespace std;
int func(vector<int>& memo,unsigned int i){
    if(i <= memo.size())
        return memo[i - 1];
    memo.push_back(func(memo,i - 1) + 4 * i - 3);
    return memo[i - 1];
}
int main(){
    int C,n;
    vector<int> memo{2};
    cin>>C;
    while(C--){
        cin>>n;
        cout<<func(memo,n)<<endl;
    }
}