#include <Conway.h>

#include <iostream>
#include <thread>

using namespace std;

int main(){
    Conway game(180, 50);
    while(true){
        cout << game << endl;
        this_thread::sleep_for(200ms);
        game.step();
    }
    return 0;
}
