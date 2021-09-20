#ifndef CELL_H
#define CELL_H

#include <cstdint>

class Cell{
public:
    enum Gender{
        Female,
        Male
    };
    static unsigned getPopulation();
    Cell();
    ~Cell();
    void birth(bool init = true);
    void birth(const Cell &Father, const Cell &Mother);
    void die();
    unsigned getAge() const;
    uint64_t getCharacter() const;
    Gender getSex() const;
    void grow();
    bool isAlive() const;
    bool isFertile() const;
private:
    static const unsigned Lifespan;
    static const unsigned MinChildbirthAge;
    static const unsigned MaxChildbirthAge;
    static unsigned Population;
    bool IsAlive;
    unsigned Age;
    Gender Sex;
    uint64_t Character;
};

#endif // CELL_H
