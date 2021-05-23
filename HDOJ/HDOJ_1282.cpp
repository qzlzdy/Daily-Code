//============================================================================
// Name        : HDOJ_1282.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : 回文数猜想
//============================================================================
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool plalindrome(string str){
    auto bg = str.begin();
    auto ed = --str.end();
    while(bg < ed)
    {
        if(*(bg++) != *(ed--))
            return false;
    }
    return true;
}
void transform(string& str){
    string rev;
    reverse_copy(str.begin(),str.end(),rev.begin());
    str = to_string(stoi(str) + stoi(rev));
}
int main()
{
    string str;
    while(cin>>str)
    {
        int cnt = 0;
        string output = str;
        while(!plalindrome(str))
        {
            cnt++;
            transform(str);
            output += "--->" + str;
        }
        cout<<cnt<<endl;
        cout<<output<<endl;
    }
}