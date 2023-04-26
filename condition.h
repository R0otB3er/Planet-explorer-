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
        int getFuelNeeded();
        void setFuelNeeded(int);
        int getCrewNeeded();
        void setCrewNeeded(int);
        bool pass(spaceship);
   //     friend ostream& operator<<(ostream& out, condition cond);
};
#endif