#include<iostream>

using namespace std;

class Time{
public:
    Time(int h,int m,int s);
    Time& operator+(const Time& t);
    friend ostream& operator<<(ostream& os,const Time& t);
private:
    int hour;
    int min;
    int sec;
};

Time::Time(int h,int m,int s){
    hour = h;
    min = m;
    sec = s;
}

Time& Time::operator+(const Time& t){
    int h,m,s;
    s = m = h = 0;
    s += sec + t.sec;
    while(s >= 60){
        s -= 60;
        m++;
    }
    m += min + t.min;
    while(m >= 60){
        m -= 60;
        h++;
    }
    h += hour + t.hour;
    Time *t3 = new Time(h,m,s);
    return *t3;
}

ostream& operator<<(ostream& os,const Time& t){
    os<<t.hour<<" "<<t.min<<" "<<t.sec;
    return os;
}

int main(){
    int N;
    cin>>N;
    while(N > 0){
        int h,m,s;
        cin>>h>>m>>s;
        Time t1(h,m,s);
        cin>>h>>m>>s;
        Time t2(h,m,s);
        cout<<t1 + t2<<endl;
        N--;
    }
    return 0;
} 