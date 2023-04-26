#ifndef DICE_H
#define DICE_H
#include <cstdlib>

class dice{
    public:
        dice();
        int throwDice(int); // generates a random number between 0 and int given
        bool passCheck(int,int); //generates a random number between 0 and first in and returns true if it is greater than second int
};

#endif