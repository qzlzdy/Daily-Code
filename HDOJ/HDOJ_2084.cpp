//============================================================================
// Name        : HDOJ_2084.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : 数塔
//============================================================================
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main(){
    int C;
    cin>>C;
    while(C--){
        int N,t;
        cin>>N;
        vector<vector<int> > tower;
        for(int i = 1; i <= N; i++){
            vector<int> row;
            for(int j = 1; j <= i; j++){
                cin>>t;
                row.push_back(t);
            }
            tower.push_back(row);
        }
        for(int i = N - 2; i >=0 ; i--)
            for(int j = 0; j <= i; j++)
                tower[i][j] += max(tower[i + 1][j],tower[i + 1][j + 1]);
        cout<<tower[0][0]<<endl;
    }
}