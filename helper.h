#ifndef HELPER_H
#define HELPER_H

#include "chapter.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
void printTitle(){

    cout <<"              ,--,                                                 ,----," << endl;                                                                                                                                 
    cout <<",-.----.   ,---.'|                           ,--.                ,/   .`|                                               ,----..                                                           " << endl;
    cout <<"    /   \\  |   | :      ,---,              ,--.'|    ,---,.    ,`   .'  : ,---,       ,-.----.                         /   /   \\      ,---,                  .--.--.    .--.--.       ,---,." << endl;              
    cout <<"|   :    \\ :   : |     '  .' \\         ,--,:  : |  ,'  .' |  ;    ;     /'  .' \\      \\    /  \\        ,---,          /   .     :   .'  .' `\\         ,---, /  /    '. /  /    '.   ,'  .' |        ,---," << endl; 
    cout <<"|   |  .\\ :|   ' :    /  ;    '.    ,`--.'`|  ' :,---.'   |.'___,/    ,'/  ;    '.    ;   :    \\      /_ ./|         .   /   ;.  \\,---.'     \\       /_ ./||  :  /`. /|  :  /`. / ,---.'   |       /_ ./|" << endl;
    cout <<".   :  |: |;   ; '   :  :       \\   |   :  :  | ||   |   .'|    :     |:  :       \\   |   | .\\ :,---, |  ' :        .   ;   /  ` ;|   |  .`\\  |,---, |  ' :;  |  |--` ;  |  |--`  |   |   .' ,---, |  ' :" << endl; 
    cout <<"|   |   \\ :'   | |__ :  |   /\\   \\  :   |   \\ | ::   :  |-,;    |.';  ;:  |   /\\   \\  .   : |: /___/ \\.  : |        ;   |  ; \\ ; |:   : |  '  /___/ \\.  : ||  :  ;_   |  :  ;_    :   :  |-,/___/ \\.  : | "<< endl;
    cout <<"|   : .   /|   | :.'||  :  ' ;.   : |   : '  '; |:   |  ;/|`----'  |  ||  :  ' ;.   : |   |  \\ :.  \\  \\ ,' '        |   :  | ; | '|   ' '  ;  :.  \\  \\ ,' ' \\  \\    `. \\  \\    `. :   |  ;/| .  \\  \\ ,' ' " << endl;
    cout <<";   | |`-' '   :    ;|  |  ;/  \\   \'   ' ;.    ;|   :   .'    '   :  ;|  |  ;/  \\   \\|   : .  / \\  ;  `  ,'         .   |  ' ' ' :'   | ;  .  | \\  ;  `  ,'  `----.   \\ `----.   \\|   :   .'  \\  ;  `  ,' "<< endl;
    cout <<"|   | ;    |   |  ./ '  :  | \\  \\ ,'|   | | \\   ||   |  |-,    |   |  ''  :  | \\  \\ ,';   | |  \\  \\  \\    '         '   ;  \\; /  ||   | :  |  '  \\  \\    '   __ \\  \\  | __ \\  \\  ||   |  |-,   \\  \\    '  " << endl;
    cout <<":   ' |    ;   : ;   |  |  '  '--'  '   : |  ; .''   :  ;/|    '   :  ||  |  '  '--'  |   | ;\\  \\  '  \\   |          \\   \\  ',  / '   : | /  ;    '  \\   |  /  /`--'  //  /`--'  /'   :  ;/|    '  \\   |  " << endl;
    cout <<":   : :    |   ,/    |  :  :        |   | '`--'  |   |    \\    ;   |.' |  :  :        :   ' | \\.'   \\  ;  ;           ;   :    /  |   | '` ,/      \\  ;  ; '--'.     /'--'.     / |   |    \\     \\  ;  ;  " << endl;
    cout <<"|   | :    '---'     |  | ,'        '   : |      |   :   .'    '---'   |  | ,'        :   : :-'      :  \\  \\           \\   \\ .'   ;   :  .'         :  \\  \\  `--'---'   `--'---'  |   :   .'      :  \\  \\ " << endl;
    cout <<"`---'.|              `--''          ;   |.'      |   | ,'              `--''          |   |.'         \\  ' ;            `---`     |   ,.'            \\  ' ;                       |   | ,'         \\  ' ; " << endl;
    cout <<"  `---`                             '---'        `----'                               `---'            `--`                       '---'               `--`                        `----'            `--` " << endl; 
                      
}

