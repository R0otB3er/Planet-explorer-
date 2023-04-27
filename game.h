#ifndef GAME.H
#define GAME.H

#include "chapter.h"
#include "condition.h"
#include "consequence.h"
#include "dice.h"
#include "option"
#include "spaceship.h"
#include "planet.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class game{
    private:
        spaceship ship;
        vector<planet> unexploredPlanets;
        vector<planet> exploredPlanets;
        chapter current;
        planet currPlanet;

    public:
        game();
        game(int); // fills the un explored planets vector with the given int of planets
        int doChap(int);
        void planetToExplored();
        void printPlanetOptions();
        bool isAlive();




}


#endif