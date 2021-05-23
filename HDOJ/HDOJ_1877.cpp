//============================================================================
// Name        : HDOJ1877.cpp
// Author      : Qzlzdy
// Version     :
// Copyright   : Your copyright notice
// Description : 
//============================================================================

#include <iostream>
#include <string>
using namespace std;
int main(){
    int m,A,B;
    __int64 sum;
    while(cin>>m,m != 0){
        cin>>A>>B;
        sum = A + B;
        string str;
        if(sum < 0){
            cout<<"-";
            sum = -sum;
        }
        int s;
        do{
            s = sum % m;
            str = (char)('0' + s) + str;
            sum /= m;
        }while(sum != 0);
        cout<<str<<endl;
    }
}