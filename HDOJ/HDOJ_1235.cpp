#include<iostream>

using namespace std;

int main(){
    int n,t;
    int score[101];
    while(cin>>n,n != 0){
        for(int i = 0; i < 101; i++)
            score[i] = 0;
        for(int i = 0; i < n; i++){
            cin>>t;
            score[t]++;
        }
        cin>>t;
        cout<<score[t]<<endl;
    } 
    return 0;
}