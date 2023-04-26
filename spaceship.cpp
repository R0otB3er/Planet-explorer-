#include "spaceship.h"
#include <string>
#include <iostream>

spaceship::spaceship(){
    name = "";
    fuel_capacity = 0;
    crew_capacity = 0;
    fuel = 0;
    crewNum = 0;
}

spaceship::spaceship(string _name, int fuelCap,int crewCap){
    name = _name;
    fuel_capacity = fuelCap;
    crew_capacity = crewCap;
    fuel = fuelCap;
    crewNum = 0;
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

void spaceship::setName(string _name){
    name = _name;
}
bool spaceship::isFullF(){
    return fuel == fuel_capacity;
}

bool spaceship::isFullC(){
    return crewNum == crew_capacity;
}

string spaceship::fuelR(){
    string ratio = fuel + "/" + fuel_capacity;
    return ratio;
}

string spaceship::crewR(){
    string ratio = crewNum + "/" + crew_capacity;
    return ratio;
}

ostream& operator<<(ostream& out, spaceship & ship){
    out << ship.getName() << endl << "Fuel: " << ship.fuelR() << endl << "Crew: " << ship.crewR() << endl;
    return out;
}