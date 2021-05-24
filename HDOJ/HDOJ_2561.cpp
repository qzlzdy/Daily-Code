#include<iostream>
using namespace std;
int main(){
    int C,n,B[100],temp;
    cin>>C;
    while(C > 0)
    {
        cin>>n;
        for(int i = 0; i < 100; i++)
            B[i] = 0;
        for(int i = 0; i < n; i++)
        {
            cin>>temp;
            B[temp]++;
        }
        int i = 0;
        int j = 2;
        while(j > 0)
        {
            j -= B[i];
            i++;
        }
        cout<<i-1<<endl;
        C--;
    } 
    return 0;
}