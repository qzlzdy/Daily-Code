//============================================================================
// Name        : HDOJ_1007.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : Quoit Design
//============================================================================

#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

class Point{
public:
    Point(double x,double y);
    double x(){return _x;}
    double y(){return _y;}
    double distOf(Point &other);
private:
    double _x,_y;
};

Point::Point(double x,double y){
    _x = x;
    _y = y;
}

double Point::distOf(Point &other){
    return sqrt((_x - other._x) * (_x - other._x) + (_y - other._y) * (_y - other._y));
}

double findMinCrossDist(vector<Point>& arr,int begin,int mid,int end,double min){
    vector<Point> tmp;
    for(int i = mid - 1; i >= begin && arr[mid].x() - arr[i].x() <= min; --i){
        tmp.push_back(arr[i]);
    }
    for(int i = mid; i < end && arr[i].x() - arr[mid].x() <= min; ++i){
        tmp.push_back(arr[i]);
    }
    auto cmpy = [](Point &A,Point &B){
        if(A.y() == B.y()){
            return A.x() < B.x();
        }
        return A.y() < B.y();
    };
    sort(tmp.begin(),tmp.end(),cmpy);
    for(int i = 0; i < tmp.size(); ++i){
        for(int j = i + 1; j < tmp.size(); ++j){
            if(tmp[j].y() - tmp[i].y() > min){
                break;
            }
            double d = tmp[i].distOf(tmp[j]);
            if(d < min){
                min = d;
            }
        }
    }
    return min;
}

double findMinDist(vector<Point> &arr,int begin,int end){
    if(end - begin < 2){
        return HUGE_VAL;
    }
    if(end - begin == 2){
        return arr[begin].distOf(arr[begin + 1]);
    }
    int mid = (begin + end) / 2;
    double mini = min(findMinDist(arr, begin, mid), findMinDist(arr, mid, end));
    return min(mini, findMinCrossDist(arr, begin, mid, end, mini));
}

int main(){
    int N;
    while(cin >> N){
        if(N == 0){
            break;
        }
        vector<Point> arr;
        double x, y;
        while(N--){
            scanf("%lf%lf", &x, &y);
            arr.push_back(Point(x, y));
        }
        auto cmpx = [](Point &A,Point &B){
            if(A.x() == B.x()){
                return A.y() < B.y();
            }
            return A.x() < B.x();
        };
        sort(arr.begin(), arr.end(), cmpx);
        cout << fixed << setprecision(2) << findMinDist(arr, 0, arr.size()) / 2 << endl;
    }
}
