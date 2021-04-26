//============================================================================
// Name        : HDOJ_1086.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : You can Solve a Geometry Problem too
//============================================================================
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
class Point{
public:
    Point(double pos_x = 0,double pos_y = 0);
    friend istream& operator>>(istream& in,Point& P);
    Point operator-(Point& p);
    double x,y;
};
Point::Point(double pos_x,double pos_y){
    x = pos_x;
    y = pos_y;
}
istream& operator>>(istream& in,Point& P){
    in>>P.x>>P.y;
    return in;
}
Point Point::operator -(Point& p){
    return Point(p.x - x,p.y - y);
}
class Segment{
public:
    Segment();
    Segment(Point b,Point e);
    friend istream& operator>>(istream& in,Segment& L);
    double direction(Segment& L);
    double direction(Point& P);
    bool onSegment(Point& P);
    bool isIntersect(Segment& L);
    Point begin,end;
};
Segment::Segment(){
    begin = Point();
    end = Point();
}
Segment::Segment(Point b,Point e){
    begin = b;
    end = e;
}
istream& operator>>(istream& in,Segment& L){
    in>>L.begin>>L.end;
    return in;

}
double Segment::direction(Segment& L){
    Point t1 = end - begin;
    Point t2 = L.end - L.begin;
    return t1.x * t2.y - t2.x * t1.y;
}
double Segment::direction(Point& P){
    Point t1 = end - begin;
    Point t2 = P - begin;
    return t1.x * t2.y - t2.x * t1.y;
}
bool Segment::onSegment(Point& P){
    if(min(begin.x,end.x) <= P.x && P.x <= max(begin.x,end.x) &&
            min(begin.y,end.y) <= P.y && P.y <= max(begin.y,end.y))
        return true;
    return false;
}
bool Segment::isIntersect(Segment& L){
    int d1 = L.direction(begin);
    int d2 = L.direction(end);
    int d3 = direction(L.begin);
    int d4 = direction(L.end);
    if(((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) &&
            ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0)))
        return true;
    if(d1 == 0 && L.onSegment(begin))
        return true;
    if(d2 == 0 && L.onSegment(end))
        return true;
    if(d3 == 0 && onSegment(L.begin))
        return true;
    if(d4 == 0 && onSegment(L.end))
        return true;
    return false;
}
int main(){
    int N;
    while(cin>>N){
        if(N == 0)
            break;
        vector<Segment> segments;
        int count = 0;
        for(int i = 0; i < N; i++){
            Segment L;
            cin>>L;
            for(auto &it : segments){
                if(it.isIntersect(L))
                    count++;
            }
            segments.push_back(L);
        }
        cout<<count<<endl;
    }
}
