#include<iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    string str1, str2;
    stack<int> num1, num2, sum;
    int out, adv, T, i = 1;
    cin >> T;
    while(i <= T){
        cin >> str1 >> str2;
        for(auto iter = str1.begin(); iter != str1.end(); ++iter){
            num1.push(*iter - '0');
        }
        for(auto iter = str2.begin(); iter != str2.end(); ++iter){
            num2.push(*iter - '0');
        }
        adv = 0;
        while(!(num1.empty() && num2.empty())){
            out = adv;
            if(!num1.empty()){
                out += num1.top();
                num1.pop();
            }
            if(!num2.empty()){
                out += num2.top();
                num2.pop();
            }
            adv = out / 10;
            out %= 10;
            sum.push(out);
        }
        if(adv != 0){
            sum.push(adv);
        }
        cout << "Case " << i << ":" << endl;
        cout << str1 << " + " << str2 << " = ";
        while(!sum.empty()){
            cout << sum.top();
            sum.pop();
        }
        cout << endl;
        if(i != T){
            cout << endl;
        }
        ++i;
    }
    return 0; 
} 
