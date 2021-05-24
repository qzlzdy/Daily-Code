#include<iostream>
#include<list>

using namespace std;

int main(){
    int n,m,t;
    while(cin>>n>>m,n != 0 || m != 0){
        list<int> L1;
        for(int i = 0; i < n; i++)
            L1.push_back((cin>>t,t));
        for(int j = 0; j < m; j++)
            L1.remove((cin>>t,t));
        if(L1.empty())
            cout<<"NULL"<<endl;
        else{
            L1.sort();
            L1.unique();
            while(!L1.empty()){
                cout<<L1.front()<<" ";
                L1.pop_front();
            }
            cout<<endl;
        }
    }
    return 0;
} 