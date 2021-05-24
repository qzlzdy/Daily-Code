#include<iostream>
using namespace std;
int main(){
    int T,input;
    char c;
    cin>>T;
    while(T > 0)
    {
        cin>>input;
        c = (char)input;
        cout<<c;
        T--;
    }
}