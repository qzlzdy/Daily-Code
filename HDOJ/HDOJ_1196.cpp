#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int A;
    cin>>A;
    while(A != 0)
    {
        int i = 0;;
        while(A % 2 == 0)
        {
            A /= 2;
            i++;
        }
        cout<<(int)pow(2,i)<<endl;
        cin>>A;
    }
    return 0;
}
