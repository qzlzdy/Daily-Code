//============================================================================
// Name        : HDOJ_1162.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : Eddy's picture
//============================================================================
#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;

class Point{
public:
    Point(double px, double py);
    double x,y;
    double key;
};

Point::Point(double px, double py){
    x = px;
    y = py;
    key = HUGE_VAL;
}

void minHeapify(vector<Point> &A, int i){
    unsigned l = 2 * i + 1;
    unsigned r = l + 1;
    int min = i;
    if(l < A.size() && A[l].key < A[i].key)
        min = l;
    if(r < A.size()&& A[r].key < A[min].key)
        min = r;
    if(min != i){
        Point P = A[i];
        A[i] = A[min];
        A[min] = P;
        minHeapify(A, min);
    }
}

void buildMinHeap(vector<Point> &A){
    for(int i = (A.size() - 1)/ 2; i >= 0; i--)
        minHeapify(A, i);
}
int main(){
    int n;
    while(cin>>n){
        vector<Point> points;
        double x, y;
        for(int i = 0; i < n; i++){
            cin>>x>>y;
            points.push_back(Point(x, y));
        }
        double sum = 0;
        points[0].key = 0;
        while(points.size() > 0){
            buildMinHeap(points);
            Point P = points[0];
            points.erase(points.begin());
            for(auto &it : points){
                double dist = hypot(P.x - it.x, P.y - it.y);
                if(dist < it.key){
                    if(it.key != HUGE_VAL)
                        sum -= it.key;
                    it.key = dist;
                    sum += it.key;
                }
            }
        }
        cout<<fixed<<setprecision(2)<<sum<<endl;
    }
}
