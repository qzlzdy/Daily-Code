#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int T,N;
    cin>>T;
    while(T > 0){
        cin>>N;
        double NlgN = N * log10(N);
        double y = floor(NlgN);
        int x = (int)pow(10,NlgN - y);
        cout<<x<<endl;
        T--;
    }
    return 0;
}
