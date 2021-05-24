#include<iostream>
#include<cmath>
using namespace std;
inline void exchange(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}
int main(){
    int T,a,b,c;
    cin>>T;
    int i = 1;
    while(i <= T)
    {
        cin>>a>>b>>c;
        cout<<"Scenario #"<<i<<":"<<endl;
        if(b > a && b > c)
            exchange(a,b);
        else if(c > a && c > b)
            exchange(a,c);
        if(a*a == b*b+c*c)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
        cout<<endl;
        i++;
    }
    return 0;
}