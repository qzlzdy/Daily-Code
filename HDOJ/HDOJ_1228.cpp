#include <iostream>
#include <string> 
#include <map>

using namespace std;

map<string,int> dict = {
    {"zero",0},
    {"one",1},
    {"two",2},
    {"three",3},
    {"four",4},
    {"five",5},
    {"six",6},
    {"seven",7},
    {"eight",8},
    {"nine",9}
};

int main(){
    string curr;
    int A,B;
    while(cin>>curr){
        A = dict[curr];
        while(cin>>curr,curr != "+"){
            A *= 10;
            A += dict[curr];
        }
        B = dict[(cin>>curr,curr)];
        while(cin>>curr,curr != "="){
            B *= 10;
            B += dict[curr];
        }
        if(A == 0 && B == 0)
            break;
        cout<<A + B<<endl;
    }
}
