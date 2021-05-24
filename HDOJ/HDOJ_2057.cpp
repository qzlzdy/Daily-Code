//============================================================================
// Name        : HDOJ_2057.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : A + B Again
//============================================================================
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main()
{
    string A,B;
    while(cin>>A>>B)
    {
        long long sum = stoll(A,nullptr,16) + stoll(B,nullptr,16);
        cout<<hex<<uppercase;
        if(sum < 0)
        {
            cout<<'-';
            cout<<(sum ^ 0xffffffffffffffff) + 1<<endl;
        }
        else
            cout<<sum<<endl;
    }
}
