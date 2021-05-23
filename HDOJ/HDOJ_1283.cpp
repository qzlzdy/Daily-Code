#include <iostream>
#include <string>
#include <iterator>

using namespace std;

int main(){
    int M1,M2,R1,R2,R3;
    string op;
    while(cin>>M1>>M2>>op){
        R1 = R2 = R3 = 0;
        string::iterator it = op.begin();
        while(it != op.end()){
            switch(*it){
            case 'A':
                R1 = M1;
                break;
            case 'B':
                R2 = M2;
                break;
            case 'C':
                M1 = R3;
                break;
            case 'D':
                M2 = R3;
                break;
            case 'E':
                R3 = R1 + R2;
                break;
            case 'F':
                R3 = R1 - R2;
                break;
            }
            it++;
        }
        cout<<M1<<","<<M2<<endl;
    }
}