#include "quicklife.h"

#include <iostream>

using namespace qzlzdy;
using namespace std;

int qzlzdy::MEMCHUNK = 8192 - 16;

quicklife::quicklife(){
    maxmemory = 0;
    usedmemory = 0;
    bricklist = nullptr;
    memused = nullptr;
}

quicklife::~quicklife(){
    while(memused){
        linkedmem *nu = memused->next;
        delete memused;
        memused = nu;
    }
}

brick *quicklife::newbrick(){
    brick *r;
    if(bricklist == nullptr){

    }
}
