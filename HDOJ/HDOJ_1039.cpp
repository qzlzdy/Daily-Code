//============================================================================
// Name        : HDOJ_1039.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : Easier Done Than Said?
//============================================================================
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
bool isVowel(char ch){
    switch(ch){
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        return true;
    default:
        return false;
    }
}
int main(){
    string str;
    while(cin>>str){
        if(str == "end")
            break;
        bool vowel = false;
        for(auto &it : str){
            if(isVowel(it)){
                vowel = true;
                break;
            }
        }
        bool repeat = true;
        bool combo = true;
        char prev = str[0];
        bool type = isVowel(str[0]);
        char cnt = 1;
        for(unsigned i = 1; i < str.length(); i++){
            if(prev == str[i]){
                if(prev != 'e' && prev != 'o'){
                    repeat = false;
                    break;
                }
            }
            if(type == isVowel(str[i])){
                if(++cnt == 3){
                    combo = false;
                    break;
                }
            }else{
                cnt = 1;
                type ^= true;
            }
            prev = str[i];
        }
        if(vowel && repeat && combo)
            printf("<%s> is acceptable.\n",str.c_str());
        else
            printf("<%s> is not acceptable.\n",str.c_str());
    }
}
