#include<iostream>

using namespace std;

int main(){
    char c; 
    int n;
    cin>>c;
    while(c != '@'){
        cin>>n;
        for(int i = 0; i < n - 1; i++)
            cout<<" ";
        cout<<c<<endl;
        for(int i = 1; i < n - 1; i++){
            for(int j = 0; j < n - 1 - i; j++)
                cout<<" ";
            cout<<c;
            for(int j = 0; j < 2 * i - 1; j++)
                cout<<" ";
            cout<<c<<endl;
        }
        if(n != 1){
            for(int i = 0; i < 2 * n - 1; i++)
                cout<<c;
            cout<<endl;
        }
        cin>>c;
        if(c != '@')
            cout<<endl;
    }
    return 0;
}