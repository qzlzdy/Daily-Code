//============================================================================
// Name        : HDOJ_1160.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : FatMouse's Speed
//============================================================================
#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include <algorithm>
using namespace std;
class Mouse{
public:
    Mouse(int w,int s,int i);
    int weight,speed,id;
};
Mouse::Mouse(int w,int s,int i){
    weight = w;
    speed = s;
    id = i;
}
bool cmp(Mouse& A,Mouse& B){
    if(A.weight == B.weight)
        return A.speed > B.speed;
    return A.weight < B.weight;
}
int main(){
    vector<Mouse> mice;
    int w,s,size = 0;
    while(cin>>w>>s)
        mice.push_back(Mouse(w,s,++size));
    sort(mice.begin(),mice.end(),cmp);
    vector<int> tmp{1};
    vector<int> prev{0};
    int maxMice = 0;
    for(int i = 1; i < size; i++){
        int maxi = 1;
        int preId = -1;
        for(int j = 0; j < i; j++)
            if(mice[i].weight > mice[j].weight && mice[i].speed < mice[j].speed)
                if(maxi < tmp[j] + 1){
                    maxi = tmp[j] + 1;
                    preId = j;
                }
        tmp.push_back(maxi);
        prev.push_back(preId);
        maxMice = max(maxMice,maxi);
    }
    stack<int> S;
    int pos = size - 1;
    cout<<maxMice<<endl;
    while(tmp[pos] != maxMice)
        pos--;
    while(prev[pos] != -1){
        S.push(mice[pos].id);
        pos = prev[pos];
    }
    cout<<mice[pos].id<<endl;
    while(!S.empty()){
        cout<<S.top()<<endl;
        S.pop();
    }
}
