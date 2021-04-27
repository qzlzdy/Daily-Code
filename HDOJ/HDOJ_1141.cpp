//============================================================================
// Name        : HDOJ_1128.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : Self Numbers
//============================================================================
#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int y;
    while(cin>>y){
        if(y == 0)
            break;
        double max = exp2((y - 1940) / 10);
        double sum = 0;
        int i = 1;
        while(sum < max)
            sum += log2(++i);
        cout<<i - 1<<endl;
    }
}
