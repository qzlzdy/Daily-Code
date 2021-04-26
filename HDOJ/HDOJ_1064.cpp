#include<iostream>
#include<cmath>
using namespace std;
int main(){
    double sum,temp;
    for(int i = 0; i < 12; i++)
    {
        cin>>temp;
        sum += temp;
    }
    sum /= 12;
    cout<<"$"<<floor(sum*100)/100<<endl;
    return 0;
}
