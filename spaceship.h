#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <string>
#include <iostream>



class spaceship {
    private:
        int fuel_capacity;
        int crew_capacity;
        std::string name;
        int crewNum;
        int fuel;
    public:
        spaceship();

        spaceship(std::string,int,int);

        ~spaceship();
        
        std::string getName(){return name;}
        
        void setName(std::string);
        
        int getFuelCapacity(){return fuel_capacity;}
        
        void setFuelCapacity(int);
        
        int getCrewCapacity(){return crew_capacity;}
        
        void setCrewCapacity(int);
        
        int getFuel(){return fuel;}
        
        void setFuel(int);
        
        int getCrew(){return crewNum;}
        
        void setCrew(int);
        
        bool isFullF(); //return true if fuel is full
        
        bool isFullC(); // returns true if no more crew can fit
        
        std::string fuelR(); // fuel/fuel_capacity
        
        std::string crewR(); // crewNum/crew_capacity
        
        friend std::ostream& operator<<(std::ostream& out, spaceship& ship);
};

spaceship::spaceship(){
    name = "";
    fuel_capacity = 0;
    crew_capacity = 0;
    fuel = 0;
    crewNum = 0;
}

spaceship::spaceship( std::string _name, int fuelCap,int crewCap){
    name = _name;
    fuel_capacity = fuelCap;
    crew_capacity = crewCap;
    fuel = fuelCap;
    crewNum = 0;
}

spaceship::~spaceship(){

}

void spaceship::setFuelCapacity(int fuelCap){
    fuel_capacity = fuelCap;
}
        
void spaceship::setCrewCapacity(int crewCap){
    crew_capacity = crewCap;
}
        
void spaceship::setFuel(int _fuel){
    fuel = _fuel;
}

void spaceship::setCrew(int _crew){
    crewNum = _crew;
}

void spaceship::setName( std::string _name){
    name = _name;
}
bool spaceship::isFullF(){
    return fuel == fuel_capacity;
}

bool spaceship::isFullC(){
    return crewNum == crew_capacity;
}

std::string spaceship::fuelR(){
     std::string ratio = std::to_string(fuel) + "/" + std::to_string(fuel_capacity);
    return ratio;
}

std::string spaceship::crewR(){
     std::string ratio = std::to_string(crewNum) + "/" + std::to_string(crew_capacity);
    return ratio;
}

std::ostream& operator<<(std::ostream& out, spaceship & ship){
    out << ship.getName() << std::endl << "Fuel: " << ship.fuelR() << std::endl << "Crew: " << ship.crewR() << std::endl;
    return out;
}
#endif