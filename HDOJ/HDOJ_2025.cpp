#include<iostream>
#include<iterator>
#include<string>

using namespace std;

int main(){
    string str;
    while(cin>>str){
        char max = 0;
        string::iterator it = str.begin();
        while(it != str.end()){
            if(*it > max)
                max = *it;
            it++;
        }
        it = str.begin();
        while(it != str.end()){
            cout<<*it;
            if(*it == max)
                cout<<"(max)";
            it++;
        }
        cout<<endl;
    }
    return 0;
}