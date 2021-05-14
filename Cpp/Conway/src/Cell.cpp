#include <Cell.h>

#include <algorithm>
#include <random>
#include <sstream>

using namespace std;

Cell::Cell(){
    alive = false;
    identifier = "";
    parent = nullptr;
}

Cell::Cell(Cell *parent){
    alive = true;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(33, 126);
    ostringstream buffer;
    for(int i = 0; i < 16; ++i){
        buffer << (char)dis(gen);
    }
    identifier = buffer.str();
    this->parent = parent->getParent();
}

string Cell::getIdentifier() const{
    return identifier;
}

Cell *Cell::getParent(){
    // if(parent != this){
    //     parent = parent->getParent();
    // }
    return parent;
}

bool Cell::isAlive() const{
    return alive;
}
