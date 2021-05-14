#ifndef __CONWAY_H
#define __CONWAY_H

#include <Cell.h>

#include <vector>

class Conway{
public:
    Conway(unsigned width, unsigned height);
    void run();
    void init();
private:
    void print();
    void countAliveCell();
    void evolve();
    std::vector<std::vector<Cell> > world;
    std::vector<std::vector<unsigned char> > count;
    unsigned height;
    unsigned width;
    Cell root;
};

#endif // __COMWAY_H
