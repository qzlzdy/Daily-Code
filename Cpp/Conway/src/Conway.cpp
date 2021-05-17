#include <Conway.h>

#include <algorithm>
#include <random>

using namespace std;

Conway::Conway(unsigned width, unsigned height) : world(width, vector<Cell *>(height, nullptr)){
    init();
}

Conway::~Conway(){
    for(auto &row : world){
        for(auto &cell : row){
            if(cell != nullptr){
                delete cell;
            }
        }
    }
}

void Conway::step(){

}

unsigned long long Conway::time = 0;

void Conway::init(){
    random_device rd;
    mt19937 gen(rd());
    bernoulli_distribution d(0.375);
    for(auto &row : world){
        for(auto &cell : row){
            if(d(gen)){
                cell = new Cell(-1);
            }
        }
    }
}
