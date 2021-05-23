//============================================================================
// Name        : HDOJ_1587.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : Flowers
//============================================================================
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N,M;
    while(cin>>N>>M){
        vector<int> flws(N);
        for(auto &it : flws)
            cin>>it;
        vector<int> arr(M + 1,0);
        for(int i = 0; i < N; i++)
            for(int j = 0; j <= M; j++)
                if(j >= flws[i] && arr[j - flws[i]] + 1 > arr[j])
                    arr[j] = arr[j - flws[i]] + 1;
        cout<<arr[M]<<endl;
    }
}