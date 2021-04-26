#include <iostream>

using namespace std;

int getFib(int n){
    if(n == 0)
        return 1;
    else if(n == 1)
        return 2;
    else{
        int a = 1;
        int b = 2;
        int temp;
        while(n > 1){
            temp = a;
            a = b;
            b = (b + temp) % 3;
            n--;
        }
        return b;
    }
}

int main(){
    int n;
    while(cin>>n){
        if(getFib(n) == 0)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
} 
