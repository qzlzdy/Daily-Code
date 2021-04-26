#include <iostream>
#include<string>
#include <cstdio>
using namespace std;
int main()
{
    int t,length,count=0;
    string input_str;
    cin>>t;
    getchar();
    for(int i=0; i<t; i++)
    {
        getline(cin,input_str);
        length=input_str.size();
        input_str[length]=' ';
        for(int j=0; j<=length; j++)
        {
            if(input_str[j]!=' ')
            {
                ++count;

            }
            else
            {
                for(int k=j-1; k>=j-count; k--)
                {
                    cout<<input_str[k];
                }
                if(j!=length)
                    cout<<" ";
                count=0;
            }
        }
        cout<<endl;
    }
    return 0;
}
