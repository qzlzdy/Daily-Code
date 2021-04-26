//============================================================================
// Name        : HDOJ_1102.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : Constructing Roads
//============================================================================
#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int MAX = 0x7fffffff;

class Village{
public:
    Village(int i);
    int id;
    int key;
};

Village::Village(int i){
    id = i;
    key = MAX;
}

void minHeapify(vector<Village> &A, int i){
    unsigned l = 2 * i + 1;
    unsigned r = l + 1;
    int min = i;
    if(l < A.size() && A[l].key < A[i].key)
        min = l;
    if(r < A.size()&& A[r].key < A[min].key)
        min = r;
    if(min != i){
        Village V = A[i];
        A[i] = A[min];
        A[min] = V;
        minHeapify(A, min);
    }
}

void buildMinHeap(vector<Village> &A){
    for(int i = (A.size() - 1)/ 2; i >= 0; i--)
        minHeapify(A, i);
}

int main(){
    int N, Q;
    while(cin>>N){
        vector<vector<int> > map(N, vector<int>(N));
        vector<Village> vills;
        for(int i = 0; i < N; i++)
            vills.push_back(Village(i));
        for(auto &row : map)
            for(auto &it : row)
                cin>>it;
        cin>>Q;
        int a, b;
        for(int i = 0; i < Q; i++){
            cin>>a>>b;
            map[a - 1][b - 1] = map[b - 1][a - 1] = 0;
        }
        int sum = 0;
        vills[0].key = 0;
        set<int> S;
        while(vills.size() > 0){
            buildMinHeap(vills);
            Village V = vills[0];
            vills.erase(vills.begin());
            S.insert(V.id);
            for(auto &it : vills){
                if(S.find(it.id) == S.end() && map[V.id][it.id] < it.key){
                    if(it.key != MAX)
                        sum -= it.key;
                    it.key = map[V.id][it.id];
                    sum += it.key;
                }
            }
        }
        cout<<sum<<endl;
    }
}
