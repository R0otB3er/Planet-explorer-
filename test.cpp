#include "chapter.h"
#include "planet.h"
#include "condition.h"
#include "consequence.h"
#include "spaceship.h"
#include "option.h"
#include "helper.h"
#include "game.h"
#include <iostream>
#include <fstream>


using namespace std;



int main(){

    game testGame;

    printTitle();

    testGame.printPlanetOptions();


    return 0;
}