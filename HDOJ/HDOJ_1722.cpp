#include<iostream>
using namespace std;
int gcd(int a,int b){
    if(b == 0)
        return a;
    else
        return gcd(b,a % b);
}
int main(){
    int a,b;
    while(cin>>a>>b){
        cout<<a + b - gcd(a,b)<<endl;
    }
    return 0;
}