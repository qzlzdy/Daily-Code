//============================================================================
// Name        : HDOJ_1201.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : 18岁生日
//============================================================================
#include <cstdio>
#include <string>
using namespace std;

bool isLeap(int year){
    if(year % 400 == 0)
        return true;
    if(year % 4 == 0 && year % 100 != 0)
        return true;
    return false;
}

int main(){
    int T;
    scanf(" %d", &T);
    while(T-- > 0){
        int y, m, d;
        scanf(" %d-%d-%d", &y, &m, &d);
        if(m >= 3)
            y++;
        int sum = 0;
        for(int i = 0; i < 18; i++){
            if(isLeap(y))
                sum += 366;
            else
                sum += 365;
            y++;
        }
        if(m == 2 && d == 29 && !isLeap(y))
            sum = -1;
        printf("%d\n", sum);
    }
}
