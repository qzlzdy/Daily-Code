#include<iostream>

using namespace std;

int main(){
    int m,n;
    int odd,nodd;
    while(cin>>m>>n){
        if(m > n){
            int t = m;
            m = n;
            n = t;
        }
        odd = nodd = 0;
        for(int i = m; i <= n; i++){
            if(i % 2 == 0)
                nodd += i * i;
            else
                odd += i * i * i;
        }
        cout<<nodd<<" "<<odd<<endl;
    }
    return 0;
}