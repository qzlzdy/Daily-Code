//============================================================================
// Name        : HDOJ1038.cpp
// Author      : Qzlzdy
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;
float const p = 3.1415927;
int main(){
    float d,t;
    int r;
    int i = 1;
    while(cin>>d>>r>>t){
        if(r == 0)
            break;
        float dist = r * p * d / 12 / 5280;
        float time = dist / t * 3600;
        cout<<"Trip #"<<i<<": ";
        cout<<fixed<<setprecision(2)<<dist<<" ";
        cout<<fixed<<setprecision(2)<<time<<endl;
        i++;
    }
}
