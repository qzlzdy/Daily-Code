//============================================================================
// Name        : HDOJ_2899.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : Strange fuction
//============================================================================
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
double f(double x,double y){
    return 6*pow(x,7)+8*pow(x,6)+7*pow(x,3)+5*x*x - y*x;
}
double df(double x){
    return 42*pow(x,6)+48*pow(x,5)+21*x*x+10*x;
}
int main(){
    int T;
    double Y;
    cin>>T;
    while(T--){
        double i = 0,j = 100;
        cin>>Y;
        if(df(j) < Y || df(i) > Y){
            cout<<"No solution!"<<endl;
            continue;
        }
        while(abs(i-j) > 1e-8){
            double mid = (i + j) / 2;
            if(df(mid) < Y)
                i = mid;
            else
                j = mid;
        }
        cout<<fixed<<setprecision(4)<<f(i,Y)<<endl;
    }
}