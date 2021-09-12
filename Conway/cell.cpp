#include "cell.h"

#include <random>

using namespace std;

unsigned Cell::getPopulation(){
    return Population;
}

Cell::Cell() : IsAlive(false){
    ++Population;
}

Cell::~Cell(){
    --Population;
}

void Cell::birth(bool init){
    IsAlive = true;
    Age = 0;
    static random_device rd;
    static mt19937_64 gen(rd());
    static bernoulli_distribution d(0.5);
    Sex = d(gen) ? Male : Female;
    if(init){
        Character = 0;
        for(int i = 0; i < 64; ++i){
            Character |= d(gen);
            Character <<= 1;
        }
    }
}

void Cell::birth(const Cell &Father, const Cell &Mother){
    birth(false);
    Character = Father.Character ^ Mother.Character;
}

void Cell::die(){
    IsAlive = false;
}

unsigned Cell::getAge() const{
    return Age;
}

Cell::Gender Cell::getSex() const{
    return Sex;
}

void Cell::grow(){
    if(IsAlive){
        ++Age;
        if(Age == Lifespan){
            die();
        }
    }
}

bool Cell::isAlive() const{
    return IsAlive;
}

bool Cell::isFertile() const{
    return MinChildbirthAge <= Age && Age <= MaxChildbirthAge;
}

const unsigned Cell::Lifespan = 20;

const unsigned Cell::MinChildbirthAge = 4;

const unsigned Cell::MaxChildbirthAge = 12;

unsigned Cell::Population = 0;
