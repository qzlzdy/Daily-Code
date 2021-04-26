//============================================================================
// Name        : HDOJ1029.cpp
// Author      : Qzlzdy
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================

#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
int main(){
    int N;
    while(scanf("%d",&N) == 1){
        map<int,int> dict;
        int t = 0;
        for(int i = 0; i < N; i++){
            scanf("%d",&t);
            if(dict.find(t) == dict.end())
                dict[t] = 1;
            else
                dict[t]++;
            if(dict[t] >= (N + 1) / 2){
                cout<<t<<endl;
                break;
            }
        }
        string gomi;
        getline(cin,gomi);
    }
}
