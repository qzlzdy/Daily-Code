//============================================================================
// Name        : HDOJ1009.cpp
// Author      : Qzlzdy
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================

#include <iostream>
#include <string>
#include <sstream>
using namespace std;
string tostring(int d){
    ostringstream os;
    os<<d;
    return os.str();
}
int main(){
    string N;
    while(cin>>N){
        if(N == "0")
            break;
        while(N.size() != 1){
            string::iterator it = N.begin();
            int sum = 0;
            while(it != N.end())
                sum += *(it++) - '0';
            N = tostring(sum);
        }
        cout<<N<<endl;
    }
}
