#include <array>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <mutex>
#include <vector>

using namespace std;

/**
 * @brief 计算六星出率
 * 
 * @param Count 当前连续未出六星的次数
 * 
 * @return 当次六星概率
 */
static double getSixProb(unsigned Count){
    if(Count <= 50){
        return 0.02;
    }
    return 0.02 * Count - 0.98;
}

/**
 * @brief 计算首次六星出率
 * 
 * @param Count 当前抽卡次数
 * 
 * @return 当次为首次六星概率
 */
once_flag InitFirstSixProb;
static double getFirstSixProb(unsigned Count){
    static array<double, 99> FirstSixProb;
    call_once(InitFirstSixProb, [&](){
        double t = 1;
        for(int i = 1; i < 100; ++i){
            FirstSixProb[i - 1] = t * getSixProb(i);
            t *= 1 - getSixProb(i);
        }
    });
    return FirstSixProb[Count - 1];
}

/**
 * @brief 计算首次限定出率
 * 
 * @param Count 当前抽卡次数
 * @param a     限定干员比重
 * 
 * @return 当次为首次限定概率
 */
once_flag InitFirstSpecProb;
static double getFirstSpecProb(unsigned Count, double a){
    static array<double, 299> FirstSpecProb;
    call_once(InitFirstSpecProb, [&](){
        for(size_t i = 1; i < 300; ++i){
            double prob = 0;
            for(int j = 1; j < 100 && i - j > 0; ++j){
                prob += FirstSpecProb[i - j - 1] * getFirstSixProb(j);
            }
            prob *= 1 - a;
            prob += i < 99 ? getFirstSixProb(i) * a : 0;
            FirstSpecProb[i - 1] = prob;
        }
    });
    return FirstSpecProb[Count - 1];
}

/**
 * @brief 计算随机变量的数学期望
 * 
 * @param Prob 概率分布，仅支持有限离散型随机变量
 * @return 数学期望
 */
double E(vector<double> &Prob){
    double res = 0;
    for(size_t i = 0; i < Prob.size(); ++i){
        res += Prob[i] * (i + 1);
    }
    return res;
}

/**
 * @brief 计算随机变量的方差
 * 
 * @param Prob 概率分布，仅支持有限离散型随机变量
 * @return 方差
 */
double D(vector<double> &Prob){
    double EX = E(Prob);
    double res = 0;
    for(size_t i = 0; i < Prob.size(); ++i){
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
    cout << scientific;
    for(int i = 0; i < 300; ++i){
        cout << "P{Y == " << i + 1 << "} = " << Prob[i] << endl;
    }

    cout << "E(X) = " << E(Prob) << endl;
    cout << "D(X) = " << D(Prob) << endl;

    return EXIT_SUCCESS;
}
