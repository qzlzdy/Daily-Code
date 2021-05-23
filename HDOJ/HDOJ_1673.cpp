//============================================================================
// Name        : HDOJ_1673.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : Optimal Parking
//============================================================================
#include <iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,tmp;
        int min = 0x7fffffff,max = 0x80000000;
        cin>>n;
        while(n--)
        {
            cin>>tmp;
            if(tmp > max)
                max = tmp;
            if(tmp < min)
                min = tmp;
        }
        cout<<2 * (max - min)<<endl;
    }
}