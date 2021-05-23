#include<iostream>
#include<ios>
#include<iomanip>

using namespace std;

int main(){
    int m,n;
    double sum,an;
    cin>>m;
    while(m > 0){
        cin>>n;
        sum = 0;
        an = 1;
        for(int i = 0; i < n; i++){
            sum += an;
            an = (-1) * an * (i + 1) / (i + 2);
        }
        cout<<fixed<<setprecision(2)<<sum<<endl;
        m--;
    }
    return 0;
}