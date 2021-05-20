//============================================================================
// Name        : HDOJ_1232.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : 畅通工程
//============================================================================
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
class City{
public:
    City();
    City* findSet();
    void unionSet(City* x);
private:
    void link(City* x);
    City* par;
    int rank;
};
City::City(){
    par = this;
    rank = 0;
}
City* City::findSet(){
    if(par != this)
        par = par->findSet();
    return par;
}
void City::unionSet(City* x){
    findSet();
    link(x->findSet());
}
void City::link(City* x){
    if(par->rank > x->rank)
        x->par = par;
    else{
        par->par = x;
        if(x->rank == par->rank)
            x->rank++;
    }
}
int main(){
    int M,N;
    while(scanf("%d%d",&N,&M)){
        if(N == 0)
            break;
        vector<City*> cities;
        for(int i = 0; i < N; i++)
            cities.push_back(new City());
        int x,y,sum = N - 1;
        for(int i = 0; i < M; i++){
            scanf("%d%d",&x,&y);
            if(cities[x-1]->findSet() != cities[y-1]->findSet()){
                cities[x-1]->unionSet(cities[y-1]);
                sum--;
            }
        }
        cout<<sum<<endl;
        for(int i = 0; i < N; i++)
            delete cities[i];
    }
}
