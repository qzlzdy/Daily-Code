//============================================================================
// Name        : HDOJ_2446.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : Shell Pyramid
//============================================================================
#include <iostream>
using namespace std;
long long fi(long long i){
    return i * (i - 1) / 2 * (i + 1) / 3;
}
long long fj(long long j){
    return j * (j - 1) / 2;
}
int main(){
    int n;
    cin>>n;
    while(n--){
        long long s;
        cin>>s;
        long long i,j,k;
        int l = 0,r = 1e7;
        while(true){
            int mid = (r + l) / 2;
            if(fi(mid) >= s)
                r = mid;
            else if(fi(mid + 1) < s)
                l = mid + 1;
            else{
                l = mid;
                break;
            }
        }
        i = l;
        s -= fi(i);
        //cout<<s<<" "<<fi(i)<<endl;
        l = 0;
        r = i;
        while(true){
            int mid = (r + l) / 2;
            if(fj(mid) >= s)
                r = mid;
            else if(fj(mid + 1) < s)
                l = mid + 1;
            else{
                l = mid;
                break;
            }
        }
        j = l;
        k = s - fj(j);
        //cout<<k<<" "<<fj(j)<<endl;
        cout<<i<<" "<<j<<" "<<k<<endl;
    }
}