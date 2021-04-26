//============================================================================
// Name        : HDOJ_1058.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : Humble Numbers
//============================================================================
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<int> num{1};
vector<int> prime{2,3,5,7};
vector<int> coe{0,0,0,0};
int advance(){
    int mini = min(min(num[coe[0]] * 2,num[coe[1]] * 3),min(num[coe[2]] * 5,num[coe[3]] * 7));
    num.push_back(mini);
    for(int i = 0; i < 4; i++)
        if(num[coe[i]] * prime[i] == mini)
            coe[i]++;
    return mini;
}
int main(){
    int n;
    while(cin>>n){
        if(n == 0)
            break;
        for(int i = num.size(); i < n; i++)
            advance();
        cout<<"The "<<n;
        if(n % 100 / 10 == 1)
            cout<<"th";
        else{
            switch(n % 10){
            case 1:
                cout<<"st";
                break;
            case 2:
                cout<<"nd";
                break;
            case 3:
                cout<<"rd";
                break;
            default:
                cout<<"th";
            }
        }
        cout<<" humble number is "<<num[n - 1]<<"."<<endl;
    }
}
