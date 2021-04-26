//============================================================================
// Name        : HDOJ1009.cpp
// Author      : Qzlzdy
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================

#include <iostream>
#include <vector>
#include <iomanip>
#include <iterator>
#include <algorithm>

using namespace std;

class Data{
public:
    int J, F;
    double rate;
    Data(int j, int f);
};

Data::Data(int j, int f){
    J = j;
    F = f;
    rate = 1.0 * f / j;
}

class cheaper{
public:
    bool operator()(Data &A, Data& B){
        return A.rate < B.rate;
    }
};

int main(){
    int M, N;
    while(cin >> M >> N){
        if(M == -1 && N == -1){
            break;
        }
        vector<Data> vec;
        int j, f;
        for(int i = 0; i < N; ++i){
            cin >> j >> f;
            vec.push_back(Data(j, f));
        }
        sort(vec.begin(), vec.end(), cheaper());
        double sum = 0;
        vector<Data>::iterator it = vec.begin();
        while(it != vec.end() && M > 0){
            if(M >= it->F){
                M -= it->F;
                sum += it->J;
                ++it;
            }
            else{
                sum += M / it->rate;
                M = 0;
            }
        }
        while(it != vec.end() && it->rate == 0){
            sum += it->J;
            ++it;
        }
        cout << fixed << setprecision(3) << sum << endl;
    }
}
