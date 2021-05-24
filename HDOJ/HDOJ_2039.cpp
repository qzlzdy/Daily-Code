#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int M;
    double t;
    cin>>M;
    while(M > 0){
        vector<double> vec;
        for(int i = 0; i < 3; i++)
            vec.push_back((cin>>t,t));
        sort(vec.begin(),vec.end());
        if(vec[0] + vec[1] > vec[2])
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
        M--;
    }
    return 0;
} 