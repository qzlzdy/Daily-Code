#include<iostream>

using namespace std;

int main(){
    int n,sum;
    while(cin>>n){
        sum = 1;
        for(int i = 1; i < n; i++)
            sum = (sum + 1) * 2;
        cout<<sum<<endl;
    }
    return 0;
}