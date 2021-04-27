//============================================================================
// Name        : HDOJ_1173.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : 采矿
//============================================================================
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main(){
    int n;
    while(cin>>n){
        if(n == 0)
            break;
        vector<double> x(n), y(n);
        for(int i = 0; i < n; i++)
            cin>>x[i]>>y[i];
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        cout<<fixed<<setprecision(2);
        cout<<x[n / 2]<<' '<<y[n / 2]<<endl;
    }
}
