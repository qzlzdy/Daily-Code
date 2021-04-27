//============================================================================
// Name        : HDOJ_1161.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : Eddy's mistakes
//============================================================================

#include <iostream>
#include <string>
using namespace std;
int main(){
    string str;
    while(getline(cin,str)){
        string::iterator it = str.begin();
        while(it != str.end()){
            if(*it >= 'A' && *it <= 'Z')
                *it += 32;
            it++;
        }
        cout<<str<<endl;
    }
}
