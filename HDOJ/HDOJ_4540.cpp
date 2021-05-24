//============================================================================
// Name        : HDOJ_4540.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : 威威猫系列故事——打地鼠
//============================================================================
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class Mole{
public:
    Mole(int x);
    int pos,energy;
};
Mole::Mole(int x){
    pos = x;
    energy = 0;
}
class Axis{
public:
    Axis(int N,int K);
    int WhacAMole();
private:
    int energy(int T,int i);
    int consume(int T,int x,int y);
    vector<vector<Mole> > _moles;
};
Axis::Axis(int N,int K){
    int pos;
    for(int i = 0; i < N; i++){
        vector<Mole> row;
        for(int j = 0; j < K; j++){
            cin>>pos;
            row.push_back(Mole(pos));
        }
        _moles.push_back(row);
    }
}
int Axis::WhacAMole(){
    int size = _moles[0].size();
    int time = _moles.size();
    int mini;
    for(int i = 1; i < time; i++){
        for(int j = 0; j < size; j++){
            mini = energy(i - 1,0) + consume(i,j,0);
            for(int k = 1; k < size; k++)
                mini = min(mini,energy(i - 1,k) + consume(i,j,k));
            _moles[i][j].energy = mini;
        }
    }
    mini = energy(time - 1,0);
    for(int i = 1; i < size; i++)
        mini = min(mini,energy(time - 1,i));
    return mini;
}
int Axis::energy(int T,int i){
    return _moles[T][i].energy;
}
int Axis::consume(int T,int x,int y){
    return abs(_moles[T][x].pos - _moles[T - 1][y].pos);
}
int main(){
    int N,K;
    while(cin>>N>>K){
        Axis axis(N,K);
        cout<<axis.WhacAMole()<<endl;
    }
}