void printDecal(){
    cout <<"             .                      .                                                                                                                                       .                      .         "<< endl;
    cout <<"             .                      ;                                                                                                                                       .                      ;         "<< endl;
    cout <<"             :                  - --+- -                                                                                                                                    :                  - --+- -      "<< endl;
    cout <<"             !           .          !                                                                                                                                       !           .          !         "<< endl;
    cout <<"             |        .             .                                                                                                                                       |        .             .         "<< endl;
    cout <<"             |_         +                                                                                                                                                   |_         +                     "<< endl;
    cout <<"          ,  | `.                                                                                                                                                        ,  | `.                             "<< endl;
    cout <<"--- --- --+-<#>-+- ---  --  -                                                                                                                                  --- --- --+-<#>-+- ---  --  -                 "<< endl;
    cout <<"          `._|_,'                                                                                                                                                        `._|_,'                             "<< endl;
    cout <<"             T                                                                                                                                                              T                                "<< endl;
    cout <<"             |                                                                                                                                                              |                                "<< endl;
    cout <<"             !                                                                                                                                                              !                                "<< endl;
    cout <<"             :         . :                                                                                                                                                  :         . :                    "<< endl;
    cout <<"             .       *                                                                                                                                                      .       *                        "<< endl;

}

void changeChapter(chapter& chap,int num){
    std::ifstream inFS;
    std::string stream;
    int count = 0;

    //checks to see if you can open the file
    try{
        if( num < 10){
            inFS.open("chap/30,0" + std::to_string(num) + ".txt");
            //cout << "chap/30,0" << std::to_string(num) << ".txt";
        }else{
            inFS.open("chap/30," + std::to_string(num) + ".txt");
            //cout << "chap/30," << std::to_string(num) << ".txt";
        }
        if(!inFS.is_open()){
            throw std::runtime_error("No File");
        }
    }catch(std::runtime_error& excpt){
        std::cout << excpt.what() << std::endl;
    }


    std::getline(inFS, stream);
    chap.setDescription(stream);
    //std::cout << description << endl;
   

        while(!inFS.eof()){
            condition cond_temp;
            consequence cons_temp;
            option op_temp;

            std::getline(inFS,stream,'@');
            if(count == 0){
                op_temp.setText(stream); 
            } else {
                op_temp.setText(stream.substr(1,stream.length() - 2)); 
            }
        
            inFS >> stream;
            if(stream == "if"){
                inFS >> stream;
                    if(stream == "fuel"){
                        inFS >> stream;
                        cond_temp.setFuelNeeded(stoi(stream));
                        inFS >> stream;
                    }
                    if(stream == "crew"){
                        inFS >> stream;
                        cond_temp.setCrewNeeded(stoi(stream));
                        inFS >> stream;

                    }
            }

            op_temp.setCondition(cond_temp);

            if(stream == "add"){
                inFS >> stream;
                cons_temp.setgetLose(true);
                if(stream == "crew"){
                    inFS >> stream;
                    cons_temp.setChangeCrew(stoi(stream));
                    inFS >> stream;
                }
                if(stream == "fuel"){
                    inFS >> stream;
                    cons_temp.setChangeFuel(stoi(stream));
                    inFS >> stream;
                }
            }

            if(stream == "lose"){
                inFS >> stream;
                cons_temp.setgetLose(false);
                if(stream == "crew"){
                    inFS >> stream;
                    cons_temp.setChangeCrew(stoi(stream));
                    inFS >> stream;
                }
                if(stream == "fuel"){
                    inFS >> stream;
                    cons_temp.setChangeFuel(stoi(stream));
                    inFS >> stream;
                }
            }

            if(stream == "goto"){
                inFS >> stream;
                cons_temp.setChapter(stoi(stream));
            }

            op_temp.setConsequence(cons_temp);
            chap.addOption(op_temp);
            //std::cout << options.at(count) << std::endl;

            count++;
    }
}

#endif