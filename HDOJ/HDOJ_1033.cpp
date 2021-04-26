//============================================================================
// Name        : HDOJ1033.cpp
// Author      : Qzlzdy
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================

#include <iostream>
#include <string>
using namespace std;
int const EAST = 0;
int const SOUTH = 1;
int const WEST = 2;
int const NORTH = 3;
class Compass{
public:
    Compass();
    ~Compass();
    void turn(char dect);
private:
    int _x,_y,_dect;
};
Compass::Compass(){
    _x = 310;
    _y = 420;
    _dect = EAST;
    cout<<"300 420 moveto"<<endl;
    cout<<"310 420 lineto"<<endl;
}
Compass::~Compass(){
    cout<<"stroke"<<endl;
    cout<<"showpage"<<endl;
}
void Compass::turn(char dect){
    if(dect == 'A')
        _dect = (_dect + 1) % 4;
    else
        _dect = (_dect + 3) % 4;
    switch(_dect){
    case EAST:
        _x += 10;
        break;
    case SOUTH:
        _y -= 10;
        break;
    case WEST:
        _x -= 10;
        break;
    case NORTH:
        _y += 10;
    }
    cout<<_x<<" "<<_y<<" lineto"<<endl;
}
int main(){
    string cmd;
    while(cin>>cmd){
        string::iterator cur = cmd.begin();
        Compass comp;
        while(cur != cmd.end())
            comp.turn(*(cur++));
    }
}
