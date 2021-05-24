#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int a,b;
    while(cin>>a>>b,a != 0 || b != 0){
        int rs = b - a * 100 % b;
        if(rs == b)
            rs = 0;
        cout<<setw(2)<<setfill('0')<<rs;
        rs += b;
        while(rs < 100){
            cout<<" "<<setw(2)<<setfill('0')<<rs;
            rs += b;
        }
        cout<<endl;
    }
} 