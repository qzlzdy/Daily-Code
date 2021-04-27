//============================================================================
// Name        : HDOJ_1205.cpp
// Author      : Qzlzdy
// Version     : C++
// Description :
//============================================================================

#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int N,max,t;
        __int64 sum = 0;
        scanf("%d",&N);
        max = 0;
        while(N--){
            scanf("%d",&t);
            if(t > max)
                max = t;
            sum += t;
        }
        if(max <= sum - max + 1)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
}
