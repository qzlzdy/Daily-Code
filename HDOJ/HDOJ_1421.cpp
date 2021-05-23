//============================================================================
// Name        : HDOJ_1421.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : 搬寝室
//============================================================================
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int func(int a,int b){
    return (a-b)*(a-b);
}
int main(){
    int n,k;
    while(cin>>n>>k){
        int t;
        vector<int> weight;
        for(int i = 0; i < n; i++){
            cin>>t;
            weight.push_back(t);
        }
        sort(weight.begin(),weight.end());
        vector<vector<int> > tire(n + 1,vector<int>(n / 2 + 1,0));
        for(int i = 2; i <= n; i++){
            for(int j = 1; 2 * j <= i; j++){
                int min = tire[i - 2][j - 1] + func(weight[i - 1],weight[i - 2]);
                if(2 * j <= i - 1 && min > tire[i - 1][j])
                    min = tire[i - 1][j];
                tire[i][j] = min;
            }
        }
        cout<<tire[n][k]<<endl;
    }
}