//============================================================================
// Name        : HDOJ1037.cpp
// Author      : Qzlzdy
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================

#include <iostream>
using namespace std;
int main(){
    int high[3];
    while(cin>>high[0]){
        cin>>high[1]>>high[2];
        int i;
        for(i = 0; i < 3; i++){
            if(high[i] < 168){
                cout<<"CRASH "<<high[i]<<endl;
                break;
            }
        }
        if(i == 3)
            cout<<"NO CRASH"<<endl;
    }
}
