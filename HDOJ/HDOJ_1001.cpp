#include <iostream>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        int sum = 0;
        if(n % 2 == 0){
            sum = n / 2;
            sum *= n + 1;
        }
        else{
            sum = (n + 1) / 2;
            sum *= n;
        }
        cout << sum << endl;
        cout << endl;
    }
    return 0;
}
