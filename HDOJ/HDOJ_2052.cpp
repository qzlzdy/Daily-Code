#include <iostream>
using namespace std;
int main()
{
    int w,h;
    while(cin>>w>>h)
    {
        for(int i = 0; i < h + 2; i++)
        {
            cout<<"|+"[i == 0 || i == h + 1];
            for(int j = 0; j < w; j++)
            {
                cout<<" -"[i == 0 || i == h + 1];
            }
            cout<<"|+"[i == 0 || i == h + 1]<<endl;
        }
        cout<<endl;
    }
}