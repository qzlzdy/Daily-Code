//============================================================================
// Name        : HDOJ_1571.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : 下沙小面的(1)
//============================================================================
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    int NCity;
    while(cin>>NCity){
        if(NCity == 0)
            break;
        vector<vector<int> > dst(NCity,vector<int>(NCity));
        for(auto &row : dst)
            for(auto &it : row)
                cin>>it;
        string op;
        int K,pos,curr = 0,sum = 0;
        vector<int> by;
        cin>>K;
        while(K-- > 0){
            cin>>op;
            if(op == "UP"){
                cin>>pos;
                if(pos != curr && by.size() < 7)
                    by.push_back(pos);
            }else if(op == "GO"){
                if(by.empty())
                    continue;
                sum += dst[curr][by.front()];
                curr = by.front();
                auto it = by.begin();
                while(it != by.end()){
                    if(*it == curr)
                        it = by.erase(it);
                    else
                        it++;
                }
            }
        }
        cout<<sum<<endl;
    }
}