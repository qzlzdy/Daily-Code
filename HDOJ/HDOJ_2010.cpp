#include<iostream>
#include<vector>
#include<iterator>

using namespace std;

int main(){
    int m,n;
    int a,b,c;
    vector<int> vec;
    while(cin>>m>>n){
        vec.clear();
        for(int i = m; i <= n; i++){
            a = i / 100;
            b = i / 10 - 10 * a;
            c = i % 10;
            if(a*a*a+b*b*b+c*c*c == i)
                vec.push_back(i);
        }
        if(vec.empty())
            cout<<"no"<<endl;
        else{
            for(int i = 0; i < vec.size() - 1; i++)
                cout<<vec[i]<<" ";
            cout<<vec[vec.size() - 1]<<endl;
        }
            
    }
    return 0;
}