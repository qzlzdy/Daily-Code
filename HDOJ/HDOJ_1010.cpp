//============================================================================
// Name        : HDOJ_1010.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : Tempter of the Bone
//============================================================================
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<vector<char> > map;
vector<vector<bool> > searched;
int N,M;
int startX, startY, endX, endY;
bool passable(int x, int y){
    if(x < 0 || x >= N)
        return false;
    if(y < 0 || y >= M)
        return false;
    return map[x][y] == '.';
}
bool DFS(int T, int currX, int currY){
    if(currX == endX && currY == endY)
        return T == 0;
    int sum = T - abs(endX - currX) - abs(endY - currY);
    if(sum < 0 || sum % 2 == 1)
        return false;
    searched[currX][currY] = true;
    int nextX, nextY;

    nextX = currX - 1;
    nextY = currY;
    if(passable(nextX, nextY) && !searched[nextX][nextY] && DFS(T - 1, nextX, nextY))
        return true;

    nextX = currX + 1;
    nextY = currY;
    if(passable(nextX, nextY) && !searched[nextX][nextY] && DFS(T - 1, nextX, nextY))
        return true;

    nextX = currX;
    nextY = currY - 1;
    if(passable(nextX, nextY) && !searched[nextX][nextY] && DFS(T - 1, nextX, nextY))
        return true;

    nextX = currX;
    nextY = currY + 1;
    if(passable(nextX, nextY) && !searched[nextX][nextY] && DFS(T - 1, nextX, nextY))
        return true;

    searched[currX][currY] = false;
    return false;
}
int main(){
    int T;
    while(cin>>N>>M>>T){
        if(M == 0 && N == 0 && T == 0)
            break;
        map = vector<vector<char> >(N, vector<char>(M));
        searched = vector<vector<bool> >(N, vector<bool>(M, false));
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                cin>>map[i][j];
                if(map[i][j] == 'S'){
                    startX = i;
                    startY = j;
                }else if(map[i][j] == 'D'){
                    endX = i;
                    endY = j;
                    map[i][j] = '.';
                }
            }
        }
        if(DFS(T, startX, startY))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}
