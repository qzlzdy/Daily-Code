//============================================================================
// Name        : HDOJ_1056.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : HangOver
//============================================================================
#include <iostream>
#include <vector>
using namespace std;
int main(){
    double c;
    vector<double> len{0.5};
    while(cin>>c){
        if(c == 0.00)
            break;
        int num;
        double sum = len[len.size() - 1];
        if(sum < c){
            int i = len.size() + 2;
            do{
                sum += 1.0 / i;
                i++;
                len.push_back(sum);
            }while(sum < c);
            num = len.size();
        }else{
            num = 1;
            while(len[num - 1] < c)
                num++;
        }
        cout<<num<<" card(s)"<<endl;
    }
}
