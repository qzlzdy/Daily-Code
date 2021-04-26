//============================================================================
// Name        : HDOJ_1048.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : The Hardest Problem Ever
//============================================================================
#include <iostream>
#include <string>
using namespace std;
string pw = "VWXYZABCDEFGHIJKLMNOPQRSTU";
bool isCharacter(char c){
    return c >= 'A' && c <= 'Z';
}
int main(){
    string str;
    getline(cin,str);
    while(str != "ENDOFINPUT"){
        getline(cin,str);
        string::iterator it = str.begin();
        while(it != str.end()){
            if(isCharacter(*it))
                *it = pw[*it - 'A'];
            it++;
        }
        cout<<str<<endl;
        getline(cin,str);    //END
        getline(cin,str);
    }
}
