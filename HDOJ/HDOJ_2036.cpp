//============================================================================
// Name        : HDOJ_2036.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : 改革春风吹满地
//============================================================================
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
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
int main(){
    int n;
    while(cin>>n){
        if(n == 0)
            break;
        vector<Point> points;
        for(int i = 0; i < n; i++){
            Point P;
            cin>>P;
            points.push_back(P);
        }
        points.push_back(points[0]);
        double sum = 0;
        for(int i = 0; i < n; i++)
            sum += points[i].drection(points[i + 1]);
        sum /= 2;
        cout<<fixed<<setprecision(1)<<abs(sum)<<endl;
    }
}