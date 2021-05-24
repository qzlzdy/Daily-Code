#include<iostream>
#include<string>
#include<iterator>

using namespace std;

int main(){
    int n;
    cin>>n;
    getchar();
    while(n > 0){
        int sum = 0;
        string str;
        getline(cin,str,'\n');
        string::iterator it = str.begin();
        while(it != str.end()){
            if(*it < 0)
                sum++;
            it++;
        }
        cout<<sum / 2<<endl;
        n--;
    }
    return 0;
}