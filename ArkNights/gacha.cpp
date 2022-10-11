#include <array>
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
const unsigned MAX_GACHA_NB = 300;
once_flag InitFirstSpecProb;
static double getFirstSpecProb(unsigned Count, double a){
    static array<double, MAX_GACHA_NB - 1> FirstSpecProb;
    call_once(InitFirstSpecProb, [&](){
        for(int i = 1; i < MAX_GACHA_NB; ++i){
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
    for(int i = 0; i < Prob.size(); ++i){
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
    for(int i = 0; i < Prob.size(); ++i){
        res += Prob[i] * (i - EX + 1) * (i - EX + 1);
    }
    return res;
}

int main(){
    vector<double> Prob(MAX_GACHA_NB);
    vector<double> Acc(MAX_GACHA_NB);
    double sum = 0;
    for(int i = 1; i < MAX_GACHA_NB; ++i){
        Acc[i - 1] = sum;
        Prob[i - 1] = getFirstSpecProb(i, 0.35);
        sum += Prob[i - 1];
    }
    Acc[MAX_GACHA_NB - 1] = 1;
    Prob[MAX_GACHA_NB - 1] = 1 - sum;

    // Display
    cout << scientific;
    for(int i = 0; i < MAX_GACHA_NB; ++i){
        cout << "P{Y == " << i + 1 << "} = " << Prob[i] << endl;
    }

    cout << "E(X) = " << E(Prob) << endl;
    cout << "D(X) = " << D(Prob) << endl;

    return 0;
}
