//============================================================================
// Name        : HDOJ_1253.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : 胜利大逃亡
//============================================================================
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int const X = 0;
int const Y = 1;
int const Z = 2;
vector<vector<int> > const order = {{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};
int const SIZE = 6;
int A,B,C,T;
bool inside(int x,int y,int z){
    return x >= 0 && x < A && y >= 0 && y < B && z >= 0 && z < C;
}
class Point{
public:
    Point(int pos_x,int pos_y,int pos_z);
    short x,y,z;
    short time;
};
Point::Point(int pos_x,int pos_y,int pos_z){
    x = pos_x;
    y = pos_y;
    z = pos_z;
    time = 0;
}
Point nex(0,0,0);
int BFS(vector<vector<vector<bool> > >& visited){
    if(A == 1 && B == 1 && C == 1)
        return 0;
    queue<Point> Q;
    Point start(0,0,0);
    start.time = 0;
    Q.push(start);
    while(!Q.empty()){
        Point curr = Q.front();
        Q.pop();
        for(int i = 0; i < SIZE; i++){
            nex.x = curr.x + order[i][X];
            nex.y = curr.y + order[i][Y];
            nex.z = curr.z + order[i][Z];
            if(inside(nex.x,nex.y,nex.z) && !visited[nex.x][nex.y][nex.z] && nex.time < T){
                if(nex.x == A-1 && nex.y == B-1 && nex.z == C-1)
                    return curr.time + 1;
                nex.time = curr.time + 1;
                Q.push(nex);
                visited[nex.x][nex.y][nex.z] = true;
            }
        }
    }
    return -1;
}
int main(){
    int K;
    scanf("%d",&K);
    while(K--){
        scanf("%d%d%d%d",&A,&B,&C,&T);
        vector<vector<vector<bool> > > visited;
        int t;
        for(int i = 0; i < A; i++){
            vector<vector<bool> > plane;
            for(int j = 0; j < B; j++){
                vector<bool> row;
                for(int k = 0; k < C; k++){
                    scanf("%d",&t);
                    row.push_back(t);
                }
                plane.push_back(row);
            }
            visited.push_back(plane);
        }
        cout<<BFS(visited)<<endl;
    }
}