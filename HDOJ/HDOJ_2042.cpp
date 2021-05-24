#include <iostream>
using namespace std;
int main(){
    int N;
    cin>>N;
    while(N > 0){
        int i,n = 3;
        cin>>i;
        while(i > 0){
            n = (n - 1) * 2;
            i--;
        }
        cout<<n<<endl;
        N--;
    }
} 