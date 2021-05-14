#include <Conway.h>

#include <chrono>
#include <iostream>
#include <random>
#include <thread>

using namespace std;

Conway::Conway(unsigned width, unsigned height) : root(&root){
    world = vector<vector<Cell> >(height, vector<Cell>(width));
    count = vector<vector<unsigned char> >(height, vector<unsigned char>(width));
    this->height = height;
    this->width = width;
}

void Conway::run(){
    while(true){
        print();
	countAliveCell();
        evolve();
        this_thread::sleep_for(100ms);
    }
}

void Conway::init(){
    random_device rd;
    mt19937 gen(rd());
    bernoulli_distribution d(0.375);
    for(unsigned i = 0; i < height; ++i){
        for(unsigned j = 0; j < width; ++j){
            world[i][j] = d(gen) ? Cell(&root) : Cell();
        }
    }
}

void Conway::print(){
    for(auto &row : world){
        for(auto &cell : row){
            cout << " #"[cell.isAlive()];
        }
        cout << endl;
    }
}

void Conway::countAliveCell(){
    for(auto &row : count){
        for(auto &element : row){
            element = 0;
        }
    }
    for(unsigned i = 0; i < height; ++i){
        for(unsigned j = 0; j < width; ++j){
            if(!world[i][j].isAlive()){
                continue;
            }
            bool u = i > 0;
            bool b = i + 1 < height;
            bool l = j > 0;
            bool r = j + 1 < width;
            if(u && l){
                ++count[i - 1][j - 1];
            }
            if(u){
                ++count[i - 1][j];
            }
            if(u && r){
                ++count[i - 1][j + 1];
            }
            if(l){
                ++count[i][j - 1];
            }
            if(r){
                ++count[i][j + 1];
            }
            if(b && l){
                ++count[i + 1][j - 1];
            }
            if(b){
                ++count[i + 1][j];
            }
            if(b && r){
                ++count[i + 1][j + 1];
            }
        }
    }
}

void Conway::evolve(){
    for(unsigned i = 0; i < height; ++i){
        for(unsigned j = 0; j < width; ++j){
            if(world[i][j].isAlive() && (count[i][j] < 2 || count[i][j] > 3)){
                world[i][j] = Cell();
            }
            else if(!world[i][j].isAlive() && count[i][j] == 3){
                world[i][j] = Cell(&root);
            }
        }
    }
}
