//============================================================================
// Name        : HDOJ_2108.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : Shape of HDU
//============================================================================
#include <iostream>
#include <vector>
using namespace std;
class Point{
public:
    Point(double pos_x = 0,double pos_y = 0);
    friend istream& operator>>(istream& in,Point& P);
    Point operator-(Point& p);
    double drection(Point& P);
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
double Point::drection(Point& P){
    return x * P.y - P.x * y;
}
class Segment{
public:
    Segment();
    Segment(Point b,Point e);
    friend istream& operator>>(istream& in,Segment& L);
    double direction(Segment& L);
    double direction(Point& P);
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
int main(){
    int n;
    while(cin>>n){
        if(n == 0)
            break;
        Segment first,L;
        cin>>L;
        first = L;
        int i;
        for(i = 2; i < n; i++){
            Point P;
            cin>>P;
            if(L.direction(P) < 0)
                break;
            L.begin = L.end;
            L.end = P;
        }
        if(i < n || L.direction(first.begin) < 0 ||
                Segment(L.end,first.begin).direction(first.end) < 0)
            cout<<"concave"<<endl;
        else
            cout<<"convex"<<endl;
    }
}