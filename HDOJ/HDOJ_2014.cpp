#include<iostream>
#include<ios>
#include<iomanip>

using namespace std;

int main(){
    int n,max,min,t;
    double sc; 
    while(cin>>n){
        sc = max = 0;
        min = 100;
        for(int i = 0; i < n; i++){
            cin>>t;
            if(t > max)
                max = t;
            if(t < min)
                min = t;
            sc += t;
        }
        sc -= max + min;
        cout<<fixed<<setprecision(2)<<sc / (n - 2)<<endl;
    }
    return 0;
}