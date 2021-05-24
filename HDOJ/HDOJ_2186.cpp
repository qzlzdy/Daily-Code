#include<iostream>

using namespace std;

int main()
{
    int C,n;
    cin>>C;
    while(C > 0){
        cin>>n;
        int a = n / 2;
        n -= a;
        int b = n * 2 / 3;
        n -= b;
        int sum = a / 10 + b / 10 + n / 10;
        if(a % 10 != 0)
            sum++;
        if(b % 10 != 0)
            sum++;
        if(n % 10 != 0)
            sum++;
        cout<<sum<<endl; 
        C--;
    } 
    return 0; 
}