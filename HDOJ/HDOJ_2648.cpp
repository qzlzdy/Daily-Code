//============================================================================
// Name        : HDOJ_2648.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : Shopping
//============================================================================
#include <iostream>
#include <map>
using namespace std;
int main(){
    int n;
    while(cin>>n){
        string name;
        map<string,int> price;
        for(int i = 0; i < n; i++){
            cin>>name;
            price[name] = 0;
        }
        int m,p,rank;
        cin>>m;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cin>>p>>name;
                price[name] += p;
            }
            rank = 0;
            auto it = price.begin();
            while(it != price.end()){
                if(it->second > price["memory"])
                    rank++;
                it++;
            }
            cout<<rank + 1<<endl;
        }
    }
}