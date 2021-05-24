//============================================================================
// Name        : HDOJ_2064.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : 汉诺塔III
//============================================================================
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    vector<long long> arr{2};
    while(cin>>N){
        for(int i = arr.size(); i < N; i++)
            arr.push_back(3 * arr.back() + 2);
        cout<<arr[N - 1]<<endl;
    }
}