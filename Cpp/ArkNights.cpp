#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){
    // P{X = k}: 前k-1次不中，第k次中 (0 < k <= 100)
    double P_X[99];
    double item = 1;
    const double NE_F = pow(0.98, 50);  // 0.98 ** 50;
    double Sum = 0;
    unsigned MaxIndex = 1;
    for(unsigned i = 1; i <= 99; ++i){
        if(i <= 50){
            P_X[i - 1] = pow(0.98, i - 1) * 0.02;
        }
        else{
            P_X[i - 1] = NE_F * (0.02 * i - 0.98) * item;
            item *= 1.98 - 0.02 * i;
        }
        
        cout << "P{X = " << i << " } = " << scientific << setprecision(6) << P_X[i - 1] << endl;
        Sum += P_X[i - 1];
        if(P_X[i - 1] > P_X[MaxIndex - 1]){
            MaxIndex = i;
        }
    }
    cout << "Sum: " << Sum << endl;
    cout << "Max P: " << MaxIndex << " --- " << scientific << setprecision(6) << P_X[MaxIndex - 1] << endl;
    return 0;
}
