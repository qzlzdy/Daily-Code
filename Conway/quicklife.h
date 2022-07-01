#ifndef QUICKLIFE_H
#define QUICKLIFE_H

namespace qzlzdy{

struct brick{
    uint32_t d[16];
};

struct tile{
    brick *b[4];
    short c[6];
    int flags, localdeltaforward;
};

struct supertile{
    supertile *d[8];
    int flags;
    int pop[2];
};

class quicklife{
public:
    quicklife();
    virtual ~quicklife();
    virtual int setcell(int x, int y, int newstate);
    virtual int getcell(int x, int y);
    virtual int nextcell(int x, int y, int &v);
private:
    brick *newbrick();
    tile *newtile();
    supertile *newsupertile();
    brick *bricklist;
};

}

#endif
