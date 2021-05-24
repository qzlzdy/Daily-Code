#include<iostream>

using namespace std;

int main(){
    int N;
    cin>>N; 
    while(N > 0){
        string str;
        cin>>str;
        cout<<6<<str.substr(str.size() - 5)<<endl;
        N--;
    }
    return 0;
}