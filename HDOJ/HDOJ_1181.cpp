//============================================================================
// Name        : HDOJ_1181.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : 变形课
//============================================================================
#include <iostream>
#include <string>
#include <list>
#include <vector>
using namespace std;

class Point{
public:
    Point();
    void connect(Point *p);
    friend bool DFS(Point *begin, Point *end);
private:
    list<Point*> adj;
    bool searched;
};

Point::Point(){
    searched = false;
}

void Point::connect(Point *p){
    adj.push_back(p);
}

bool DFS(Point *begin, Point *end){
    if(begin == end)
        return true;
    begin->searched = true;
    for(auto &it : begin->adj){
        if(!it->searched && DFS(it, end))
            return true;
    }
    return false;
}

int main(){
    string str;
    while(cin>>str){
        vector<Point*> dict;
        list<Point*> points;
        for(int i = 0; i < 26; i++)
            dict.push_back(new Point());
        while(str != "0"){
            Point *p = new Point();
            dict[str.front() - 'a']->connect(p);
            p->connect(dict[str.back() - 'a']);
            points.push_back(p);
            cin>>str;
        }
        if(DFS(dict['b' - 'a'], dict['m' - 'a']))
            cout<<"Yes."<<endl;
        else
            cout<<"No."<<endl;
        for(auto &it : dict)
            delete it;
        for(auto &it : points)
            delete it;
    }
}
