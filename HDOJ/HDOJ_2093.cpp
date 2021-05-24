#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;
class Data{
public:
    string name;
    int count;
    int time;
    Data(string name,int n,int m);
};
Data::Data(string name,int n,int m):name(name){
    string buff;
    count = 0;
    time = 0; 
    for(int i = 0; i < n; i++){
        cin>>buff;
        if(buff[buff.length() - 1] == ')'){
            string fa = "";
            int i = buff.length() - 2;
            while(buff[i] != '(')
                fa = buff[i--] + fa;
            time += (atoi(buff.substr(0,i).c_str()) + m * atoi(fa.c_str()));
            count++;
        }
        else if(atoi(buff.c_str()) > 0){
            time += atoi(buff.c_str());
            count++;
        }
    }
    if(count == 0)
        time = 0;
}
bool ranks(Data &a,Data& b){
    if(a.count != b.count)
        return a.count > b.count;
    if(a.time != b.time)
        return a.time < b.time;
    return a.name < b.name;
}
int main(){
    int n,m;
    cin>>n>>m;
    string name;
    vector<Data> vec;
    while(cin>>name)
        vec.push_back(Data(name,n,m));
    sort(vec.begin(),vec.end(),ranks);
    for(int i = 0; i < vec.size(); i++){
        cout<<setw(10)<<left<<vec[i].name;
        cout<<" "<<setw(2)<<right<<vec[i].count;
        cout<<" "<<setw(4)<<right<<vec[i].time<<endl;
    }
} 