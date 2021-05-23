#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

class Point{
public:
    Point(double x = 0, double y = 0);
    double distant(const Point& p)const;
    double x,y;
};

Point::Point(double x,double y){
    this->x = x;
    this->y = y;
}

double Point::distant(const Point &p)const{
    return sqrt((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y));
}

int main(){
    Point a,b;
    while(cin>>a.x){
        cin>>a.y>>b.x>>b.y;
        cout<<fixed<<setprecision(2)<<a.distant(b)<<endl;
    }
}