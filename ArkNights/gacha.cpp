#include <array>
#include <iomanip>
#include <iostream>
#include <mutex>
#include <vector>

using namespace std;

// 六星出率
static double getSixProb(int Count){
    if(Count <= 50){
        return 0.02;
    }
    return 0.02 * Count - 0.98;
}

// 第X首次出六星
static double getFirstSixProb(int Count){
    static array<double, 99> FirstProb;
    static bool InitFirstProb = false;
    if(InitFirstProb){
        return FirstProb[Count - 1];
    }
    double t = 1;
    for(int i = 1; i < 100; ++i){
        FirstProb[i - 1] = t * getSixProb(i);
        t *= 1 - getSixProb(i);
    }
    InitFirstProb = true;
    return FirstProb[Count - 1];
}

// 第Y首次出限定
static double getFirstSpecProb(int Count, double a){
    static array<double, 299> FirstProb;
    static bool InitFirstProb = false;
    if(InitFirstProb){
        return FirstProb[Count - 1];
    }
    for(int i = 1; i < 300; ++i){
        double prob = 0;
        for(int j = 1; j < 100 && i - j > 0; ++j){
            prob += FirstProb[i - j - 1] * getFirstSixProb(j);
        }
        prob *= 1 - a;
        prob += i < 99 ? getFirstSixProb(i) * a : 0;
        FirstProb[i - 1] = prob;
    }
    InitFirstProb = true;
    return FirstProb[Count - 1];
}

double E(vector<double> &Prob){
    double res = 0;
    for(int i = 0; i < Prob.size(); ++i){
        res += Prob[i] * (i + 1);
    }
    return res;
}

double D(vector<double> &Prob){
    double EX = E(Prob);
    double res = 0;
    for(int i = 0; i < Prob.size(); ++i){
        res += Prob[i] * (i - EX + 1) * (i - EX + 1);
    }
    return res;
}

int main(){
    vector<double> Prob(300);
    vector<double> Acc(300);
    double sum = 0;
    for(int i = 1; i < 300; ++i){
        Acc[i - 1] = sum;
        Prob[i - 1] = getFirstSpecProb(i, 0.35);
        sum += Prob[i - 1];
    }
    Acc[299] = 1;
    Prob[299] = 1 - sum;

    // Display
    for(int i = 0; i < 75; ++i){
        cout << "P{Y<" << 4 * i + 1 << "} = "
             << fixed << setprecision(6) << Acc[4 * i] << "\t";
        cout << "P{Y<" << 4 * i + 2 << "} = "
             << fixed << setprecision(6) << Acc[4 * i + 1] << "\t";
        cout << "P{Y<" << 4 * i + 3 << "} = "
             << fixed << setprecision(6) << Acc[4 * i + 2] << "\t";
        cout << "P{Y<" << 4 * i + 4 << "} = "
             << fixed << setprecision(6) << Acc[4 * i + 3];
        cout << endl;
    }
/*
    cout << "E(X) = " << fixed << setprecision(6) << E(Prob) << endl;
    cout << "D(X) = " << fixed << setprecision(6) << D(Prob) << endl;
*/
    return 0;
}
