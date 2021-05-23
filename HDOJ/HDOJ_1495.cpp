//============================================================================
// Name        : HDOJ_1253.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : 胜利大逃亡
//============================================================================
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
int S,N,M;
bool balance(int s,int n){
    if(s == 0 && 2 * n == S)
        return true;
    if(n == 0 && 2 * s == S)
        return true;
    if(n == s && n + s == S)
        return true;
    return false;
}
class Point{
public:
    Point(int S,int N);
    int s,n;
    int time;
};
Point::Point(int S,int N){
    s = S;
    n = N;
    time = 0;
}
int BFS(vector<vector<bool> >& searched){
    queue<Point> Q;
    Point start(S,0);
    searched[S][0] = true;
    Q.push(start);
    while(!Q.empty()){
        Point curr = Q.front();
        Q.pop();
        //cout<<curr.s<<" "<<curr.n<<" "<<curr.time<<endl;
        int delta,m = S - curr.s - curr.n;
        Point next(0,0);
        if(curr.s > 0 && curr.n < N){
            delta = min(curr.s,N - curr.n);
            next.s = curr.s - delta;
            next.n = curr.n + delta;
            if(!searched[next.s][next.n]){
                if(balance(next.s,next.n))
                    return curr.time + 1;
                searched[next.s][next.n] = true;
                next.time = curr.time + 1;
                Q.push(next);
            }
        }
        if(curr.s > 0 && m < M){
            delta = min(curr.s,M - m);
            next.s = curr.s - delta;
            next.n = curr.n;
            if(!searched[next.s][next.n]){
                if(balance(next.s,next.n))
                    return curr.time + 1;
                searched[next.s][next.n] = true;
                next.time = curr.time + 1;
                Q.push(next);
            }
        }
        if(curr.n > 0 && curr.s < S){
            delta = min(curr.n,S - curr.s);
            next.n = curr.n - delta;
            next.s = curr.s + delta;
            if(!searched[next.s][next.n]){
                if(balance(next.s,next.n))
                    return curr.time + 1;
                searched[next.s][next.n] = true;
                next.time = curr.time + 1;
                Q.push(next);
            }
        }
        if(curr.n > 0 && m < M){
            delta = min(curr.n,M - m);
            next.n = curr.n - delta;
            next.s = curr.s;
            if(!searched[next.s][next.n]){
                if(balance(next.s,next.n))
                    return curr.time + 1;
                searched[next.s][next.n] = true;
                next.time = curr.time + 1;
                Q.push(next);
            }
        }
        if(m > 0 && curr.s < S){
            delta = min(m,S - curr.s);
            next.s = curr.s + delta;
            next.n = curr.n;
            if(!searched[next.s][next.n]){
                if(balance(next.s,next.n))
                    return curr.time + 1;
                searched[next.s][next.n] = true;
                next.time = curr.time + 1;
                Q.push(next);
            }
        }
        if(m > 0 && curr.n < N){
            delta = min(m,N - curr.n);
            next.n = curr.n + delta;
            next.s = curr.s;
            if(!searched[next.s][next.n]){
                if(balance(next.s,next.n))
                    return curr.time + 1;
                searched[next.s][next.n] = true;
                next.time = curr.time + 1;
                Q.push(next);
            }
        }
    }
    return -1;
}
int main(){
    while(cin>>S>>N>>M){
        if(S == 0 && N == 0 && M == 0)
            break;
        if(S % 2 != 0){
            cout<<"NO"<<endl;
            continue;
        }
        vector<vector<bool> > searched(S + 1,vector<bool>(N + 1,false));
        int rs = BFS(searched);
        if(rs >= 0)
            cout<<rs;
        else
            cout<<"NO";
        cout<<endl;
    }
}