#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
    int N, max;
    string str, maxStr;
    map<string, int> m; 
    while(cin >> N, N != 0){
        m.clear();
        max = 0;
        maxStr = "";
        while(N > 0){
            cin >> str;
            if(m.find(str) == m.end()){
                m[str] = 1;
            }
            else{
                m[str]++;
            }
            if(m[str] > max){
                max = m[str];
                maxStr = str;
            }
            --N;
        }
        cout << maxStr << endl;
    }
    return 0;
} 
