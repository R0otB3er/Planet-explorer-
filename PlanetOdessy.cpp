
#include "helper.h"
#include "game.h"
#include <iostream>
#include <stdlib.h>



using namespace std;



int main(){

    game theGame;    

    printDecal();
    printTitle();
    system("pause");
    system("cls");
    
    //this loop is the whole game
    for(int loop = 0; loop < 3;loop++){
        int choice = 0;
        cout << theGame.getShip() << endl << "Choose the planet you want to explore!" << endl;
        theGame.printPlanetOptions();

        choice = getOptionChoice();
        // checks to make sure the user has enough fuel to go to the planet and if not if gives a you lose screen
        if(theGame.changeCurPlanet(choice) == 0){ 
            theGame.changeCurChap(-1);
            system("cls");
            cout << theGame.getCurrent();
            exit(0);
        }

        system("cls");
        
        //this loop is the user on a planet
        while(theGame.getCurPlanet().numOfOptions() != 0){
            cout << theGame.getShip() << endl;
            cout<<theGame.getCurPlanet();

            theGame.doPlanet(getOptionChoice());

            system("cls");

            //this loop is the user going through chapters
            while(true){
                cout << theGame.getShip() << endl;
                int optionCheck = -1;
                cout<<theGame.getCurrent();
            
                if(theGame.getCurrent().numOfOptions() == 0){
                    system("pause");
                    system("cls");
                    break;
                }

                //makes sure a valid answer is given
                while(optionCheck == -1){
                    optionCheck = theGame.doChap(getOptionChoice());
                }

                theGame.changeCurChap(optionCheck);

                //a check to make sure the user is alive
                if (optionCheck == 0){
                    system("cls");
                    cout<<theGame.getCurrent();
                    exit(0);
                }

                system("cls");
            }
        }

        theGame.removePlanetOption(choice);
    }
    // the win screen
    system("cls");
    cout << "                                                                                                 YOU BEAT" << endl;
    printDecal();
    printTitle();
    printDecal();

    return 0;
}