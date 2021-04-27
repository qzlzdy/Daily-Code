//============================================================================
// Name        : HDOJ_1159.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : Common Subsequence
//============================================================================
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
int LCS(string X,string Y){
    vector<vector<int> > len(X.length() + 1,vector<int>(Y.length() + 1,0));
    int maxi = 0;
    for(int i = 1; i <= X.length(); i++)
        for(int j = 1; j <= Y.length(); j++){
            if(X[i - 1] == Y[j - 1])
                len[i][j] = len[i - 1][j - 1] + 1;
            else if(len[i][j - 1] >= len[i - 1][j])
                len[i][j] = len[i][j - 1];
            else
                len[i][j] = len[i - 1][j];
            maxi = max(maxi,len[i][j]);
        }
    return maxi;
}
int main(){
    string X,Y;
    while(cin>>X>>Y){
        cout<<LCS(X,Y)<<endl;
    }
}
