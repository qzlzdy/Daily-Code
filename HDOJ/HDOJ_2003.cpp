#include<iostream>
#include<cmath> 
#include<ios>
#include<iomanip> 

using namespace std;

int main(){
    double N;
    while(cin>>N){
        cout<<fixed<<setprecision(2)<<abs(N)<<endl;
    }
}