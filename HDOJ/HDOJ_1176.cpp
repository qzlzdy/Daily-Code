//============================================================================
// Name        : HDOJ_1176.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : 免费馅饼
//============================================================================
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
class Axis{
public:
    Axis(int n);
    int getCooks();
private:
    void resize(int count);
    vector<vector<int> > _cooks;
};
Axis::Axis(int n){
    int x,T;
    for(int i = 0; i < n; i++){
        scanf("%d%d",&x,&T);
        if(_cooks.size() < T)
            resize(T);
        _cooks[T - 1][x]++;
    }
}
int Axis::getCooks(){
    for(int i = _cooks.size() - 2; i >= 0; i--){
        for(int j = 0; j < 11; j++){
            int maxi = _cooks[i + 1][j];
            if(j > 0)
                maxi = max(maxi,_cooks[i + 1][j - 1]);
            if(j < 10)
                maxi = max(maxi,_cooks[i + 1][j + 1]);
            _cooks[i][j] += maxi;
        }
    }
    return max(_cooks[0][4],max(_cooks[0][5],_cooks[0][6]));
}
void Axis::resize(int count){
    _cooks.resize(count,vector<int>(11,0));
}
int main(){
    int n;
    while(cin>>n){
        if(n == 0)
            break;
        Axis axis(n);
        cout<<axis.getCooks()<<endl;
    }
}
