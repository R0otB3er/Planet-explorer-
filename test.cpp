
#include "helper.h"
#include "game.h"
#include <iostream>



using namespace std;



int main(){

    game testGame;
    int choice = 0;
    string throwAway;
    chapter doodoo(1);
    

    //printDecal();
    //printTitle();
    
    for(int loop = 0; loop < 4;loop++){
        testGame.printPlanetOptions();

        testGame.changeCurPlanet(getOptionChoice());

        while(testGame.getCurPlanet().numOfOptions() != 0){
            cout<<testGame.getCurPlanet();

            testGame.doPlanet(getOptionChoice());
        
            while(true){
                int optionCheck = 0;
                cout<<testGame.getCurrent();
            
                if(testGame.getCurrent().numOfOptions() == 0){
                    cout << "Enter anyhing to continue" << endl;
                    cin >>throwAway;
                    break;
                }

                while(optionCheck == 0){
                    optionCheck = testGame.doChap(getOptionChoice());
                }

                testGame.changeCurChap(optionCheck);
            }
        }
    }

    return 0;
}