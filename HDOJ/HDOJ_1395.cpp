//============================================================================
// Name        : HDOJ_1395.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : 2^x mod n = 1
//============================================================================
#include <iostream>
#include <set>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        set<int> dict{2};
        int x = 1,item = 2;
        while(item != 1)
        {
            item = (item << 1) % n;
            x++;
            if(dict.find(item) != dict.end())
            {
                x = -1;
                item = 1;
            }
            else
            {
                dict.insert(item);
            }
        }
        if(x == -1)
            cout<<"2^? mod "<<n<<" = 1"<<endl;
        else
            cout<<"2^"<<x<<" mod "<<n<<" = 1"<<endl;
    }
}