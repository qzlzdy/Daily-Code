//============================================================================
// Name        : HDOJ_1052.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : Tian Ji -- The Horse Racing
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
int main(){
    int n;
    while(cin>>n){
        if(n == 0)
            break;
        vector<int> tian,king;
        int speed;
        for(int i = 0; i < n; i++){
            cin>>speed;
            tian.push_back(speed);
        }
        for(int i = 0; i < n; i++){
            cin>>speed;
            king.push_back(speed);
        }
        sort(tian.rbegin(),tian.rend());
        sort(king.rbegin(),king.rend());
        vector<int>::iterator tf = tian.begin();
        vector<int>::iterator kf = king.begin();
        vector<int>::iterator ts = tian.end() - 1;
        vector<int>::iterator ks = king.end() - 1;
        int count = 0;
        while(tf <= ts){
            if(*tf > *kf){
                tf++;
                kf++;
                count++;
            }else if(*tf < *kf){
                kf++;
                ts--;
                count--;
            }else{
                if(*ts > *ks){
                    ks--;
                    ts--;
                    count++;
                }else{
                    if(*kf > *ts)
                        count--;
                    kf++;
                    ts--;
                }
            }
        }
        cout<<count * 200<<endl;
    }
}
