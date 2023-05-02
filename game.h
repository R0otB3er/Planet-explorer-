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
        chapter current; // holds the information to the current chapter the user is on
        planet* currPlanet; //points to the planet the user is currently on

    public:
        game();
        // fills the un explored planets vector with the given int of planets
        game(int); 
        ~game();
        // calls the set function on the "current" chapter using the num given
        void changeCurChap(int);
        // points curPlanet to the unexploredplanet and the index given 
        int changeCurPlanet(int); 
        /*applies the changes stores in the consequence of the option at the index.
        returns -1 if there is a bad index, 0 if the consequence leads to no more crewm members and an in that leads to the next chapter 
        */
        int doChap(int);
        // similar to doChap but doesnt check for death and is main function is to point to the first event on the planet 
        void doPlanet(int);
        //prints all of the planets available to explore
        void printPlanetOptions();
        // checks to see if crew is > 0
        bool isAlive();
        chapter getCurrent();
        planet getCurPlanet();
        void printCurrent();
        planet getPlanet(int);
        void setShip(spaceship);
        spaceship getShip();
        void printCurPlanet();
        // removes a planet from the vector of unexplored planets
        void removePlanetOption(int);

};

game::game(){ // base level of planet options is 3
    for(int i = 1 ; i <=  3;i++){
        planet temp(i);
        unexploredPlanets.push_back(temp);
    }
    current = chapter();
    currPlanet = new planet();
    ship = spaceship("standard issue star explorer", 50, 10);
    ship.setCrew(5);
}

game::game(int numOfPlanets){
    for(int i = 1 ; i <=  numOfPlanets;i++){
        planet temp(i);
        unexploredPlanets.push_back(temp);
    }
    current = chapter();
    currPlanet = new planet();
    ship = spaceship("standard issue star explorer", 20, 10);
    ship.setCrew(5);
    } // if i want to have more or less planet options

game::~game(){}

int game::doChap(int choice){
    if(current.numOfOptions() - 1 >= choice  && choice >= 0){
        if(current.getOption(choice).getCondition().pass(ship)){
            current.getOption(choice).getConsequence().applyToShip(ship);
            if(isAlive()){
                return current.getOption(choice).getConsequence().getChapter();
            } else {
                return 0;
            }
        } else {
            std::cout << "you are missing something!" << std::endl;
        }  
    } else {
        std::cout << "invalid option" << std::endl;
        return -1;
    }
    return -1;
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
    current = chapter();
        current.setChapter(_chapNum);
}
        
void game::printPlanetOptions(){
    for(int i = 0; i < unexploredPlanets.size(); i++){
        std::cout << i << "] ";
        unexploredPlanets.at(i).printMini();
        std::cout << std::endl;
    }
}

int game::changeCurPlanet(int index){
    if(index < unexploredPlanets.size() && index >= 0 && unexploredPlanets.at(index).checkFuel(ship)){
        currPlanet = &unexploredPlanets.at(index);
        currPlanet->getFuelCost().applyToShip(ship);
        return 1;
    }else if(!unexploredPlanets.at(index).checkFuel(ship)){
        return 0;
    }else{
        std::cout<< "Invalid choice try again" << std::endl;
        return -1;
    }
    cout << "SHOULDNT GET HERE";
    return -1;
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
    std::cout << current.getDescription() << std::endl << std::endl;
    
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

void game::removePlanetOption(int index){
    if(index < unexploredPlanets.size() && index >= 0){
        unexploredPlanets.erase(unexploredPlanets.begin()+index);
    } else{
        std::cout << "BAD INDEX";
    }
}

#endif