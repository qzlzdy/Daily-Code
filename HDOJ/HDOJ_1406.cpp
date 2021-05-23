//============================================================================
// Name        : HDOJ_1406.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : 完数
//============================================================================
#include <iostream>
#include <cmath>
using namespace std;
int f(int x){
    int i = 1, acc = 0;
    while(i < x){
        if(x % i == 0)
            acc += i;
        i++;
    }
    return acc;
}
int main(){
    int n, num1, num2;
    cin>>n;
    while(n-- > 0){
        cin>>num1>>num2;
        int a = min(num1, num2);
        int b = max(num1, num2);
        int cnt = 0;
        for(int i = a; i <= b; i++)
            if(f(i) == i)
                cnt++;
        cout<<cnt<<endl;
    }
}