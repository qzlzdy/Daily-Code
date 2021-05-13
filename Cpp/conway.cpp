#include <chrono>
#include <iostream>
#include <random>
#include <thread>
#include <vector>

using namespace std;

string symbol = "0123456798abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

class Conway{
public:
    Conway(unsigned width, unsigned height);
    void run();
    void init();
private:
    void print();
    void countAliveCell();
    void evolve();
    vector<vector<char> > world;
    vector<vector<char> > count;
    bool active;
    unsigned height;
    unsigned width;
    unsigned index;
};

Conway::Conway(unsigned width, unsigned height){
    world = vector<vector<char> >(height, vector<char>(width, ' '));
    count = vector<vector<char> >(height, vector<char>(width));
    active = true;
    this->height = height;
    this->width = width;
    index = 0;
}

void Conway::run(){
    do{
        print();
	countAliveCell();
        evolve();
        this_thread::sleep_for(250ms);
    }while(active);
}

void Conway::init(){
    random_device rd;
    mt19937 gen(rd());
    bernoulli_distribution d(0.05);
    for(unsigned i = 0; i < height; ++i){
        for(unsigned j = 0; j < width; ++j){
            world[i][j] = d(gen) ? '0' : ' ';
        }
    }
}

void Conway::print(){
    for(auto &row : world){
        for(auto &cell : row){
            cout << cell;
        }
        cout << endl;
    }
    cout << endl;
}

void Conway::countAliveCell(){
    for(auto &row : count){
        for(auto &element : row){
            element = 0;
        }
    }
    for(unsigned i = 0; i < height; ++i){
        for(unsigned j = 0; j < width; ++j){
            if(world[i][j] == ' '){
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
    active = false;
    index = (index + 1) % symbol.length();
    for(unsigned i = 0; i < height; ++i){
        for(unsigned j = 0; j < width; ++j){
            char origin = world[i][j];
            if(world[i][j] != ' ' && (count[i][j] < 2 || count[i][j] > 3)){
                world[i][j] = ' ';
            }
            else if(world[i][j] == ' ' && count[i][j] == 3){
                world[i][j] = symbol[index];
            }
            active |= origin != world[i][j];
        }
    }
}

int main(){
    Conway game(180, 50);
    game.init();
    game.run();
    return 0;
}
