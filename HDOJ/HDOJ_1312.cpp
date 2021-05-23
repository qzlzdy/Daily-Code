//============================================================================
// Name        : HDOJ_1312.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : Red and Black
//============================================================================
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int> >const dect = {{1,0},{0,1},{-1,0},{0,-1}};
int const SIZE = 4;
int const X = 0;
int const Y = 1;
vector<vector<bool> > visited;
int H,W;
bool passable(int x,int y){
    return 0 <= x && x < H && 0 <= y && y < W && !visited[x][y];
}
class Point{
public:
    Point(int pos_x,int pos_y);
    int x,y;
};
Point::Point(int pos_x,int pos_y){
    x = pos_x;
    y = pos_y;
}
int main(){
    while(cin>>W>>H){
        if(H == 0 && W == 0)
            break;
        visited.clear();
        Point start(0,0);
        char t;
        for(int i = 0; i < H; i++){
            vector<bool> row;
            for(int j = 0; j < W; j++){
                cin>>t;
                if(t == '@'){
                    row.push_back(true);
                    start = Point(i,j);
                }else
                    row.push_back(t == '.' ? false : true);
            }
            visited.push_back(row);
        }
        queue<Point> Q;
        int sum = 1;
        Q.push(start);
        while(!Q.empty()){
            Point curr = Q.front();
            Q.pop();
            //cout<<curr.x<<" "<<curr.y<<endl;
            Point next(0,0);
            for(int i = 0; i < SIZE; i++){
                next.x = curr.x + dect[i][X];
                next.y = curr.y + dect[i][Y];
                if(passable(next.x,next.y)){
                    visited[next.x][next.y] = true;
                    sum++;
                    Q.push(next);
                }
            }
        }
        cout<<sum<<endl;
    }
}