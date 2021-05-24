#include<iostream>
#include<string>
#include<iterator>

using namespace std;

int main(){
    string str;
    while(getline(cin,str,'\n')){
        string::iterator it = str.begin();
        if(*it >= 'a')
            *it -= 32;
        while(++it != str.end()){
            if(*it == ' ' && ++it != str.end() && *it >= 'a')
                *it -= 32;
        }
        cout<<str<<endl;
    }
    return 0;
} 