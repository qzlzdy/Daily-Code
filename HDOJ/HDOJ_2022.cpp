#include<iostream>
#include<cmath>

using namespace std;

int main(){
    int m,n,sc,t,x,y;
    while(cin>>m>>n){
        int i,j;
        sc = 0;
        x = y = 1;
        for(i = 0; i < m; i++)
            for(j = 0; j < n; j++)
                if(cin>>t,abs(t) > abs(sc)){
                    sc = t;
                    x = i + 1;
                    y = j + 1;
                }
        cout<<x<<" "<<y<<" "<<sc<<endl;
    }
    return 0;
}