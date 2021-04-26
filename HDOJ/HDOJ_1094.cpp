#include<iostream>
using namespace std;
int main(){
    int sum,M,t;
    while(cin>>M)
    {
        sum = 0;
        while(M>0)
        {
            cin>>t;
            sum+=t;
            M--;
        }
        cout<<sum<<endl;
    }
    return 0;
}
