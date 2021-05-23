//============================================================================
// Name        : HDOJ_1297.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : Children’s Queue
//============================================================================

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
class BigNum{
public:
    BigNum(int n = 0);
    BigNum operator+(BigNum& addend);
    friend ostream& operator<<(ostream& out,BigNum& bn);
private:
    string _num;
};
BigNum::BigNum(int num){
    stringstream ss;
    ss<<num;
    _num = ss.str();
}
BigNum BigNum::operator+(BigNum& addend){
    BigNum rs;
    rs._num = "";
    string::reverse_iterator numa = _num.rbegin();
    string::reverse_iterator numb = addend._num.rbegin();
    int d,c = 0;
    while(numa != _num.rend() && numb != addend._num.rend()){
        d = *numa + *numb + c - 2 * '0';
        rs._num = (char)('0' + d % 10) + rs._num;
        c = d / 10;
        numa++;
        numb++;
    }
    while(numa != _num.rend()){
        d = *numa - '0' + c;
        rs._num = (char)('0' + d % 10) + rs._num;
        c = d / 10;
        numa++;
    }
    while(numb != addend._num.rend()){
        d = *numb - '0' + c;
        rs._num = (char)('0' + d % 10) + rs._num;
        c = d / 10;
        numb++;
    }
    if(c != 0)
        rs._num = (char)('0' + c) + rs._num;
    return rs;
}
ostream& operator <<(ostream& out,BigNum& bn){
    out<<bn._num;
    return out;
}
BigNum& func(vector<BigNum>& demo,int n){
    if(demo.size() >= n)
        return demo[n - 1];
    demo.push_back(func(demo,n - 4) + func(demo,n - 2) + func(demo,n - 1));
    return demo[n - 1];
}
int main(){
    int n;
    vector<BigNum> demo{BigNum(1),BigNum(2),BigNum(4),BigNum(7)};
    while(cin>>n){
        cout<<func(demo,n)<<endl;
    }
}