#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t > 0){
        int n;
        cin>>n;
        double curr,max = 0;
        while(n > 0){
            cin>>curr;
            if(curr > max)
                max = curr;
            n--;
        }
        cout<<fixed<<setprecision(2)<<max<<endl;
        t--;
    } 
    return 0;
} 