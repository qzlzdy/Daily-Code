#include<iostream>
#include<string>
#include<iterator>

using namespace std;

int main(){
    int n,count;
    string str;
    cin>>n;
    while(n > 0){
        cin>>str;
        count = 0;
        for(string::iterator it = str.begin(); it != str.end(); it++)
            if(*it <= '9' && *it >= '0')
                count++;
        cout<<count<<endl;
        n--;
    }
    return 0;
}