#include<iostream>
#include<stack>

using namespace std;

int combinator(int m,int n){
    int rs = 1;
    stack<int> S;
    for(int i = n; i >= 2; i--)
        S.push(i);
    for(int i = m; i > m - n; i--){
        rs *= i;
        while(!S.empty() && rs % S.top() == 0){
            rs /= S.top();
            S.pop();
        }
    }
    return rs;
}

int main(){
    int n;
    while(cin>>n){
        for(int i = 0; i < n; i++){
            int C = 1;
            for(int j = 0; j < i; j++){
                cout<<combinator(i,j)<<" ";
            }
            cout<<1<<endl;
        }
        cout<<endl; 
    }
    return 0;
} 