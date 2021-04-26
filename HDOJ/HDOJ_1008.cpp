#include<iostream>

using namespace std;

int main(){
    int N;
    while(cin >> N, N != 0){
        int sum = 0;
        int pos = 0;
        int order;
        while(N > 0){
            cin >> order;
            if(order > pos){
                sum += 6 * (order - pos) + 5;
            }
            else{
                sum += 4 * (pos - order) + 5;
            }
            pos = order;
            --N;
        }
        cout << sum << endl;
    }
    return 0;
}
