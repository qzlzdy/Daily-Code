//============================================================================
// Name        : HDOJ_1050.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : Moving Tables
//============================================================================

#include <iostream>
#include <vector>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        int N,s,t;
        vector<int> arr(200,0);
        cin>>N;
        while(N--){
            cin>>s>>t;
            s = (s - 1) / 2;
            t = (t - 1) / 2;
            if(s > t){
                int m = s;
                s = t;
                t = m;
            }
            for(int i = s; i <= t; i++)
                arr[i]++;
        }
        int max = 0;
        for(vector<int>::iterator it = arr.begin(); it != arr.end(); it++){
            if(*it > max)
                max = *it;
        }
        cout<<10 * max<<endl;
    }
}

