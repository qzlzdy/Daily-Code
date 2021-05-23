#include<iostream>
#include<cmath>
#include<iomanip>

#define PI 3.1415927

using namespace std;

int main(){
    double R;
    while(cin>>R){
        cout<<fixed<<setprecision(3)<<(4.0/3)*PI*R*R*R<<endl;
    }
}