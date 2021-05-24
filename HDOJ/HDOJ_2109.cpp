//============================================================================
// Name        : HDOJ_2109.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : Fighting for HDU
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    while(cin>>n){
        if(n == 0)
            break;
        int t;
        vector<int> CH,JP;
        for(int i = 0; i < n; i++){
            cin>>t;
            CH.push_back(t);
        }
        for(int i = 0; i < n; i++){
            cin>>t;
            JP.push_back(t);
        }
        sort(CH.begin(),CH.end());
        sort(JP.begin(),JP.end());
        int point = 0;
        int fail = 0;
        for(int i = 0; i < n; i++){
            if(CH[i] > JP[i])
                point += 2;
            else if(CH[i] == JP[i]){
                point++;
                fail++;
            }else
                fail += 2;
        }
        cout<<point<<" vs "<<fail<<endl;
    }
}