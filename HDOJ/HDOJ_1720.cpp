//============================================================================
// Name        : HDOJ_1720.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : A+B Coming
//============================================================================
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string A,B;
    while(cin>>A>>B)
    {
        cout<<stoi("0x" + A,0,16) + stoi("0x" + B,0,16)<<endl;
    }
}