#include<iostream>
#include<string> 
#include<vector>
#include<cstdlib>
#include<algorithm>
using namespace std;
int main(){
    string str;
    while(cin>>str)
    {
        string buffer;
        vector<int> arr;
        int i = 0;
        while(i < str.length())
        {
            buffer.clear();
            while(i < str.length() && str[i] != '5')
                buffer += str[i++];
            if(!buffer.empty())
                arr.push_back(atoi(buffer.c_str()));
            i++;
        }
        sort(arr.begin(),arr.end());
        for(int i = 0; i < arr.size() - 1; i++)
            cout<<arr[i]<<" ";
        cout<<arr[arr.size() - 1]<<endl;
    }
    return 0;
}

