#include "consequence.h"

consequence::consequence(){
    NextChapter = 0;
    changeCrew = 0;
    getLose = false;
    changeFuel = 0;
    isShip = false;
}

consequence::consequence(int CChange,int FChance, bool GL, int chapNum){
    NextChapter = chapNum;
    changeCrew = CChange;
    getLose = GL;
    changeFuel = FChance;
    isShip = false;
}
        
consequence::consequence(spaceship _ship,int chapNum){
    changeCrew = 0;
    changeFuel = 0;
    newShip = _ship;
    NextChapter = chapNum;
    getLose = true;
    isShip = true;
}

consequence::~consequence(){}

void consequence::setgetLose(bool GL){
    getLose = GL;
}
        
bool consequence::getGetLose(){
    return getLose;
}  
void consequence::setChangeFuel(int fuel){
    changeFuel = fuel;
}
        
int consequence::getChangeFuel(){
    return changeFuel;
}

void consequence::setChangeCrew(int crew){
    changeCrew = crew;
}
        
int consequence::getChangeCrew(){
    return changeCrew;
}
        
void consequence::SetShip(spaceship ship){
    newShip = ship;
}
        
spaceship consequence::getShip(){
    return newShip;
}
        
void consequence::setChapter(int chapNum){
    NextChapter = chapNum;
}

int consequence::getChapter(){
    return NextChapter;
}

bool consequence::isAShip(){
    return isShip;
}

void consequence::applyToShip(spaceship& ship){
    if(getLose){
        ship.setCrew(ship.getCrew() + changeCrew);
        ship.setFuel(ship.getFuel() + changeFuel);
    } else{
        ship.setCrew(ship.getCrew() - changeCrew);
        ship.setFuel(ship.getFuel() - changeFuel);
    }

    if(ship.getFuel() < 0){
        ship.setFuel(0);
    }

    if(ship.getFuel() > ship.getFuelCapacity()){
        ship.setFuel(ship.getFuelCapacity());
    }

    if(ship.getCrew() < 0){ // some call to end the game?
        ship.setCrew(0);
    }

    if(ship.getCrew() > ship.getCrewCapacity()){
        ship.setCrew(ship.getCrewCapacity());
    }
}

ostream& operator<<(ostream& out, consequence cons){
    if(cons.getGetLose()){
        out << "Get ";
    } else {
        out << "lose ";
    }

    if(cons.getChangeCrew() > 0){
        out  << cons.getChangeCrew() << " crewMembers ";
    }
    
    if(cons.getChangeFuel() > 0){
        out << cons.getChangeFuel() << " fuel";
    }

    if(cons.isAShip()){
        out << cons.getShip().getName();    
    }
    return out;
}

/*
void consequence::add(consequence & other){

}
*/