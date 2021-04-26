#include<iostream>
using namespace std;
int main(){
    int T,N;
    cin>>T;
    while(T > 0)
    {
        cin>>N;
        int A[N];
        for(int i = 0; i < N; i++)
            cin>>A[i];
        for(int i = 0; i < N - 1; i++)
        {
            int min = A[i];
            int k = i;
            for(int j = i + 1; j < N; j++)
            {
                if(A[j] < min)
                {
                    min = A[j];
                    k = j;
                }
            }
            if(k != i)
            {
                A[k] = A[i];
                A[i] = min;
            }
        }
        for(int i = 0; i < N - 1; i++)
        {
            cout<<A[i]<<" ";
        }
        cout<<A[N - 1]<<endl;
        T--;
    } 
    return 0;
}
