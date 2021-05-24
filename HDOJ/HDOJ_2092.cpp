#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int n,m;
    while(cin>>n>>m,n != 0 || m != 0){
        double delta = sqrt(n * n -  4 * m);
        if(delta < 0 || delta != (int)delta){
            cout<<"No"<<endl;
            continue;
        }
        if((n + (int)delta) % 2 != 0){
            cout<<"No"<<endl;
            continue;
        }
        cout<<"Yes"<<endl;
    }
} 