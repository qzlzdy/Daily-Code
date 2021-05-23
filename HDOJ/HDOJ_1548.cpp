//============================================================================
// Name        : HDOJ_1548.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : A strange lift
//============================================================================
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Floor{
public:
    Floor(int ki);
    bool visited;
    int k;
    int step;
};
Floor::Floor(int ki){
    visited = false;
    k = ki;
    step = -1;
}
int main(){
    int N,A,B,t;
    while(cin>>N){
        if(N == 0)
            break;
        cin>>A>>B;
        vector<Floor> floors;
        for(int i = 0; i < N; i++){
            cin>>t;
            floors.push_back(Floor(t));
        }
        queue<int> Q;
        floors[A - 1].step = 0;
        Q.push(A - 1);
        while(!Q.empty()){
            int f = Q.front();
            Q.pop();
            if(f == B - 1)
                break;
            floors[f].visited = true;
            int next = f - floors[f].k;
            if(next >= 0 && !floors[next].visited){
                if(floors[next].step == -1 || floors[next].step > floors[f].step + 1)
                    floors[next].step = floors[f].step + 1;
                Q.push(next);
            }
            next = f + floors[f].k;
            if(next < N && !floors[next].visited){
                if(floors[next].step == -1 || floors[next].step > floors[f].step + 1)
                    floors[next].step = floors[f].step + 1;
                Q.push(next);
            }
        }
        cout<<floors[B - 1].step<<endl;
    }
}