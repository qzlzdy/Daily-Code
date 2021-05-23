//============================================================================
// Name        : HDOJ_1969.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : Pie
//============================================================================
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstdio>
using namespace std;
vector<int> rad;
double const PI = 3.1415926535897932384;
int f(double S){
    int sum = 0;
    auto it = rad.begin();
    while(it != rad.end()){
        sum += floor((*it) * (*it) / S);
        it++;
    }
    return sum;
}
int main(){
    int T;
    //cin>>T;
    scanf("%d",&T);
    while(T--){
        int N,F;
        //cin>>N>>F;
        scanf("%d%d",&N,&F);
        rad = vector<int>(N);
        for(int i = 0; i < N; i++)
            //cin>>rad[i];
            scanf("%d",&rad[i]);
        sort(rad.rbegin(),rad.rend());
        double l = 0,r = rad[0] * rad[0];
        while(r - l > 1e-7){
            double mid = (l + r) / 2;
            if(f(mid) < F + 1)
                r = mid;
            else
                l = mid;
        }
        cout<<fixed<<setprecision(4)<<PI * l<<endl;
    }
}