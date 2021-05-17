#ifndef __CELL_H
#define __CELL_H

#include <string>
#include <vector>

class Cell{
public:
    Cell(unsigned long long bt);
    ~Cell();
    static unsigned long long getBirthCount();
    static unsigned long long getDeathCount();
    std::string getIdentifier() const;
    unsigned long long getBirthTime() const;
    std::vector<unsigned char> getDNA() const;
private:
    static unsigned long long birthCount;
    static unsigned long long deathCount;
    std::string identifier;
    unsigned long long birthTime;
    std::vector<unsigned char> DNA;
};

#endif // _CELL_H
