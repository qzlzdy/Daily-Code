//============================================================================
// Name        : HDOJ_2199.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : Can you solve this equation?
//============================================================================
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
double f(double x){
    return 8*x*x*x*x+7*x*x*x+2*x*x+3*x+6;
}
int main(){
    int T;
    double Y;
    cin>>T;
    while(T--){
        double i = 0,j = 100;
        cin>>Y;
        if(f(j) < Y || f(i) > Y){
            cout<<"No solution!"<<endl;
            continue;
        }
        while(abs(i-j) > 1e-8){
            double mid = (i + j) / 2;
            if(f(mid) < Y)
                i = mid;
            else
                j = mid;
        }
        i = floor(i*1e4+0.5)/1e4;
        cout<<fixed<<setprecision(4)<<i<<endl;
    }
}