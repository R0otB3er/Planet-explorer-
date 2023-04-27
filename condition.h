#ifndef CONDITION_H
#define CONDITION_H
#include "spaceship.h"

class condition {
    private:
        int fuelNeeded;
        int crewNeeded;
    public:
        condition();
        condition(int, int);
        ~condition();
        int getFuelNeeded();
        void setFuelNeeded(int);
        int getCrewNeeded();
        void setCrewNeeded(int);
        bool pass(spaceship);
        friend std::ostream& operator<<(std::ostream& out, condition cond);
};

condition::condition(){
    fuelNeeded = 0;
    crewNeeded = 0;
}

condition::condition(int FNeed, int CNeed){
    fuelNeeded = FNeed;
    crewNeeded = CNeed;
}

condition::~condition(){}

int condition::getFuelNeeded(){
    return fuelNeeded;
}

void condition::setFuelNeeded(int FNeed){
    fuelNeeded = FNeed;
}
        
int condition::getCrewNeeded(){
    return crewNeeded;
}

void condition::setCrewNeeded(int CNeed){
    crewNeeded = CNeed;
}

bool condition::pass(spaceship ship){
    if((ship.getFuel() >= fuelNeeded) && (ship.getCrew() >= crewNeeded)){
        return true;
    }
    return false;
}

std::ostream& operator<<(std::ostream& out, condition cond){
    if(cond.getFuelNeeded() > 0 || cond.getCrewNeeded() > 0){
        out << "reqired: ";
    }
    
    if(cond.getFuelNeeded() > 0){
        out<< cond.getFuelNeeded() << " fuel ";
    }

    if(cond.getCrewNeeded()){
        out << cond.getCrewNeeded() << " crew"; 
    }

    return out;
}
#endif