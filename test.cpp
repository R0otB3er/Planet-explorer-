
#include "helper.h"
#include "game.h"
#include <iostream>



using namespace std;



int main(){

    game testGame;
    int choice;
    string stream;
    chapter testing(1);

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
    
    testGame.getCurrent().setChapter(testGame.doPlanet(choice));

    cout << testing;
    
    testGame.printCurrent();
    


    return 0;
}