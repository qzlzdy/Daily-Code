//============================================================================
// Name        : HDOJ_1551.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : Cable master
//============================================================================
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;
int cut(double len,vector<double>& cables){
    int sum = 0;
    for(auto &it : cables)
        sum += floor(it / len);
    return sum;
}
int main(){
    int N,K;
    while(cin>>N>>K){
        if(N == 0 && K == 0)
            break;
        vector<double> cables(N);
        for(int i = 0; i < N; i++)
            cin>>cables[i];
        double i = 0.01,j = 1e5;
        while(abs(j - i) > 1e-6){
            double mid = (i + j) / 2;
            int cnt = cut(mid,cables);
            if(cnt >= K)
                i = mid;
            else
                j = mid;
        }
        cout<<fixed<<setprecision(2)<<i<<endl;
    }
}