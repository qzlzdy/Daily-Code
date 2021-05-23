#include<iostream>
#include<vector>
#include<iterator>
#include<cmath>
#include<algorithm>

using namespace std;

bool absSort(int a,int b){
    return abs(a) > abs(b);
}

int main(){
    int n,t;
    vector<int> vec;
    while(cin>>n,n != 0){
        vec.clear();
        for(int i = 0; i < n; i++)
            vec.push_back((cin>>t,t));
        sort(vec.begin(),vec.end(),absSort);
        vector<int>::iterator it = vec.begin();
        cout<<*(it++);
        while(it != vec.end())
            cout<<" "<<*(it++);
        cout<<endl;
    } 
    return 0;
}