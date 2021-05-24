//============================================================================
// Name        : HDOJ_2047.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : 阿牛的EOF牛肉串
//============================================================================
#include <iostream>
#include <vector>
using namespace std;
vector<long long> arr{3,8};
int main()
{
    int n;
    while(cin>>n)
    {
        for(int i = arr.size(); i < n; i++)
        {
            arr.push_back(2 * arr[i - 1] + 2 * arr[i - 2]);
        }
        cout<<arr[n - 1]<<endl;;
    }
}