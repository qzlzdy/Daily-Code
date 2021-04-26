//============================================================================
// Name        : HDOJ_1003.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : Max Sum
//============================================================================

#include <iostream>

using namespace std;

int main(){
    int T;
    cin >> T;
    for(int count = 1; count <= T; ++count){
        int N, t;
        cin >> N;
        int sum, low = 1, high = 1;
        int acc = 0, acclow = 1;
        cin >> sum;
        acc += sum;
        for(int i = 1; i < N; ++i){
            cin >> t;
            acc += t;
            if(acc < 0){
                acc = 0;
                acclow = i + 2;
            }
            else if(acc > sum){
                sum = acc;
                low = acclow;
                high = i + 1;
            }
            if(t > sum){
                sum = acc = t;
                acclow = low = high = i + 1;
            }
        }
        cout << "Case " << count << ":" << endl;
        cout << sum << " " << low << " " << high << endl;
        if(count != T){
            cout << endl;
        }
    }
    return 0;
}
