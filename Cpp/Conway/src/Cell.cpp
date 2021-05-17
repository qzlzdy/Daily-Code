#include <Cell.h>

#include <algorithm>
#include <random>
#include <sstream>

using namespace std;

Cell::Cell(unsigned long long bt){
    ++birthCount;
    birthTime = bt;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> idDis(33, 126);
    ostringstream buffer;
    for(int i = 0; i < 16; ++i){
        buffer << (char)idDis(gen);
    }
    identifier = buffer.str();
    uniform_int_distribution<> genesDis(0, 255);
    unsigned char genes = (unsigned char)genesDis(gen);
    DNA = vector<unsigned char>(16, genes);
}

Cell::~Cell(){
    ++deathCount;
}

unsigned long long Cell::getBirthCount(){
    return birthCount;
}

unsigned long long Cell::getDeathCount(){
    return deathCount;
}

string Cell::getIdentifier() const{
    return identifier;
}

unsigned long long Cell::getBirthTime() const{
    return birthTime;
}

vector<unsigned char> Cell::getDNA() const{
    return DNA;
}

unsigned long long Cell::birthCount = 0;
unsigned long long Cell::deathCount = 0;
