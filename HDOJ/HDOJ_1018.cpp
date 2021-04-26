#include<iostream>
#include<cmath>
#include<ios> 
#include<iomanip>
using namespace std;
int main(){
    int T,N;
    cin>>T;
    while(T > 0){
        cin>>N;
        double d = 0;
        for(int i = 2; i <= N;i++)
            d += log10(i);
        cout<<fixed<<setprecision(0)<<floor(d)+1<<endl; 
        T--;
    }
    return 0;
}
