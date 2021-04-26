#include<iostream>
using namespace std;
int main(){
    int a,b;
    while(cin>>a>>b)
    {
        if(a > b)
        {
            int temp = a;
            a = b;
            b = temp;
        }
        int rs = a;
        int i = 2;
        while(rs % b != 0)
            rs = a * (i++);
        cout<<rs<<endl;
    } 
    return 0;
}
