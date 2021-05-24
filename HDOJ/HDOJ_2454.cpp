//============================================================================
// Name        : HDOJ_2454.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : Degree Sequence of Graph G:
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        int n,d;
        cin>>n;
        vector<int> dgr;
        while(n--){
            cin>>d;
            dgr.push_back(d);
        }
        sort(dgr.rbegin(),dgr.rend());
        d = dgr[0];
        bool flag = true;
        while(d != 0 && flag){
            dgr[0] = 0;
            for(int i = 1; i <= d; i++){
                dgr[i]--;
                if(dgr[i] < 0){
                    flag = false;
                    break;
                }
            }
            sort(dgr.rbegin(),dgr.rend());
            d = dgr[0];
        }
        if(flag)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
}