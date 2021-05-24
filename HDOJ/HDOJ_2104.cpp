#include<iostream>
#include<cctype>
using namespace std;
int gcd(int a,int b){
    if(b == 0)
        return a;
    else
        return gcd(b,a%b);
}
int main(){
    int N,M;
    cin>>N>>M;
    while(N != -1 || M != -1)
    {
        if(gcd(N,M)==1)
            cout<<"YES"<<endl;
        else
            cout<<"POOR Haha"<<endl;
        cin>>N>>M;
    }
    return 0;
}