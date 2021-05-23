//============================================================================
// Name        : HDOJ_1555.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : How many days?
//============================================================================
#include <iostream>
using namespace std;
int main(){
    int M,k;
    while(cin>>M>>k){
        if(M == 0 && k == 0)
            break;
        int t,cnt = 0;
        while(M >= k){
            t = M / k;
            cnt += t * k;
            M = M % k + t;
        }
        cnt += M;
        cout<<cnt<<endl;
    }
}