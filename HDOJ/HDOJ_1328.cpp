//============================================================================
// Name        : HDOJ_1328.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : IBM Minus One
//============================================================================
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int N;
    cin>>N;
    for(int i = 1; i <= N; i++)
    {
        string str;
        cin>>str;
        for(auto &it : str)
        {
            if(it == 'Z')
                it = 'A';
            else
                it++;
        }
        cout<<"String #"<<i<<endl;
        cout<<str<<'\n'<<endl;
    }
}