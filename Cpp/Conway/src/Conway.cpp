#include <Conway.h>

#include <algorithm>
#include <cstring>
#include <random>

using namespace std;

Conway::Conway(unsigned width, unsigned height) : world(height, vector<Cell *>(width, nullptr)){
    this->width = width;
    this->height = height;
    init();
}

Conway::~Conway(){
    for(auto &row : world){
        for(auto &cell : row){
            if(cell){
                delete cell;
            }
        }
    }
}

void Conway::step(){
    vector<vector<unsigned char> > count(height, vector<unsigned char>(width, 0));
    for(unsigned i = 0; i < height; ++i){
        for(unsigned j = 0; j < width; ++j){
            if(!world[i][j]){
                continue;
            }
            bool ineg = i > 0;
            bool ipos = i + 1 < height;
            bool jneg = j > 0;
            bool jpos = j + 1 < width;
            if(ineg && jneg){
                ++count[i - 1][j - 1];
            }
            if(ineg){
                ++count[i - 1][j];
            }
            if(ineg && jpos){
                ++count[i - 1][j + 1];
            }
            if(jneg){
                ++count[i][j - 1];
            }
            if(jpos){
                ++count[i][j + 1];
            }
            if(ipos && jneg){
                ++count[i + 1][j - 1];
            }
            if(ipos){
                ++count[i + 1][j];
            }
            if(ipos && jpos){
                ++count[i + 1][j + 1];
            }
        }
    }
    for(unsigned i = 0; i < height; ++i){
        for(unsigned j = 0; j < width; ++j){
            if(!world[i][j] && count[i][j] == 3){
                world[i][j] = new Cell(time);
            }
            else if(world[i][j] && (count[i][j] < 2 || count[i][j] > 3)){
                delete world[i][j];
                world[i][j] = nullptr;
            }
        }
    }
    ++time;
}

ostream &operator<<(ostream &out, Conway &conway){
    out << "\033[2J";
    for(auto &row : conway.world){
        for(auto &cell : row){
            if(cell){
                out << "\033[47m \033[0m";
            }
            else{
                out << "\033[40m \033[0m";
            }
        }
        out << endl;
    }
    out << "BirthCount " << Cell::getBirthCount() << "\tDeathCount " << Cell::getDeathCount();
    return out;
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
