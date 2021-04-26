//============================================================================
// Name        : HDOJ_1129.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : Do the Untwist
//============================================================================
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int toCode(char text){
    switch(text){
    case '_':
        return 0;
    case '.':
        return 27;
    default:
        return text - 'a' + 1;
    }
}
char toText(int code){
    switch(code){
    case 0:
        return '_';
    case 27:
        return '.';
    default:
        return code + 'a' - 1;
    }
}
int main(){
    int k;
    string ciphertext;
    while(cin>>k){
        if(k == 0)
            break;
        cin>>ciphertext;
        int n = ciphertext.length();
        vector<char> plaintext(n);
        for(int i = 0; i < n; i++){
            int plaincode = toCode(ciphertext[i]) + i;
            while(plaincode >= 28)
                plaincode -= 28;
            plaintext[k * i % n] = toText(plaincode);
        }
        for(auto &it : plaintext)
            cout<<it;
        cout<<endl;
    }
}
