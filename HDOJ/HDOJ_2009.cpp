#include<iostream>
#include<cmath>
#include<ios>
#include<iomanip>

using namespace std;

int main(){
    double n,sum;
    int m;
    while(cin>>n>>m){
        sum = 0;
        for(int i = 0; i < m; i++){
            sum += n;
            n = sqrt(n);
        }
        cout<<fixed<<setprecision(2)<<sum<<endl;
    }
    return 0;
}