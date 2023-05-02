// did not have enough time to implement randomness to the game
#ifndef DICE_H
#define DICE_H
#include <cstdlib>

class dice{
    public:
        dice();
        ~dice();
        int throwDice(int); // generates a random number between 0 and int given
        bool passCheck(int,int); //generates a random number between 0 and first in and returns true if it is greater than second int
};

dice::dice(){}
dice::~dice(){}

int dice::throwDice(int max){
    std::srand(time(NULL));
    return rand() % (max+1) + 1;
}

bool dice::passCheck(int max, int level){
    std::srand(time(NULL));
    return level >= (rand() % (max+1));
}

#endif