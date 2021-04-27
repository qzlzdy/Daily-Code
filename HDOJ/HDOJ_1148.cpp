//============================================================================
// Name        : HDOJ_1144.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : Prerequisites?
//============================================================================
#include <iostream>
#include <map>
#include <string>
#include <iomanip>
using namespace std;
class Player{
public:
    Player();
    void win();
    void lose();
    bool noplay();
    double average();
private:
    int w,l;
};
Player::Player(){
    w = l = 0;
}
void Player::win(){
    w++;
}
void Player::lose(){
    l++;
}
bool Player::noplay(){
    return w == 0 && l == 0;
}
double Player::average(){
    return 1.0 * w / (w + l);
}
bool win(string &m1,string &m2){
    if(m1 == "rock")
        return m2 == "scissors";
    else if(m1 == "scissors")
        return m2 == "paper";
    else
        return m2 == "rock";
}
int main(){
    int n,k;
    bool cnt = false;
    while(cin>>n){
        if(n == 0)
            break;
        cin>>k;
        if(cnt)
            cout<<endl;
        cnt = true;
        map<int,Player> players;
        int p1,p2;
        string m1,m2;
        while(k-- > 0){
            cin>>p1>>m1>>p2>>m2;
            if(m1 != m2){
                if(win(m1,m2)){
                    players[p1].win();
                    players[p2].lose();
                }else{
                    players[p2].win();
                    players[p1].lose();
                }
            }
        }
        for(int i = 1; i <= n; i++){
            if(players[i].noplay())
                cout<<'-'<<endl;
            else
                cout<<fixed<<setprecision(3)<<players[i].average()<<endl;
        }
    }
}
