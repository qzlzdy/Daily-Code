#ifndef __CONWAY_H
#define __CONWAY_H

#include <Cell.h>

#include <iostream>
#include <vector>

class Conway{
public:
    Conway(unsigned width, unsigned height);
    ~Conway();
    void step();
    friend std::ostream &operator<<(std::ostream &out, Conway &conway);
private:
    static unsigned long long time;
    void init();
    bool isValid(unsigned x, unsigned y);
    unsigned width;
    unsigned height;
    std::vector<std::vector<Cell *> > world;
};

#endif // __COMWAY_H
