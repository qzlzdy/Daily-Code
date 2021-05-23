#include<iostream>
#include<queue>

using namespace std;

int main(){
    int n,cow,i,num;
    while(cin>>n,n != 0){
        queue<int> Q;
        Q.push(0);
        Q.push(0);
        i = 1;
        cow = 1;
        num = 1;
        while(i < n){
            i++;
            Q.push(cow);
            num += cow;
            cow += Q.front();
            Q.pop();
        }
        cout<<num<<endl;
    }
    return 0;
}