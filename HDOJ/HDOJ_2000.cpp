#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iterator>

using namespace std;

int main(){
    string str;
    vector<char> ch;
    while(cin>>str){
        ch.clear();
        for(string::iterator iter = str.begin();iter != str.end();iter++)
            ch.push_back(*iter);
        sort(ch.begin(),ch.end());
        cout<<ch[0]<<" "<<ch[1]<<" "<<ch[2]<<endl;
    }
}