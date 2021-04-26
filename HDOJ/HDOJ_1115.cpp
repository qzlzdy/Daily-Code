//============================================================================
// Name        : HDOJ_1115.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : Lifting the Stone
//============================================================================
#include <iostream>
#include <vector>
#include <iomanip>
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
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        vector<Point> points;
        for(int i = 0; i < N; i++){
            Point P;
            cin>>P;
            points.push_back(P);
        }
        points.push_back(points[0]);
        double x,y,sum;
        x = y = sum = 0;
        for(int i = 0; i < N; i++){
            double A = points[i].drection(points[i + 1]);
            sum += A;
            x += A * (points[i].x + points[i + 1].x);
            y += A * (points[i].y + points[i + 1].y);
        }
        sum *= 3;
        cout<<fixed<<setprecision(2)<<x / sum<<" "<<y / sum<<endl;
    }
}
