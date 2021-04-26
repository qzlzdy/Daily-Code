#include <iostream>

using namespace std;

int main(){
    int N;
    cin >> N;
    string str;
    for(int i = 0; i < N; ++i){
        cin >> str;
        str += '\0';
        char prev = 0;
        int count = 0;
        for(auto &curr : str){
            if(prev == 0){  // first char
                prev = curr;
                count = 1;
            }else if(curr == prev){ // duplicate
                ++count;
            }else if(count == 1){   // single
                cout << prev;
                prev = curr;
                count = 1;
            }else{  // duplicate
                cout << count << prev;
                prev = curr;
                count = 1;
            }
        }
        cout << endl;
    }
    return 0;
}
