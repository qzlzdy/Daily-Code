//============================================================================
// Name        : HDOJ_1144.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : Prerequisites?
//============================================================================
#include <iostream>
#include <string>
#include <set>
using namespace std;
int main(){
    int k,m;
    while(cin>>k){
        if(k == 0)
            break;
        cin>>m;
        set<string> sel;
        string course;
        while(k-- > 0){
            cin>>course;
            sel.insert(course);
        }
        int c,r;
        bool pass = true;
        while(m-- > 0){
            cin>>c>>r;
            int cnt = 0;
            while(c-- > 0){
                cin>>course;
                if(sel.find(course) != sel.end())
                    cnt++;
            }
            if(cnt < r)
                pass = false;
        }
        if(pass)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
}
