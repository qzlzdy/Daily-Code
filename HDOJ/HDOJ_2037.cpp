#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>

using namespace std;

class Bangumi{
public:
    int begin;
    int end;
    Bangumi(){};
    Bangumi(int beg,int en);
    bool operator()(const Bangumi& a,const Bangumi &b)const;
};

Bangumi::Bangumi(int beg,int en){
    begin = beg;
    end = en;
}

bool Bangumi::operator()(const Bangumi& a,const Bangumi& b)const{
    return a.end < b.end;
}

int main(){
    int n;
    while(cin>>n,n != 0){
        vector<Bangumi> bgm;
        int beg,en;
        for(int i = 0; i < n; i++){
            cin>>beg>>en;
            bgm.push_back(Bangumi(beg,en));
        }
        sort(bgm.begin(),bgm.end(),Bangumi());
        int last = 0;
        int sum = 0;
        vector<Bangumi>::iterator it = bgm.begin();
        while(it != bgm.end()){
            if((*it).begin >= last){
                sum++;
                last = (*it).end;
            }
            it++;
        }
        cout<<sum<<endl;
    }
    return 0;
} 