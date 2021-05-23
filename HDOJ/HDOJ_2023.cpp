#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

int main(){
    int n,m,t;
    while(cin>>n>>m){
        vector<vector<int> > vec;
        double *cour = new double[m];
        double *aver = new double[n];
        bool *flag = new bool[n];
        for(int i = 0; i < m; i++)
            cour[i] = 0;
        for(int i = 0; i < n; i++){
            vector<int> temp;
            aver[i] = 0;
            flag[i] = true;
            for(int j = 0; j < m; j++){
                temp.push_back((cin>>t,t));
                aver[i] += t;
                cour[j] += t; 
            }
            aver[i] /= m;
            cout<<fixed<<setprecision(2)<<aver[i];
            if(i + 1 != n)
                cout<<" ";
            vec.push_back(temp);
        }
        cout<<endl;
        for(int i = 0; i < m; i++){
            cour[i] /= n;
            cout<<cour[i];
            if(i + 1 != m)
                cout<<" ";
            for(int j = 0; j < n; j++){
                if(vec[j][i] < cour[i])
                    flag[j] = false;
            }
        }
        cout<<endl;
        int sum = 0;
        for(int i = 0; i < n; i++)
            if(flag[i])
                sum++;
        cout<<sum<<endl;
        cout<<endl;
    }
    return 0;
}