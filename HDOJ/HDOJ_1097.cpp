//============================================================================
// Name        : HDOJ_1097.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : A hard puzzle
//============================================================================
#include <iostream>
using namespace std;
int main()
{
    unsigned long long a,b;
    while(cin>>a>>b)
    {
        unsigned long long r = 1,k = 1;
        while(k != 0)
        {
            if(k & b)
                r = (r * a) % 10;
            a = (a * a) % 10;
            k <<= 1;
        }
        cout<<r<<endl;
    }
}
