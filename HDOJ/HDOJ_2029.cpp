#include<iostream>
#include<string>

using namespace std;

int main(){
    int n;
    cin>>n;
    while(n > 0){
        string str;
        cin>>str;
        int i = 0;
        int j = str.size() - 1;
        while(i < j){
            if(str[i] != str[j]){
                cout<<"no"<<endl;
                break;
            }
            i++;
            j--;
        }
        if(i >= j)
            cout<<"yes"<<endl;
        n--;
    }
    return 0;
}