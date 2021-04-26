//============================================================================
// Name        : HDOJ_1128.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : Self Numbers
//============================================================================
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
int d(int n){
    int sum = n;
    while(n != 0){
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
int main(){
    vector<bool> num(1e6 + 1,true);
    for(int i = 1; i <= 1e6; i++){
        if(num[i])
            //cout<<i<<endl;
            printf("%d\n",i);
        num[d(i)] = false;
    }
}
