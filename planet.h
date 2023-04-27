#ifndef PLANET_H
#define PLANET_H

#include "chapter.h"

class planet : public chapter{
    private:
        string name;
        string TLDR;
        condition fuelcost;
        int hostility;

    public:
        planet();
        planet(int); //opens a file with the given int and reads all of the information
        planet(string _name, string _TLDR, int cost, string des, vector<option>, int num);
        ~planet();
        string getName();
        void setName(string);
        string getTLDR();
        void setTLDR(string);
        int getFuelCost();
        void setFuelCost(int);
        int getHostility();
        void setHostility(int);
        void printMini(); // prints the name, hostility, fuelcost, and TLDR 
        friend ostream& operator<<(ostream& out, planet _planet);
};

#endif