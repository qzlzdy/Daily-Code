//============================================================================
// Name        : HDOJ_1412.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : {A} + {B}
//============================================================================
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        vector<int> A(n),B(m),C;
        for(auto &it : A)
            cin>>it;
        for(auto &it : B)
            cin>>it;
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        set_union(A.begin(),A.end(),B.begin(),B.end(),back_inserter(C));
        for(auto it = C.begin(); it != C.end(); it++)
        {
            cout<<*it<<" \n"[it + 1 == C.end()];
        }
    }
}