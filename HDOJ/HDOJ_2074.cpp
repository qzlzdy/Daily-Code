#include<iostream>

using namespace std;

int main(){
    char c[2]; 
    bool flag = false;
    int n;
    while(cin>>n){
        cin>>c[1]>>c[0];
        if(flag)
            cout<<endl;
        if(n == 1){
            cout<<c[1]<<endl;
            continue;
        }
        char **str = new char*[n];
        for(int i = 0; i < n; i++)
            str[i] = new char[n];
        int num = (n + 1) / 2;
        for(int i = 0; i < num; i++){
            int x = i,y = i;
            char play;
            if(num % 2 == 0)
                play = c[i % 2];
            else    
                play = c[(i + 1) % 2]; 
            while(y < n - i){
                str[x][y] = play;
                str[n - x - 1][y++] = play;
            }
            y = i;
            while(x < n - i){
                str[x][y] = play;
                str[x++][n - y - 1] = play;
            }
            str[0][0] = str[0][n - 1] = str[n - 1][0] = str[n - 1][n - 1] = ' ';
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++)
                cout<<str[i][j];
            cout<<endl;
        }
        for(int i = 0; i < n; i++)
            delete[] str[i];
        delete[] str;
        flag = true;
    }
    return 0;
}