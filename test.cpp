
#include "helper.h"
#include "game.h"
#include <iostream>



using namespace std;



int main(){

    game testGame;

    printDecal();
    printTitle();
    printDecal();

    testGame.printPlanetOptions();

    return 0;
}