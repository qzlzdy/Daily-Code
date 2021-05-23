//============================================================================
// Name        : HDOJ_1266.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : Reverse Number
//============================================================================
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    int N;
    cin>>N;
    while(N--)
    {
        string str;
        cin>>str;
        auto bg = str.begin();
        auto ed = str.end();
        if(*bg == '-')
            bg++;
        while(*(ed - 1) == '0')
            ed--;
        reverse(bg,ed);
        cout<<str<<endl;
    }
}