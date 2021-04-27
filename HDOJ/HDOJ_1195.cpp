//============================================================================
// Name        : HDOJ_1195.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : Open the Lock
//============================================================================
#include <iostream>
#include <string>
#include <queue>
#include <map>
using namespace std;

int BFS(string begin, string end){
    map<string, int> steps;
    steps[begin] = 0;
    queue<string> Q;
    Q.push(begin);
    while(!Q.empty()){
        string code = Q.front();
        if(code == end)
            return steps[code];
        Q.pop();
        for(int i = 0; i < 4; i++){
            if(code[i] == end[i])
                continue;
            string str = code;
            if(str[i] == '9')
                str[i] = '1';
            else
                str[i]++;
            if(steps[str] == 0){
                steps[str] = steps[code] + 1;
                Q.push(str);
            }
            str = code;
            if(str[i] == '1')
                str[i] = '9';
            else
                str[i]--;
            if(steps[str] == 0){
                steps[str] = steps[code] + 1;
                Q.push(str);
            }
        }
        for(int i = 0; i < 3; i++){
            string str = code;
            char tmp = str[i];
            str[i] = str[i + 1];
            str[i + 1] = tmp;
            if(steps[str] == 0){
                steps[str] = steps[code] + 1;
                Q.push(str);
            }
        }
    }
    return -1;
}

int main(){
    int T;
    cin>>T;
    while(T-- > 0){
        string begin, end;
        cin>>begin>>end;
        cout<<BFS(begin, end)<<endl;
    }
}
