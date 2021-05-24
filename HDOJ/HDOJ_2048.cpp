//============================================================================
// Name        : HDOJ_2048.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : 神、上帝以及老天爷
//============================================================================
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
vector<long long> arr{0,1};
vector<long long> fact{1};
int main()
{
    int C;
    cin>>C;
    while(C--)
    {
        int n;
        cin>>n;
        for(int i = arr.size(); i < n; i++)
        {
            arr.push_back(i * (arr[i - 1] + arr[i - 2]));
        }
        for(int i = fact.size(); i <= n; i++)
        {
            fact.push_back(i * fact.back());
        }
        cout<<fixed<<setprecision(2);
        cout<<100.0 * arr[n - 1] / fact[n]<<'%'<<endl;
    }
}