#include<iostream>
#include<cmath>
using namespace std;
int i;
bool isPrime(int n){
    if(n == 1)
        return false;
    int m = sqrt(n);
    for(int i = 2; i <= m; i++)
        if(n % i == 0)
            return false;
    return true;
}
void advan(){
    while(!isPrime(++i));
}
int main(){
    int n;
    cin>>n;
    while(n > 0)
    {
        int a,b;
        cin>>a>>b;
        i = 2;
        while(a / b % i == 0)
            advan();
        cout<<i*b<<endl;
        n--;
    } 
    return 0;
}
