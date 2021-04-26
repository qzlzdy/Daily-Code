//============================================================================
// Name        : HDOJ_1005.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : Number Sequence
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int A, B, n;
    while(cin >> A >> B >> n){
        if(A == 0 && B == 0 && n == 0){
            break;
        }
        vector<int> arr(2, 1);
        int prev = (A + B) % 7;
        int curr = (A * prev + B) % 7;
        bool loop = false;
        int i;
        while(!loop){
            for(i = 0; i < arr.size() - 1; ++i){
                if(arr[i] == prev && arr[i + 1] == curr){
                    loop = true;
                    break;
                }
            }
            if(!loop){
                arr.push_back(prev);
                prev = curr;
                curr = (A * prev + B * arr[arr.size() - 1]) % 7;
            }
        }
        int a = i + (n - i - 1) % (arr.size() - i);
        cout << arr[n <= i ? n - 1 : a] << endl;
    }
    return 0;
}
