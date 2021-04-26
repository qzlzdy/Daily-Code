//============================================================================
// Name        : HDOJ_1159.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : Common Subsequence
//============================================================================
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main(){
    int N,t;
    while(cin>>N){
        if(N == 0)
            break;
        vector<int> points;
        for(int i = 0; i < N; i++){
            cin>>t;
            points.push_back(t);
        }
        vector<int> score{points[0]};
        int maxSum = points[0];
        for(int i = 1; i < points.size(); i++){
            int maxi = points[i];
            for(int j = 0; j < i; j++)
                if(points[i] > points[j])
                    maxi = max(maxi,points[i] + score[j]);
            score.push_back(maxi);
            maxSum = max(maxSum,maxi);
        }
        cout<<maxSum<<endl;
    }
}
