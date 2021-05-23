#include<iostream>

using namespace std;

int main(){
    int n,sum,t;
    while(cin>>n){
        sum = 1;
        for(int i = 0; i < n; i++){
            cin>>t;
            if(t % 2 != 0)
                sum *= t;
        }
        cout<<sum<<endl;
    }
    return 0;
}