//============================================================================
// Name        : HDOJ_1035.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : Robot Motion
//============================================================================
#include <iostream>
#include <vector>
using namespace std;
const int E = -1;
const int S = -2;
const int W = -3;
const int N = -4;
int r,c,e;
bool inMap(int x,int y)
{
    if(x < 0 || x >= r)
        return false;
    if(y < 0 || y >= c)
        return false;
    return true;
}
int main(){
    while(cin>>r>>c)
    {
        if(r == 0 && c == 0)
            break;
        cin>>e;
        vector<vector<int> > map(r,vector<int>(c));
        for(auto &row : map)
        {
            for(auto &it : row)
            {
                char comp;
                cin>>comp;
                switch(comp)
                {
                case 'E':
                    it = E;
                    break;
                case 'S':
                    it = S;
                    break;
                case 'W':
                    it = W;
                    break;
                case 'N':
                    it = N;
                    break;
                }
            }
        }
        int x = 0,y = e - 1,step = 0;
        while(inMap(x,y) && map[x][y] < 0)
        {
            int comp = map[x][y];
            map[x][y] = step++;
            switch(comp)
            {
            case E:
                y++;
                break;
            case S:
                x++;
                break;
            case W:
                y--;
                break;
            case N:
                x--;
                break;
            }
        }
        if(!inMap(x,y))
            cout<<step<<" step(s) to exit"<<endl;
        else
            cout<<map[x][y]<<" step(s) before a loop of "<<step - map[x][y]<<" step(s)"<<endl;
    }
}
