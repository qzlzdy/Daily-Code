//============================================================================
// Name        : HDOJ_1491.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : Octorber 21st
//============================================================================
#include <iostream>
using namespace std;
int days[] = {0,31,28,31,30,31,30,31,31,30};
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int m,d;
        cin>>m>>d;
        if(m > 10 || (m == 10 && d > 21))
            cout<<"What a pity, it has passed!"<<endl;
        else if(m == 10 && d == 21)
            cout<<"It's today!!"<<endl;
        else{
            int sum = 0;
            for(int i = m; i < 10; i++)
                sum += days[i];
            sum += 21 - d;
            cout<<sum<<endl;
        }
    }
}