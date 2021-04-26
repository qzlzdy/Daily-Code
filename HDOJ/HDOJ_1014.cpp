//============================================================================
// Name        : HDOJ_1014.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : Uniform Generator
//============================================================================
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
int main(){
    int STEP, MOD;
    while(cin>>STEP>>MOD){
        cout<<setw(10)<<right<<STEP;
        cout<<setw(10)<<right<<MOD;
        vector<bool> flags(MOD, false);
        int cnt = MOD, i = 0;
        while(cnt > 0){
            if(!flags[i]){
                flags[i] = true;
                cnt--;
                i = (i + STEP) % MOD;
            }else
                break;
        }
        cout<<"    "<<left;
        if(cnt != 0)
            cout<<"Bad Choice"<<endl;
        else
            cout<<"Good Choice"<<endl;
        cout<<endl;
    }
}
