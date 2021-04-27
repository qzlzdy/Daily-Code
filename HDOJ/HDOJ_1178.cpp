//============================================================================
// Name        : HDOJ_1178.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : Heritage from father
//============================================================================
#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    double N;
    while(cin>>N){
        if(N == 0)
            break;
        double sum = N * (N + 1) * (N + 2) / 6.0;
        int ind = 0;
        while(sum >= 10){
            ind++;
            sum /= 10;
        }
        cout<<fixed<<setprecision(2);
        cout<<sum<<'E';
        cout<<setprecision(0);
        cout<<ind<<endl;
    }
}
