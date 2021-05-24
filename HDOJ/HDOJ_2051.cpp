#include <iostream>
#include <stack>
using namespace std;
int main(){
    int n;
    while(cin>>n){
        stack<int> S;
        while(n != 0){
            S.push(n % 2);
            n /= 2;
        }
        while(!S.empty()){
            cout<<S.top();
            S.pop();
        }
        cout<<endl;
    }
    return 0;
} 