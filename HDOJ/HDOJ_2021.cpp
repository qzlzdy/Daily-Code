#include<iostream>

using namespace std;

int rmb[] = {100,50,10,5,2,1};

int main(){
    int n,money,sum;
    while(cin>>n,n != 0){
        sum = 0;
        for(int i = 0; i < n; i++){
            cin>>money;
            int j = 0;
            while(money != 0){
                while(rmb[j] > money)
                    j++;
                money -= rmb[j];
                sum++;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}