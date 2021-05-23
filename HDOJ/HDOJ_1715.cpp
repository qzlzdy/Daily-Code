//============================================================================
// Name        : HDOJ_1035.cpp
// Author      : Qzlzdy
// Version     : C++
// Description :
//============================================================================
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class BigNum
{
public:
    BigNum(int num);
    BigNum(string num);
    int length();
    BigNum operator+(BigNum &num);
    char &operator[](int n);
    friend ostream &operator<<(ostream &out,const BigNum &num);
private:
    string _num;
};
BigNum::BigNum(int num)
{
    _num = to_string(num);
}
BigNum::BigNum(string num)
{
    _num = num;
}
int BigNum::length()
{
    return _num.length();
}
BigNum BigNum::operator +(BigNum &num)
{
    string sum;
    int i = length() - 1,j = num.length() - 1;
    int carry = 0,digit;
    while(i >= 0 && j >= 0)
    {
        digit = _num[i--] + num[j--] - 2 * '0' + carry;
        carry = digit / 10;
        digit %= 10;
        sum.insert(sum.begin(),'0' + digit);
    }
    while(i >= 0)
    {
        digit = _num[i--] - '0' + carry;
        carry = digit / 10;
        digit %= 10;
        sum.insert(sum.begin(),'0' + digit);
    }
    while(j >= 0)
    {
        digit = num[j--] - '0' + carry;
        carry = digit / 10;
        digit %= 10;
        sum.insert(sum.begin(),'0' + digit);
    }
    if(carry != 0)
        sum.insert(sum.begin(),'0' + carry);
    return BigNum(sum);
}
char &BigNum::operator [](int n)
{
    return _num[n];
}
ostream &operator<<(ostream &out,const BigNum &num)
{
    out<<num._num;
    return out;
}
int main()
{
    vector<BigNum> arr(2,BigNum(1));
    int N,i;
    cin>>N;
    while(N--)
    {
        cin>>i;
        for(int j = arr.size(); j < i; j++)
            arr.push_back(arr[j - 1] + arr[j - 2]);
        cout<<arr[i - 1]<<endl;
    }
}