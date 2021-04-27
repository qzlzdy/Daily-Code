//============================================================================
// Name        : HDOJ_1157.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : Who's in the Middle
//============================================================================
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int N;
    while(cin>>N)
    {
        vector<int> cows(N);
        for(int i = 0; i < N; i++)
            cin>>cows[i];
        sort(cows.begin(),cows.end());
        cout<<cows[N / 2]<<endl;
    }
}
