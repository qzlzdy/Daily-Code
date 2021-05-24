#include<iostream>
#include<string>

using namespace std;

string chars = "0123456789ABCDEF";

int main(){
    int N,R;
    while(cin>>N>>R){
        string str;
        if(N < 0){
            cout<<"-";
            N = -N;
        }
        int s;
        do{
            s = N % R;
            str = chars[s] + str;
            N /= R;
        }while(N != 0);
        cout<<str<<endl;
    }
    return 0;
}