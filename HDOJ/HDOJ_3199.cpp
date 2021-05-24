//============================================================================
// Name        : HDOJ_3199.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : Hamming Problem
//============================================================================
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<long long> num;
vector<long long> prime(3);
vector<int> coe;
int advance(){
    long long mini = min(min(num[coe[0]] * prime[0],num[coe[1]] * prime[1]),num[coe[2]] * prime[2]);
    num.push_back(mini);
    for(int i = 0; i < 3; i++)
        if(num[coe[i]] * prime[i] == mini)
            coe[i]++;
    return mini;
}
int main(){
    int n;
    while(cin>>prime[0]>>prime[1]>>prime[2]>>n){
        num = vector<long long>{1};
        coe = vector<int>{0,0,0};
        for(int i = num.size(); i <= n; i++)
            advance();
        cout<<num[n]<<endl;
    }
}