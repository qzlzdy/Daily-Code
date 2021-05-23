//============================================================================
// Name        : HDOJ_1789.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : Doing Homework again
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Subject{
public:
    int deadline;
    int reduce;
};
bool cmp(Subject& A,Subject& B){
    if(A.reduce == B.reduce)
        return A.deadline < B.deadline;
    return A.reduce > B.reduce;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        vector<Subject> arr(N,Subject());
        for(int i = 0; i < N; i++)
            cin>>arr[i].deadline;
        for(int i = 0; i < N; i++)
            cin>>arr[i].reduce;
        sort(arr.begin(),arr.end(),cmp);
        int score = 0;
        vector<int> tab(N,0);
        for(vector<Subject>::iterator it = arr.begin(); it != arr.end(); it++){
            if(it->deadline > N || tab[it->deadline - 1] >= it->deadline){
                int i = N - 1;
                for( ; tab[i - 1] < tab[i]; i--)
                    tab[i]++;
                tab[i]++;
                if(it->deadline <= N)
                    score += it->reduce;
            }else{
                int i = it->deadline - 1;
                for( ; i > 0 && tab[i - 1] < tab[i]; i--)
                    tab[i]++;
                tab[i]++;
                for(i = it->deadline; i < N; i++)
                    tab[i]++;
            }
        }
        cout<<score<<endl;
    }
}