#include<iostream>
using namespace std;
int main(){
    int sum,N,input,M;
    cin>>N;
    while(N>0){
        sum = 0;
        cin>>M;
        while(M>0)
        {
            cin>>input;
            sum+=input;
            M--;
        }
        cout<<sum<<endl;
        N--;
        if(N!=0)
            cout<<endl;
    }
}
