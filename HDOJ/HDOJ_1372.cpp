//============================================================================
// Name        : HDOJ_1372.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : Knight Moves
//============================================================================
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cstdio>
using namespace std;
int const X = 0;
int const Y = 1;
int const SIZE = 8;
vector<vector<int> > const order{{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1}};
bool isBoard(int x,int y){
    return x >= 0 && x < SIZE && y >= 0 && y < SIZE;
}
int main(){
    char sx,sy,ex,ey;
    while(cin>>sx>>sy>>ex>>ey){
        sx -= 'a';
        ex -= 'a';
        sy -= '1';
        ey -= '1';
        queue<vector<int> > Q;
        vector<vector<int> > board(8,vector<int>(8,-1));
        board[sx][sy] = 0;
        Q.push({sx,sy});
        while(!Q.empty()){
            vector<int> curr = Q.front();
            Q.pop();
            if(curr[X] == ex && curr[Y] == ey)
                break;
            int nextx,nexty;
            for(int i = 0; i < SIZE; i++){
                nextx = curr[X] + order[i][X];
                nexty = curr[Y] + order[i][Y];
                if(isBoard(nextx,nexty) && board[nextx][nexty] == -1){
                    Q.push({nextx,nexty});
                    board[nextx][nexty] = board[curr[X]][curr[Y]] + 1;
                }
            }
        }
        printf("To get from %c%c to %c%c takes %d knight moves.\n",
                sx+'a',sy+'1',ex+'a',ey+'1',board[ex][ey]);
    }
}