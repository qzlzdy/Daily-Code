#include<iostream>
using namespace std;
int main(){
    int T,Y,N;
    cin>>T;
    while(T > 0)
    {
        cin>>Y>>N;
        while(N > 0)
        {
            if ((Y%4==0 && Y%100!=0) || Y%400==0)
                N--;
            Y++;
        }
        cout<<Y-1<<endl;
        T--;
    }
    return 0;
}
