//============================================================================
// Name        : HDOJ_2563.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : 统计问题
//============================================================================
#include <iostream>
#include <vector>
using namespace std;
int func(int);
int funcUp(int i){
    if(i == 1)
        return 1;
    return func(i - 1);
}
int funcSide(int i){
    if(i == 1)
        return 2;
    return 2 * funcUp(i - 1) + funcSide(i - 1);
}
int func(int i){
    return funcUp(i) + funcSide(i);
}
int main(){
    int C,n;
    cin>>C;
    while(C--){
        cin>>n;
        cout<<func(n)<<endl;
    }
}