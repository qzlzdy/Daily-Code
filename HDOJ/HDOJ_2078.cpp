#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T > 0){
        int n,m,t,min = 100;
        cin>>n>>m;
        while(n > 0){
            cin>>t;
            if(t < min)
                min = t;
            n--;
        }
        cout<<(100-min)*(100-min)<<endl;
        T--;
    }
} 