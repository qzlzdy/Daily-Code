#include<iostream>
using namespace std;
int main(){
    int sum,t,input;
    cin>>t;
    while(t != 0){
        sum = 0;
        while(t>0)
        {
            cin>>input;
            sum+=input;
            t--;
        }
        cout<<sum<<endl;
        cin>>t;
    }
}
