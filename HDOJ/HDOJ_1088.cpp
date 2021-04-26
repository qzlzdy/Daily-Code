#include <iostream>
#include <string>

using namespace std;

string HR(){
    string str = "";
    for(int i = 0; i < 80; i++)
        str += '-';
    return str;
}

int main(){
    string curr;
    int len = 0;
    while(cin>>curr){
        if(curr[0] == '<'){
            if(curr[1] == 'b'){
                cout<<endl;
                len = 0;
            }
            else{
                if(len != 0)
                    cout<<endl;
                cout<<HR()<<endl;
                len = 0;
            }
        }
        else{
            if(curr.length() == 80){
                if(len != 0)
                    cout<<endl;
                cout<<curr;
                len = 80;
                continue;
            }
            if(len + curr.length() + 1 > 80){
                cout<<endl;
                len = 0;
            }
            if(len != 0){
                cout<<" ";
                len++;
            }
            cout<<curr;
            len += curr.length();
        }
    }
    cout<<endl;
}
