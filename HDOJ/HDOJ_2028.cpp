#include<iostream>
#include<vector>
#include<numeric>

using namespace std;

int gcd(int a,int b){
    int t;
    while(b != 0){
        t = a;
        a = b;
        b = t % b;
    }
    return a;
}

int lcm(int a,int b){
    return a / gcd(a,b) * b;
}

int main(){
    int n,t;
    while(cin>>n)
    {
        vector<int> vec;
        for(int i = 0; i < n; i++)
            vec.push_back((cin>>t,t));
        cout<<accumulate(vec.begin(),vec.end(),1,lcm)<<endl;
    } 
    return 0;
}