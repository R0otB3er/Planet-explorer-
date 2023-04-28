#include "game.h"
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

/*
using namespace std;

game::game(){}

game::game(int numOfPlanets){}

int game::doChap(int choice){
    if(current.numOfOptions() >= choice  && choice >= 0){
        if(current.getOption(choice).getCondition().pass(ship)){
            current.getOption(choice).getConsequence().applyToShip(ship);
            return current.getOption(choice).getConsequence().getChapter();
        }   
    } else {
        cout << "invalid option" << endl;
        return 0;
    }
    return 0;
}

game::~game(){}
        
void game::planetToExplored(int index){
    exploredPlanets.push_back(unexploredPlanets(index));
    unexploredPlanets.~vector(index);
}
        
void game::printPlanetOptions(){
    for(int i = 0; i < unexploredPlanets.size(); i++){
        cout << i << "] " << unexploredPlanets[i].printMini();
        cout << endl;
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
*/