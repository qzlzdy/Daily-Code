#include<iostream>

using namespace std;

int main()
{
    int C,n,m;
    cin>>C;
    while(C > 0){
        cin>>n>>m;
        if(n % (m + 1) == 0)
            cout<<"Rabbit"<<endl;
        else
            cout<<"Grass"<<endl;
        C--;
    } 
    return 0; 
}