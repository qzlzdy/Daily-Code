//============================================================================
// Name        : HDOJ_1164.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : Eddy's research I
//============================================================================
#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<bool> prime(65535,true);
    for(int i = 2; i <= 65535; i++){
        if(!prime[i - 2])
            continue;
        int k = i + i;
        while(k <= 65535){
            prime[k - 2] = false;
            k += i;
        }
    }
    int x;
    while(cin>>x){
        int i = 2;
        while(!prime[x - 2]){
            if(x % i == 0){
                cout<<i<<'*';
                x /= i;
            }else
                while(!prime[(++i) - 2]);
        }
        cout<<x<<endl;
    }
}
