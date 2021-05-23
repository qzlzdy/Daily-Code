#include<iostream>
#include<cmath>

using namespace std;

bool isPrime(int x){
    if(x <= 1)
        return false;
    for(int i = 2; i <= sqrt(x); i++){
        if(x % i == 0)
            return false;
    }
    return true;
}

int main(){
    int x,y;
    bool flag;
    while(cin>>x>>y,(x != 0)||(y != 0)){
        flag = true;
        for(int i = x; i <= y; i++)
            if(!isPrime(i*i + i + 41)){
                flag = false;
                break;
            }
        if(flag)
            cout<<"OK"<<endl;
        else
            cout<<"Sorry"<<endl;
    }
    return 0;
}