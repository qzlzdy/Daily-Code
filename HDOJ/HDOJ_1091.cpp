#include<iostream>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    do{
        cout<<a+b<<endl;
        cin>>a>>b;
    }while(!(a==0&&b==0));
    return 0;
}
