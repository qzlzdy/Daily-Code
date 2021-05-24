#include <iostream>
#include <queue>
#include <algorithm>
#include <iterator>
using namespace std;
int main(){
    int M;
    cin>>M;
    for(int i = 0; i < M; i++){
        int N,t;
        cin>>N;
        deque<int> Q;
        for(int j = 0; j < N; j++)
            Q.push_back((cin>>t,t));
        sort(Q.begin(),Q.end());
        int sum = 0;
        while(Q.size() > 1){
            sum += Q.back() - Q.front();
            Q.pop_front();
            Q.pop_back();
        }
        cout<<sum<<endl;
    }
} 