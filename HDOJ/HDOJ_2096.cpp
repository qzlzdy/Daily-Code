#include<iostream>

using namespace std;

int main(){
    int A,B,T; 
    cin>>T;
    while(T > 0){
        cin>>A>>B;
        A %= 100;
        B %= 100;
        cout<<(A + B) % 100<<endl; 
        T--;
    } 
    return 0;
} 
