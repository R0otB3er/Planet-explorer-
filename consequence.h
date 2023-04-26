#ifndef CONSEQUENCE_H
#define CONSEQUENCE_H
#include "spaceship.h"
#include <iostream>


class consequence{
    private:
        int changeFuel;
        int changeCrew;
        spaceship newShip;
        int NextChapter;
        bool getLose;
        bool isShip;

    public:
        consequence();
        consequence(int,int,bool,int);
        consequence(spaceship,int);
        bool isAShip();
        void setgetLose(bool);
        bool getGetLose();
        void setChangeFuel(int);
        int getChangeFuel();
        void setChangeCrew(int);
        int getChangeCrew();
        void SetShip(spaceship);
        spaceship getShip();
        void setChapter(int);
        int getChapter();

        void applyToShip(spaceship&); //adds or removes fuel & crew to the ship based on saved values
        friend ostream& operator<<(ostream& out, consequence cons);
        //Void applyToCrew(Crew&); //removes or adds crew based on value
        //void add(const consequence& other); // adds values from other consequence to current one
};
#endif