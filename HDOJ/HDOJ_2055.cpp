//============================================================================
// Name        : HDOJ_2055.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : An easy problem
//============================================================================
#include <iostream>
using namespace std;
int f(char x)
{
    if(x <= 'Z')
        return x - 'A' + 1;
    return 'a' - x - 1;
}
int main()
{
    int T;
    cin>>T;
    while(T-- > 0)
    {
        char x;
        double y;
        cin>>x>>y;
        cout<<y + f(x)<<endl;
    }
}