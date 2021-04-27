#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int pointOf(double p){
    if(p >= 90 && p <= 100)
        return 4;
    else if(p >= 80/* && p <= 89*/)
        return 3;
    else if(p >= 70/* && p <= 79*/)
        return 2;
    else if(p >= 60/* && p <= 69*/)
        return 1;
    else if(p >= 0/* && p <= 59*/)
        return 0;
    else
        return -1;
}
int main(){
    int N;
    while(cin>>N){
        int point;
        double s,p;
        double sum,s_sum;
        sum = s_sum = 0;
        for(int i = 0; i < N; i++){
            cin>>s>>p;
            point = pointOf(p);
            if(point >= 0){
                s_sum += s;
                sum += s * point;
            }
        }
        if(s_sum != 0)
            cout<<fixed<<setprecision(2)<<sum / s_sum<<endl;
        else
            cout<<-1<<endl;
    } 
}
