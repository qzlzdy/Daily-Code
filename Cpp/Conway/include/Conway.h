#ifndef __CONWAY_H
#define __CONWAY_H

#include <Cell.h>

#include <vector>

class Conway{
public:
    Conway(unsigned width, unsigned height);
    ~Conway();
    void step();
private:
    static unsigned long long time;
    void init();
    std::vector<std::vector<Cell *> > world;
};

#endif // __COMWAY_H
