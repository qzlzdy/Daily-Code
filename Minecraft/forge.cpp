#include <array>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <queue>

using namespace std;

struct Solution{
    Solution() : Position(0), Prev(nullptr) {}
    Solution(int pos, Solution *ptr) : Position(pos), Prev(ptr) {};
    int Position;
    Solution *Prev;
};

int main(int args, char **argv){
    if(args != 2){
        cerr << "Usage: forge target" << endl;
        return -1;
    }
    int target = atoi(argv[1]);
    array<int, 8> directions = {-15, -9, -6, -3, 16, 13, 7, 2};
    queue<Solution *> Q;
    Q.push(new Solution());
    while(Q.front()->Position != target){
        int distance = abs(Q.front()->Position - target);
        for(auto direction : directions){
            int nextPosition = Q.front()->Position + direction;
            if(abs(nextPosition - target) < distance){
                Q.push(new Solution(nextPosition, Q.front()));
            }
        }
        Q.pop();
    }
    function<void(Solution *)> printSolution;
    printSolution = [&](Solution *S){
        if(S->Prev == nullptr){
            return;
        }
        printSolution(S->Prev);
        cout << showpos << S->Position - S->Prev->Position << " ";
    };
    printSolution(Q.front());
    cout << endl;
    return EXIT_SUCCESS;
}
