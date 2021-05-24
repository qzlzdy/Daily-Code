//============================================================================
// Name        : HDOJ2035.cpp
// Author      : Qzlzdy
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================

#include <iostream>
#include <queue>
using namespace std;
deque<bool> binary(int n){
    deque<bool> bin;
    while(n > 0){
        bin.push_front(n % 2);
        n /= 2;
    }
    return bin;
}
int powmod(int a,int b,int n){
    int d = 1;
    deque<bool> bin = binary(b);
    while(!bin.empty()){
        d = (d * d) % n;
        if(bin.front())
            d = (d * a) % n;
        bin.pop_front();
    }
    return d;
}
int main(){
    int A,B;
    while(cin>>A>>B){
        if(A == 0 && B == 0)
            break;
        cout<<powmod(A,B,1000)<<endl;
    }
}