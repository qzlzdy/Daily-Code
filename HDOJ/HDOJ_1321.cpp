//============================================================================
// Name        : HDOJ_1321.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : Reverse Text
//============================================================================
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    int N;
    cin>>N;
    getchar();
    while(N--)
    {
        string str;
        getline(cin,str);
        reverse(str.begin(),str.end());
        cout<<str<<endl;
    }
}