#include <iostream>
#include <iomanip>
#include <cmath>
#define PI 3.141592654
using namespace std;
int main(){
    int T;
    cin>>T;
    for(int i = 0; i < T; i++){
        double x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        double ang1 = atan2(y1,x1);
        double ang2 = atan2(y2,x2);
        double ang = abs(ang1-ang2)/PI*180;
        cout<<fixed<<setprecision(2)<<ang<<endl;
    } 
} 