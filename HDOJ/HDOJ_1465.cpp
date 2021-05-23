//============================================================================
// Name        : HDOJ_1465.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : 不容易系列之一
//============================================================================

#include <iostream>
#include <cmath>
using namespace std;
long long func(int n){
    if(n == 2)
        return 1;
    if(n == 3)
        return 2;
    return (n - 1 ) * (func(n - 1) + func(n - 2));
}
int main(){
    int n;
    while(cin>>n){
        cout<<func(n)<<endl;
    }
}