#include<iostream>
#include<vector>
#include<iterator>

using namespace std;

int main(){
    int n,m,t;
    vector<int> vec;
    bool flag;
    while(cin>>n>>m,n != 0 && m != 0){
        vec.clear();
        flag = true;
        for(int i = 0; i < n; i++){
            cin>>t;
            if(flag && t > m){
                vec.push_back(m);
                flag = false;
            }
            vec.push_back(t);
        }
        if(flag)
            vec.push_back(m);
        vector<int>::iterator it = vec.begin();
        cout<<*(it++);
        while(it != vec.end()){
            cout<<" "<<*it;
            it++; 
        }
        cout<<endl;
    }
    return 0;
}