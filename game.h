#ifndef GAME_H
#define GAME_H

#include "chapter.h"
#include "condition.h"
#include "consequence.h"
#include "dice.h"
#include "option.h"
#include "spaceship.h"
#include "planet.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class game{
    private:
        spaceship ship;
        std::vector<planet> unexploredPlanets;
        std::vector<planet> exploredPlanets;
        chapter current;
        planet currPlanet;

    public:
        game();
        game(int); // fills the un explored planets vector with the given int of planets
        ~game();
        int doChap(int);
        void planetToExplored(int);
        void printPlanetOptions();
        bool isAlive();
        void setShip(spaceship);
        spaceship getShip();
};

game::game(){ // base level of planet options is 4
    for(int i = 1 ; i <=  4;i++){
        planet temp(i);
        unexploredPlanets.push_back(temp);
    }
}

game::game(int numOfPlanets){} // if i want to have more or less planet options

int game::doChap(int choice){
    if(current.numOfOptions() >= choice  && choice >= 0){
        if(current.getOption(choice).getCondition().pass(ship)){
            current.getOption(choice).getConsequence().applyToShip(ship);
            return current.getOption(choice).getConsequence().getChapter();
        }   
    } else {
        std::cout << "invalid option" << std::endl;
        return 0;
    }
    return 0;
}

game::~game(){}
        
void game::planetToExplored(int index){
    exploredPlanets.push_back(unexploredPlanets.at(index));
    //unexploredPlanets.~vector(index);
}
        
void game::printPlanetOptions(){
    for(int i = 0; i < unexploredPlanets.size(); i++){
        std::cout << i << "] ";
        unexploredPlanets.at(i).printMini();
        std::cout << std::endl;
    }
}
        
bool game::isAlive(){
    return ship.getCrew() > 0;
}

spaceship game::getShip(){
    return ship;
}

void game::setShip(spaceship nShip){
    ship = nShip;
}


#endif