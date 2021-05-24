//============================================================================
// Name        : HDOJ_2041.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : 超级楼梯
//============================================================================
#include <iostream>
#include <stack>
using namespace std;
long long combinator(int m,int n){
    long long rs = 1;
    stack<int> S;
    for(int i = n; i >= 2; i--)
        S.push(i);
    for(int i = m; i > m - n; i--){
        rs *= i;
        while(!S.empty() && rs % S.top() == 0){
            rs /= S.top();
            S.pop();
        }
    }
    return rs;
}
int main(){
    int N,M;
    cin>>N;
    while(N--){
        cin>>M;
        M--;
        long long count = 0;
        for(int i = 0; 2 * i <= M ; i++)
            count += combinator(M - i,i);
        cout<<count<<endl;
    }
}