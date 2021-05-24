#include<iostream>
#include<string>
#include<iterator>

using namespace std;

int a,e,i,o,u;

void clear(){
    a = e = i = o = u = 0;
}

void show(){
    cout<<"a:"<<a<<endl;
    cout<<"e:"<<e<<endl;
    cout<<"i:"<<i<<endl;
    cout<<"o:"<<o<<endl;
    cout<<"u:"<<u<<endl;
}

int main(){
    int n;
    cin>>n;
    getchar();
    while(n > 0){
        string str;
        getline(cin,str,'\n');
        string::iterator it = str.begin();
        clear();
        while(it != str.end()){
            switch(*it){
            case 'a':
                a++;
                break;
            case 'e':
                e++;
                break;
            case 'i':
                i++;
                break;
            case 'o':
                o++;
                break;
            case 'u':
                u++;
                break;
            }
            it++;
        }
        show();
        n--;
        if(n > 0)
            cout<<endl;
    }
    return 0;
}