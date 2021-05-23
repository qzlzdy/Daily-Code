//============================================================================
// Name        : HDOJ_1800.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : Flying to the Mars
//============================================================================

#include <iostream>
#include <cstdio>
#include <string>
#include <map>
using namespace std;
int main(){
    int N;
    while(cin>>N){
        map<int,int> num;
        int t,max = 0;
        while(N--){
            scanf("%d",&t);
            if(num.find(t) == num.end())
                num[t] = 1;
            else
                num[t]++;
            if(num[t] > max)
                max = num[t];
        }
        cout<<max<<endl;
    }
}