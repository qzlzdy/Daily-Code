//============================================================================
// Name        : HDOJ_1200.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : To and Fro
//============================================================================
#include <iostream>
#include <string>
using namespace std;

int f(int i, int j, int n){
    return i * n + 1 + (i % 2 == 0 ? j - 1 : n - j - 2);
}

int main(){
    int col;
    while(cin>>col){
        if(col == 0)
            break;
        string str;
        cin>>str;
        int row = str.length() / col;
        for(int j = 0; j < col; j++)
            for(int i = 0; i < row; i++)
                cout<<str[f(i, j, col)];
        cout<<endl;
    }
}
