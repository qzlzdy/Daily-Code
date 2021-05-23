#include<iostream>
#include<vector>
using namespace std;
int main(){
    int target;
    while(cin>>target)
    {
        vector<int> arr;
        int tarMark,tempID,tempM;
        cin>>tempID>>tempM;
        while(tempID != 0 || tempM != 0)
        {
            if(tempID != target)
                arr.push_back(tempM);
            else
                tarMark = tempM;
            cin>>tempID>>tempM;
        }
        int rank = 0;
        for(int i = 0; i < arr.size(); i++)
        {
            if(arr[i] > tarMark)
                rank++;
        }
        cout<<rank+1<<endl;
    }
    return 0;
}