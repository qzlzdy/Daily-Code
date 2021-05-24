#include <iostream>
#include <string>
using namespace std;
int main(){
    int M;
    cin>>M;
    for(int i = 0; i < M; i++){
        string pw;
        cin>>pw;
        if(pw.length() < 8 || pw.length() > 16){
            cout<<"NO"<<endl;
            continue;
        }
        bool d,lc,hc,s;
        d = lc = hc = s = false;
        for(string::iterator curr = pw.begin(); curr != pw.end(); curr++){
            if(*curr >= 'A' && *curr <= 'Z')
                hc = true;
            else if(*curr >= 'a' && *curr <= 'z')
                lc = true;
            else if(*curr >= '0' && *curr <= '9')
                d = true;
            else
                s = true;
        }
        if(hc + lc + s + d > 2)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
} 