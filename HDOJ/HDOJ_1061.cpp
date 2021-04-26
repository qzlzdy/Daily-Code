#include <iostream>
using namespace std;
int digit[10][4] = {{0},{1},{6,2,4,8},{1,3,9,7},{6,4},
    {5},{6},{1,7,9,3},{6,8,4,2},{1,9}};
int num[10] = {1,1,4,4,2,1,1,4,4,2};
int main(){
    int T;
    cin>>T;
    for(int i = 0; i < T; i++){
        int N,d;
        cin>>N;
        d = N % 10;
        cout<<digit[d][N % num[d]]<<endl;
    }
} 
