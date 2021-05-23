#include<iostream>

using namespace std;

int main(){
    int n;
    double t;
    int neg,pos;
    while(cin>>n,n != 0){
        neg = pos = 0;
        for(int i = 0; i < n; i++){
            cin>>t;
            if(t > 0)
                pos++;
            else if(t < 0)
                neg++;
        }
        cout<<neg<<" "<<n - neg - pos<<" "<<pos<<endl;
    }
    return 0;
}