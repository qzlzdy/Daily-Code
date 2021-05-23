//============================================================================
// Name        : HDOJ_1392.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : Surround the Trees
//============================================================================
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;
class Point{
public:
    Point(double pos_x = 0,double pos_y = 0);
    friend istream& operator>>(istream& in,Point& P);
    Point operator-(const Point& p)const;
    double drection(Point& P);
    double distance(Point& P);
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
Point Point::operator -(const Point& p)const{
    return Point(p.x - x,p.y - y);
}
double Point::drection(Point& P){
    return x * P.y - P.x * y;
}
double Point::distance(Point& P){
    return sqrt((x - P.x)*(x - P.x) + (y - P.y)*(y - P.y));
}
class Segment{
public:
    Segment();
    Segment(Point b,Point e);
    friend istream& operator>>(istream& in,Segment& L);
    double direction(const Segment& L);
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
double Segment::direction(const Segment& L){
    Point t1 = end - begin;
    Point t2 = L.end - L.begin;
    return t1.x * t2.y - t2.x * t1.y;
}
double Segment::direction(Point& P){
    Point t1 = end - begin;
    Point t2 = P - begin;
    return t1.x * t2.y - t2.x * t1.y;
}
bool cmp(Point& P,Point& Q){
    return P.drection(Q) > 0;
}
int main(){
    int n;
    while(cin>>n){
        if(n == 0)
            break;
        else if(n == 1){
            cout<<"0.00"<<endl;
            continue;
        }else if(n == 2){
            Point P,Q;
            cin>>P>>Q;
            cout<<fixed<<setprecision(2)<<P.distance(Q)<<endl;
            continue;
        }
        vector<Point> trees;
        Point min;
        cin>>min;
        for(int i = 1; i < n; i++){
            Point P;
            cin>>P;
            if(P.y < min.y || (P.y == min.y && P.x < min.x)){
                trees.push_back(min);
                min = P;
            }else
                trees.push_back(P);
        }
        for(auto &it : trees){
            it.x -= min.x;
            it.y -= min.y;
        }
        sort(trees.begin(),trees.end(),cmp);
        vector<Point> S{Point(),trees[0],trees[1]};
        for(int i = 2; i < n - 1; i++){
            while(Segment(S[S.size() - 2],S.back()).direction(Segment(S.back(),trees[i])) < 0)
                S.pop_back();
            S.push_back(trees[i]);
        }
        S.push_back(Point());
        double sum = 0;
        for(unsigned i = 0; i < S.size() - 1; i++){
            sum += S[i].distance(S[i + 1]);
        }
        cout<<fixed<<setprecision(2)<<sum<<endl;
    }
}