#ifndef PLANET_H
#define PLANET_H

#include "chapter.h"

class planet : public chapter{
    private:
        std::string name;
        std::string TLDR;
        condition fuelcost;
        int hostility;

    public:
        planet();
        planet(int); //opens a file with the given int and reads all of the information
        planet(std::string _name, std::string _TLDR, int cost, std::string des, std::vector<option>, int num);
        ~planet();
        std::string getName();
        void setName(std::string);
        std::string getTLDR();
        void setTLDR(std::string);
        int getFuelCost();
        void setFuelCost(int);
        int getHostility();
        void setHostility(int);
        void printMini(); // prints the name, hostility, fuelcost, and TLDR 
        friend std::ostream& operator<<(std::ostream& out, planet _planet);
};

planet::planet() : chapter(){
    name = "";
    TLDR = "";
    hostility = 0;
    fuelcost = condition();
}

planet::~planet(){}

planet::planet(int _chapNum){ 
    fileNum = _chapNum;
    std::ifstream inFS;
    std::string stream;
    int count = 0;
    int fuel;

    try{
        if( _chapNum < 10){
            inFS.open("chap/planet/0" + std::to_string(_chapNum) + ".txt");
        }else{
            inFS.open("chap/planet/" + std::to_string(_chapNum) + ".txt");
        }

        if(!inFS.is_open()){
            throw std::runtime_error("No File");
        }
    }
    catch(std::runtime_error& excpt){
         std::cout << excpt.what() << std::endl;
    }

    std::getline(inFS, name);
    std::getline(inFS,TLDR);

    inFS >> stream;
    hostility = stoi(stream);

    inFS >> stream;
    fuel = stoi(stream);
    fuelcost.setFuelNeeded(fuel);
    inFS >> stream;

    std::getline(inFS, description);
    
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
        options.push_back(op_temp);

        count++;
    }

}

planet::planet(std::string _name, std::string _TLDR, int cost, std::string des, std::vector<option> ops, int num): chapter(des,ops){
    name = _name;
    TLDR = _TLDR;
    fuelcost.setFuelNeeded(cost);
}

std::string planet::getName(){
    return name;
}

void planet::setName(std::string _name){
    name = _name;
}

std::string planet::getTLDR(){
    return TLDR;
}

void planet::setTLDR(std::string _TLDR){
    TLDR = _TLDR;
}

int planet::getFuelCost(){
    return fuelcost.getFuelNeeded();
}

void planet::setFuelCost(int cost){
    fuelcost.setFuelNeeded(cost);
}
        
int planet::getHostility(){
    return hostility;
}


void planet::setHostility(int hos){
    hostility = hos;
}

void planet::printMini(){
    std::cout << "Name : " << name << std::endl;
    std::cout << "Hostility: " << hostility << std::endl;
    std::cout << "Cost: " << getFuelCost() << std::endl;
    std::cout << TLDR << std::endl;
}

std::ostream& operator<<(std::ostream& out, planet _planet){
    out << _planet.getDescription() << std::endl;
    for(int i = 0; i < _planet.numOfOptions(); i++){
        out << i << "]  " << _planet.getOption(i) << std::endl;
    }
    return out;
}

#endif