#include <Conway.h>

#include <iostream>
#include <vector>

using namespace std;

int main(){
    Conway game(120, 50);
    game.init();
    game.run();
    return 0;
}
