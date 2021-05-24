#include<iostream>
#include<string>
#include<iterator>

using namespace std;

bool isLetter(char c){
    return (('A' <= c && c <= 'Z')||('a' <= c && c <= 'z'));
}

bool isNumber(char c){
    return '0' <= c && c <= '9';
}

int main(){
    int n;
    cin>>n;
    getchar();
    while(n > 0){
        string str;
        getline(cin,str,'\n');
        string::iterator it = str.begin();
        if(!isLetter(*it) && *it != '_'){
            cout<<"no"<<endl;
            n--;
            continue;
        }
        while(it != str.end()){
            if(isLetter(*it) || isNumber(*it) || *it == '_')
                ;
            else{
                cout<<"no"<<endl;
                break;
            }
            it++;
        }
        if(it == str.end())
            cout<<"yes"<<endl;
        n--;
    }
    return 0;
}