//============================================================================
// Name        : HDOJ_1165.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : Eddy's research II
//============================================================================
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
    int m, n;
    while(cin>>m>>n){
        switch(m){
        case 0:
            cout<<n + 1<<endl;
            break;
        case 1:
            cout<<n + 2<<endl;
            break;
        case 2:
            cout<<n + n + 3<<endl;
            break;
        case 3:
            cout<<fixed<<setprecision(0)<<exp2(n + 3) - 3<<endl;
        }
    }
}
