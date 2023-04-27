#include "game.h"
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

        
void game::planetToExplored(){

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