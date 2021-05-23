//============================================================================
// Name        : HDOJ_1263.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : 水果
//============================================================================
#include <iostream>
#include <string>
#include <map>
using namespace std;
class Area{
public:
    void addFruit(string fruit,int num);
    void showFruits();
private:
    map<string,int> _fruits;
};
void Area::addFruit(string name,int num){
    _fruits[name] += num;
}
void Area::showFruits(){
    for(auto &it : _fruits)
        cout<<"   |----"<<it.first<<'('<<it.second<<')'<<endl;
}
class Infos{
public:
    void addInfo(string fruit,string area,int num);
    void showInfo();
private:
    map<string,Area> _areas;
};
void Infos::addInfo(string fruit,string area,int num){
    _areas[area].addFruit(fruit,num);
}
void Infos::showInfo(){
    for(auto &it : _areas){
        cout<<it.first<<endl;
        it.second.showFruits();
    }
}
int main(){
    int T;
    cin>>T;
    while(T-- > 0){
        Infos info;
        int n,num;
        string fruit,area;
        cin>>n;
        while(n-- > 0){
            cin>>fruit>>area>>num;
            info.addInfo(fruit,area,num);
        }
        info.showInfo();
        if(T > 0)
            cout<<endl;
    }
}