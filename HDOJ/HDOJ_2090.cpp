//============================================================================
// Name        : HDOJ_2090.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : 算菜价
//============================================================================
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main(){
    string kind;
    double amount,price,sum = 0;
    while(cin>>kind>>amount>>price){
        sum += amount * price;
    }
    cout<<fixed<<setprecision(1);
    cout<<sum<<endl;
}