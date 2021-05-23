//============================================================================
// Name        : HDOJ_1425.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : sort
//============================================================================
#include <cstdio>
#include <queue>
using namespace std;
int main(){
    int n,m,t;
    while(scanf("%d%d",&n,&m) == 2){
        priority_queue<int> Q;
        for(int i = 0; i < n; i++){
            scanf("%d",&t);
            Q.push(t);
        }
        for(int i = 0; i < m; i++){
            printf("%d",Q.top());
            Q.pop();
            if(i + 1 != m)
                printf(" ");
        }
        printf("\n");
    }
}