#include <iostream>

using namespace std;

int main(){
    int N,M;
    string currID,openID,closeID,openTime,closeTime,currTime;
    cin>>N;
    while(N > 0){
        cin>>M;
        closeTime = "00:00:00";
        openTime = "23:59:59";
        while(M > 0){
            cin>>currID>>currTime;
            if(currTime <= openTime){
                openTime = currTime;
                openID = currID;
            }
            cin>>currTime;
            if(currTime >= closeTime){
                closeTime = currTime;
                closeID = currID;
            }
            M--;
        }
        cout<<openID<<" "<<closeID<<endl;
        N--;
    }
}