#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <string>
#include <iostream>
using namespace std;

class spaceship {
    private:
        int fuel_capacity;
        int crew_capacity;
        string name;
        int crewNum;
        int fuel;
    public:
        spaceship();

        spaceship(string,int,int);
        
        string getName(){return name;}
        
        void setName(string);
        
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
        
        string fuelR(); // fuel/fuel_capacity
        
        string crewR(); // crewNum/crew_capacity
        
        spaceship read(string); //takes a string and parses out information to make a spaceship
        
 //       friend ostream& operator<<(ostream& out, spaceship& ship);
};
#endif