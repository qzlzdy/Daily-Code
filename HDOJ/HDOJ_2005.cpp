#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

int days[] = {0,31,59,90,120,151,181,212,243,273,304,334,365};

bool isYear(int year){
    if(year % 400 == 0)
        return true;
    else if(!(year % 100 == 0)&&(year % 4 == 0))
        return true;
    else
        return false;
}

int main(){
    string str;
    int year,month,day;
    while(cin>>str){
        int prev,curr;
        prev = curr = 0;
        while(str[curr] != '/')
            curr++;
        year = atoi(str.substr(prev,curr).c_str());
        prev = curr = curr + 1;
        while(str[curr] != '/')
            curr++;
        month = atoi(str.substr(prev,curr).c_str());
        prev = curr = curr + 1;
        while(str[curr] != '\0')
            curr++;
        day = atoi(str.substr(prev,curr).c_str());
        int sum = days[month - 1] + day;
        if(isYear(year)&&month > 2)
            sum++;
        cout<<sum<<endl;
    }
    return 0;
}