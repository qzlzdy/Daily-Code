#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

class Students{
public:
    Students(){};
    Students(string id,string name,int score);
    friend bool sortById(const Students& a,const Students& b);
    friend bool sortByName(const Students& a,const Students& b);
    friend bool sortByScore(const Students& a,const Students& b);
    friend ostream& operator<<(ostream& out,const Students& stu);
    //Students& operator=(const Students& newstu);
private:
    string id;
    string name;
    int score;
};

Students::Students(string id,string name,int score){
    this->id = id;
    this->name = name;
    this->score = score;
}
/*
Students& Students::operator=(const Students& newstu){
    id = newstu.id;
    name = newstu.name;
    score = newstu.score;
    return *this;
}
*/
bool sortById(const Students& a,const Students& b){
    return a.id < b.id;
}

bool sortByName(const Students& a,const Students& b){
    if(a.name != b.name)
        return a.name < b.name;
    else
        return a.id < b.id;
}

bool sortByScore(const Students& a,const Students& b){
    if(a.score != b.score)
        return a.score < b.score;
    else
        return a.id < b.id;
}

void excelSort(Students *begin,Students *end,int C){
    if(C == 1)
        sort(begin,end,sortById);
    else if(C == 2)
        sort(begin,end,sortByName);
    else
        sort(begin,end,sortByScore);
}

ostream& operator<<(ostream& out,const Students& stu){
    out<<stu.id<<" "<<stu.name<<" "<<stu.score;
    return out;
}

int main(){
    int N,C;
    int count = 1;
    while(cin>>N,N != 0){
        cin>>C;
        string id,name;
        int score;
        Students *stus = new Students[N];
        for(int i = 0; i < N; i++){
            cin>>id>>name>>score;
            stus[i] = Students(id,name,score);
        }
        excelSort(stus,stus + N,C);
        cout<<"Case "<<count<<":"<<endl;
        count++;
        for(int i = 0; i < N; i++)
            cout<<stus[i]<<endl;
        delete[] stus;
    } 
    return 0;
}