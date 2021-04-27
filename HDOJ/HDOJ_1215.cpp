//============================================================================
// Name        : HDOJ_1215.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : 七夕节
//============================================================================
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main(){
    int T,N;
    cin>>T;
    while(T--){
        cin>>N;
        int sum = 1,up = (int)sqrt(N);
        for(int i = 2; i <= up; i++){
            if(N % i == 0){
                sum += i;
                if(i * i != N)
                    sum += N / i;
            }
        }
        cout<<sum<<endl;
    }
}
