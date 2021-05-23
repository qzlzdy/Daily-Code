//============================================================================
// Name        : HDOJ_1272.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : 小希的迷宫
//============================================================================
#include <iostream>
#include <map>
using namespace std;
class Set{
public:
    Set();
    Set *findSet();
    void unionSet(Set *x);
private:
    void link(Set *x);
    Set *par;
    int rank;
};
Set::Set(){
    par = this;
    rank = 0;
}
Set *Set::findSet(){
    if(par != this)
        par = par->findSet();
    return par;
}
void Set::unionSet(Set *x){
    findSet();
    link(x->findSet());
}
void Set::link(Set *x){
    if(par->rank > x->rank)
        x->par = par;
    else{
        par->par = x;
        if(x->rank == par->rank)
            x->rank++;
    }
}
int main()
{
    int b,e;
    while(cin>>b>>e)
    {
        if(b == -1 && e == -1)
            break;
        map<int,Set*> dict;
        unsigned cnt = 0,arcs = 0;
        while(b != 0 || e != 0)
        {
            if(b != e)
                arcs++;
            if(dict.find(b) == dict.end())
                dict[b] = new Set;
            if(dict.find(e) == dict.end())
                dict[e] = new Set;
            if(dict[b]->findSet() != dict[e]->findSet())
            {
                dict[b]->unionSet(dict[e]);
                cnt++;
            }
            cin>>b>>e;
        }
        if(arcs == 0 || (cnt + 1 == dict.size() && arcs == cnt))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
}