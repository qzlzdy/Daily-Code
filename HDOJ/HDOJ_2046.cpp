#include <iostream>
#include <stack>
using namespace std;
__int64 combinator(int m,int n){
    __int64 rs = 1;
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
        __int64 count = 0;
        for(int i = 0; 2 * i <= n ; i++){
            count += combinator(n - i,i);
        }
        cout<<count<<endl;
    }
} 