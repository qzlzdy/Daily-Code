#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n,key,pos,t;
    vector<int> vec;
    while(cin>>n,n != 0){
        vec.clear();
        vec.push_back((cin>>t,t));
        key = t;
        pos = 0;
        for(int i = 1; i < n; i++){
            vec.push_back((cin>>t,t));
            if(t < key){
                key = t;
                pos = i;
            }
        }
        if(pos != 0){
            vec[pos] = vec[0];
            vec[0] = key;
        }
        cout<<vec[0];
        for(int i = 1; i < n; i++)
            cout<<" "<<vec[i];
        cout<<endl;
    }
    return 0;
}