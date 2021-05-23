#include<iostream>
#include<queue>

using namespace std;

int main(){
    int n,m,i,a,sum;
    while(cin>>m>>n){
        i = 1;
        a = 2;
        sum = 0;
        queue<int> Q;
        while(m >= n){
            while(i <= n){
                sum += a;
                a += 2;
                i++;
            }
            Q.push(sum / n);
            sum = 0;
            m -= n;
            i = 1;
        }
        while(i <= m){
            sum += a;
            a += 2;
            i++;
        }
        if(m != 0)
            Q.push(sum / m);
        cout<<Q.front();
        Q.pop();
        while(!Q.empty()){
            cout<<" "<<Q.front();
            Q.pop();
        }
        cout<<endl;
    }
    return 0;
}