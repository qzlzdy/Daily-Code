//============================================================================
// Name        : HDOJ_1049.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : Climbing Worm
//============================================================================
#include <iostream>
using namespace std;
int main(){
    int n,u,d;
    while(cin>>n>>u>>d){
        if(n == 0)
            break;
        int time = 0;
        while(n != 0){
            if(n <= u){
                time++;
                break;
            }
            time += n / u * 2;
            n -= (u - d) * (n / u);
        }
        cout<<time<<endl;
    }
}
