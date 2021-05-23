//============================================================================
// Name        : HDOJ_1905.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : Pseudoprime numbers
//============================================================================
#include <iostream>
#include <iomanip>
#include <cmath>
#include <stack>
using namespace std;
long long powmod(int a,int b,int c){
    stack<int> S;
    while(b){
        S.push(b % 2);
        b /= 2;
    }
    long long sum = 1;
    while(!S.empty()){
        sum *= sum;
        sum %= c;
        if(S.top()){
            sum *= a;
            sum %= c;
        }
        S.pop();
    }
    return sum;
}
bool isPrime(int a){
    if(a < 2)
        return false;
    int bound = floor(sqrt(a));
    int i = 2;
    for( ; i <= bound; i++)
        if(a % i == 0)
            break;
    return i > bound;
}
int main(){
    int p,a;
    while(cin>>p>>a){
        if(p == 0 && a == 0)
            break;
        if(powmod(a,p,p) == a && !isPrime(p))
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
}