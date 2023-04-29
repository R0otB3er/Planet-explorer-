
#include "helper.h"
#include "game.h"
#include <iostream>



using namespace std;



int main(){

    game testGame;
    int choice;
    string stream;
    chapter doodoo(1);
    

    //printDecal();
    //printTitle();
    
    testGame.printPlanetOptions();
    cout << "> ";
    cin >> stream;
    choice = stoi(stream);
    
    testGame.choosePlanet(choice);
    
    cout << testGame.getPlanet(choice);
    
    cout << "> ";
    cin >> stream;
    choice = stoi(stream);

    testGame.changeCurChap(testGame.doPlanet(choice));

    testGame.printCurrent();

    cout << "> ";
    cin >> stream;
    choice = stoi(stream);

    testGame.changeCurChap(testGame.doChap(choice));

    cout << testGame.getShip();
    testGame.printCurrent();

    return 0;
}