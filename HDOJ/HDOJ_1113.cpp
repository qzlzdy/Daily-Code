//============================================================================
// Name        : HDOJ_xxxx.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : null
//============================================================================
#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
int main(){
    string str;
    set<string> dict;
    while(cin>>str){
        if(str == "XXXXXX")
            break;
        dict.insert(str);
    }
    set<string> rs;
    while(cin>>str){
        if(str == "XXXXXX")
            break;
        rs.clear();
        for(auto &it : dict)
            if(is_permutation(it.begin(),it.end(),str.begin()))
                rs.insert(it);
        if(rs.size() == 0){
            cout<<"NOT A VALID WORD"<<endl;
            cout<<"******"<<endl;
        }else{
            for(auto &it : rs)
                cout<<it<<endl;
            cout<<"******"<<endl;
        }
    }
}
