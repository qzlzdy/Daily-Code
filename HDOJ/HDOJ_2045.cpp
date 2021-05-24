//============================================================================
// Name        : HDOJ_2045.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : 不容易系列之(3)—— LELE的RPG难题
//============================================================================

#include <iostream>
#include <cmath>
using namespace std;
long long func(int n){
    if(n == 1)
        return 1;
    if(n == 2)
        return 2;
    return pow(2,n-1) - func(n-1);
}
int main(){
    int n;
    while(cin>>n){
        cout<<3 * func(n)<<endl;
    }
}