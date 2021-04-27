//============================================================================
// Name        : HDOJ_1194.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : Beat the Spread!
//============================================================================
#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    while(n-- > 0){
        int s, d;
        cin>>s>>d;
        int a = s + d;
        int b = s - d;
        if(b < 0 || a % 2 != 0 || b % 2 != 0)
            cout<<"impossible"<<endl;
        else
            cout<<a / 2<<' '<<b / 2<<endl;
    }
}
