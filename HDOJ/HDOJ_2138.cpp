#include<iostream>
#include<cmath>
using namespace std;
bool isPrime(int n){
    if(n == 1)
        return false;
    int m = sqrt(n);
    for(int i = 2; i <= m; i++)
        if(n % i == 0)
            return false;
    return true;
}
int main(){
    int N;
    while(cin>>N){
        int sum = 0,a;
        while(N > 0){
            cin>>a;
            if(isPrime(a))
                sum++;
            N--;
        }
        cout<<sum<<endl;
    }
    return 0;
}