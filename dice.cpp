#include "dice.h"
#include <cstdlib>

using namespace std;

dice::dice(){}
dice::~dice(){}

int dice::throwDice(int max){
    srand(time(NULL));
    return rand() % (max+1) + 1;
}

bool dice::passCheck(int max, int level){
    srand(time(NULL));
    return level >= (rand() % (max+1));
}