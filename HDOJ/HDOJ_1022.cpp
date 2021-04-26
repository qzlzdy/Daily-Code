#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <iterator>

using namespace std;

static string IN = "in";
static string OUT = "out";

int main()
{
    int n;
    string in,out;
    while(cin>>n){
        cin>>in>>out;
        queue<string> order;
        stack<int> sta;
        string::iterator in_it = in.begin();
        string::iterator out_it = out.begin();
        while(in_it != in.end()){
            order.push(IN);
            sta.push(*in_it - '0');
            while(out_it != out.end() && !sta.empty() && sta.top() == *out_it - '0'){
                out_it++;
                sta.pop();
                order.push(OUT);
            }
            in_it++;
        }
        if(out_it == out.end()){
            cout<<"Yes."<<endl;
            while(!order.empty()){
                cout<<order.front()<<endl;
                order.pop();
            }
        }
        else
            cout<<"No."<<endl;
        cout<<"FINISH"<<endl;
    }
    return 0; 
}
