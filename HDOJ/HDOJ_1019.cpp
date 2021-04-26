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
    int n,m,t;
    cin>>n;
    while(n > 0)
    {
        cin>>m;
        vector<int> vec;
        for(int i = 0; i < m; i++)
            vec.push_back((cin>>t,t));
        cout<<accumulate(vec.begin(),vec.end(),1,lcm)<<endl;
        n--;
    } 
    return 0;
}
