//============================================================================
// Name        : HDOJ_1042.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : N!
//============================================================================
#include <iostream>
#include <vector>
using namespace std;
class Bignum{
public:
    Bignum(int num);
    Bignum operator*(const Bignum& N);
    friend ostream& operator<<(ostream& out,const Bignum& N);
    int& operator[](int i);
    const int& operator[](int i)const;
    int size()const;
private:
    void pop_back();
    void resize(int count);
    vector<int> _num;
};
Bignum::Bignum(int num){
    while(num != 0){
        _num.push_back(num % 10);
        num /= 10;
    }
}
Bignum Bignum::operator *(const Bignum& N){
    Bignum R(0);
    R.resize(size() + N.size());
    for(int i = 0; i < size(); i++)
        for(int j = 0; j < N.size(); j++)
            R[i + j] += _num[i] * N[j];
    int digit,carry = 0;
    for(int i = 0; i < R.size(); i++){
        digit = R[i] + carry;
        R[i] = digit % 10;
        carry = digit / 10;
    }
    while(R[R.size() - 1] == 0)
        R.pop_back();
    return R;
}
ostream& operator<<(ostream& out,const Bignum& N){
    for(int i = N.size() - 1; i >= 0; i--)
        out<<N[i];
    return out;
}
int& Bignum::operator [](int i){
    return _num[i];
}
const int& Bignum::operator [](int i)const{
    return _num[i];
}
int Bignum::size()const{
    return _num.size();
}
void Bignum::pop_back(){
    _num.pop_back();
}
void Bignum::resize(int count){
    _num.resize(count,0);
}
Bignum bignumFact(Bignum& N,int n){
    Bignum R(1);
    for(int i = 2; i <= n; i++)
        R = R * Bignum(i);
    return R;
}
int main(){
    int n;
    while(cin>>n){
        Bignum N(n);
        cout<<bignumFact(N,n)<<endl;
    }
}
