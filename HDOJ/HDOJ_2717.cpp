//============================================================================
// Name        : HDOJ_2717.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : Catch That Cow
//============================================================================
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <cmath>
using namespace std;
class Point{
public:
    Point(int pos);
    int x,t;
};
Point::Point(int pos){
    x = pos;
    t = 0;
}
int main(){
    int N,K;
    while(cin>>N>>K){
        if(N == K){
            cout<<0<<endl;
            continue;
        }
        set<int> S;
        queue<Point> Q;
        S.insert(N);
        Q.push(Point(N));
        while(!Q.empty()){
            Point curr = Q.front();
            Q.pop();
            Point next(0);
            if(curr.x < K){
                next.x = curr.x + 1;
                if(next.x == K){
                    cout<<curr.t + 1<<endl;
                    break;
                }
                if(S.find(next.x) == S.end()){
                    S.insert(next.x);
                    next.t = curr.t + 1;
                    Q.push(next);
                }
                next.x = 2 * curr.x;
                if(next.x == K){
                    cout<<curr.t + 1<<endl;
                    break;
                }
                if(S.find(next.x) == S.end()){
                    S.insert(next.x);
                    next.t = curr.t + 1;
                    Q.push(next);
                }
            }
            if(curr.x > 0){
                next.x = curr.x - 1;
                if(next.x == K){
                    cout<<curr.t + 1<<endl;
                    break;
                }
                if(S.find(next.x) == S.end()){
                    S.insert(next.x);
                    next.t = curr.t + 1;
                    Q.push(next);
                }
            }
        }
    }
}