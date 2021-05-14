#ifndef __CELL_H
#define __CELL_H

#include <string>

class Cell{
public:
    Cell();
    Cell(Cell *parent);
    std::string getIdentifier() const;
    Cell *getParent();
    bool isAlive() const;
private:
    bool alive;
    std::string identifier;
    Cell *parent;
};

#endif // _CELL_H
