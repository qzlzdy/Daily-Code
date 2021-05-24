//============================================================================
// Name        : HDOJ_2190.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : 悼念512汶川大地震遇难同胞——重建希望小学
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
    int C,n;
    vector<int> memo{1,3};
    cin>>C;
    while(C--){
        cin>>n;
        cout<<func(memo,n)<<endl;
    }
}