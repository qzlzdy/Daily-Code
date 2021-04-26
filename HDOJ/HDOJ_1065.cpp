//============================================================================
// Name        : HDOJ_1065.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : I Think I Need a Houseboat
//============================================================================
#include <iostream>
#include <cmath>
using namespace std;
#define PI 3.1415926
int main(){
    int N,Z;
    double x,y;
    cin>>N;
    for(int i = 1; i <= N; i++){
        cin>>x>>y;
        double r = sqrt(x*x + y*y);
        Z = ceil(PI * r*r / 100);
        cout<<"Property "<<i<<": This property will begin eroding in year "<<Z<<"."<<endl;
    }
    cout<<"END OF OUTPUT."<<endl;
}
