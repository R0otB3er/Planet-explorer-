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
        planet* currPlanet;

    public:
        game();
        game(int); // fills the un explored planets vector with the given int of planets
        ~game();
        void changeCurChap(int);
        bool changeCurPlanet(int);
        int doChap(int);
        void doPlanet(int);
        void planetToExplored(int);
        void printPlanetOptions();
        bool isAlive();
        chapter getCurrent();
        planet getCurPlanet();
        void printCurrent();
        planet getPlanet(int);
        void setShip(spaceship);
        spaceship getShip();
        bool wasExplored(planet);
        void printCurPlanet();

};

game::game(){ // base level of planet options is 4
    for(int i = 1 ; i <=  4;i++){
        planet temp(i);
        unexploredPlanets.push_back(temp);
    }
    current = chapter();
    currPlanet = new planet();
    ship = spaceship("standard issue star explorer", 20, 10);
    ship.setCrew(5);
}

game::game(int numOfPlanets){} // if i want to have more or less planet options

game::~game(){}

int game::doChap(int choice){
    if(current.numOfOptions() - 1 >= choice  && choice >= 0){
        if(current.getOption(choice).getCondition().pass(ship)){
            current.getOption(choice).getConsequence().applyToShip(ship);
            return current.getOption(choice).getConsequence().getChapter();
        } else {
            std::cout << "you are missing something!" << std::endl;
        }  
    } else {
        std::cout << "invalid option" << std::endl;
        return 0;
    }
    return 0;
}

void game::doPlanet(int choice){
    if(currPlanet->numOfOptions() - 1 >= choice  && choice >= 0){
        if(currPlanet->getOption(choice).getCondition().pass(ship)){
            currPlanet->getOption(choice).getConsequence().applyToShip(ship);
            changeCurChap(currPlanet->getOption(choice).getConsequence().getChapter());
            currPlanet->removeOption(choice);
        }   
    } else {
        std::cout << "invalid option" << std::endl;
    }
}

void game::changeCurChap(int _chapNum){
    chapter nchap;
    if(_chapNum >= 0){
        nchap.setChapter(_chapNum);
    } 
    current = nchap;
    
}
   
void game::planetToExplored(int index){
    exploredPlanets.push_back(unexploredPlanets.at(index));
}

bool game::wasExplored(planet check){
    if(exploredPlanets.empty()){
        return false;
    }

    for(int i = 0; i < unexploredPlanets.size(); i++){
        if(exploredPlanets.at(i).getName() == check.getName()){
            return true;
        }
    }
    return false;
}
        
void game::printPlanetOptions(){
    for(int i = 0; i < unexploredPlanets.size(); i++){
        std::cout << i << "] ";
        unexploredPlanets.at(i).printMini();
        std::cout << std::endl;
    }
}

bool game::changeCurPlanet(int index){
    if(!wasExplored(unexploredPlanets.at(index)) && index < unexploredPlanets.size() && index >= 0){
        *currPlanet = unexploredPlanets.at(index);
        exploredPlanets.push_back(*currPlanet);
        return true;
    } else if(wasExplored(index)){
        std::cout << "This Planet has already been Explored" << std::endl;
        return false;
    } else{
        std::cout<< "Invalid choice try again" << std::endl;
        return false;
    }
    return false;
}
        
bool game::isAlive(){
    return ship.getCrew() > 0;
}

chapter game::getCurrent(){
    return current;
}

planet game::getCurPlanet(){
    return *currPlanet;
}

void game::printCurrent(){
    std::cout << current.getDescription() << std::endl;
    
    for(int i = 0; i < current.numOfOptions(); i++){
        std::cout << i << ")  ";
        current.getOption(i).print();
        std::cout << std::endl; 
    }
}

planet game::getPlanet(int choice){
    try{
        if(choice > unexploredPlanets.size() && choice < 0){
            throw std::runtime_error("bad index");
        }

    } catch(std::runtime_error& excpt){
        std::cout << excpt.what() << std::endl;
    }
    return unexploredPlanets.at(choice);
}

spaceship game::getShip(){
    return ship;
}

void game::setShip(spaceship nShip){
    ship = nShip;
}

void game::printCurPlanet(){
    std::cout << currPlanet;
}

#endif