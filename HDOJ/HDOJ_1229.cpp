#include<iostream>
#include<cmath>

using namespace std;

int main(){
    int A,B,K; 
    while(cin>>A>>B,A != 0 || B != 0){
        cin>>K;
        int n = pow(10,K);
        if(A % n == B % n)
            cout<<-1<<endl;
        else
            cout<<A + B<<endl;
    } 
    re
