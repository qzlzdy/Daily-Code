#include <iostream>
using namespace std;
int main(){
    int n;
    while(cin>>n,n != -1){
        if(n < 2){
            cout<<n<<endl;
            continue;
        }
        __int64 a,b,c;
        a = 0;
        b = 1;
        for(int i = 1; i < n; i++){
            c = a;
            a = b;
            b += c;
        }
        cout<<b<<endl;
    }
} 