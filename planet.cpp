#include "planet.h"

planet::planet() : chapter(){
    name = "";
    TLDR = "";
    hostility = 0;
    fuelcost = condition();
}

planet::planet(int _chapNum){ 
    ifstream inFS;
    string stream;
    int count = 0;
    int fuel;

    try{
        inFS.open("chap/" + to_string(chapNum) + ".txt");
        if(!inFS.is_open()){
            throw runtime_error("No File");
        }
    }
    catch(runtime_error& excpt){
         cout << excpt.what() << endl;
    }
    getLine(inFS, name);
    getline(inFS,TLDR);
    inFS >> hostility;
    inFS >> fuel;
    fuelcost.setFuelNeeded(fuel);

    getline(inFS,description,'@');

        while(!inFS.eof()){
        condition cond_temp;
        consequence cons_temp;

        
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

        options[count].setCondition(cond_temp);

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

        options[count].setConsequence(cons_temp);

        count++;
    }

}

planet::planet(string _name, string _TLDR, int cost, string des, vector<option> ops, int num): chapter(des,ops,num){
    name = _name;
    TLDR = _TLDR;
    fuelcost.setFuelNeeded(cost);
}

string planet::getName(){
    return name;
}

void planet::setName(string _name){
    name = _name;
}

string planet::getTLDR(){
    return TLDR;
}

void planet::setTLDR(string _TLDR){
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
    cout << "Name : " << name << endl;
    cout << "Hostility: " << hostility << endl;
    cout << "Cost: " << getFuelCost() << endl;
    cout << TLDR;
}

ostream& operator<<(ostream& out, planet _planet){
    out << _planet.getDescription() << endl << endl;
    for(int i = 0; i < _planet.numOfOptions(); i++){
        out << i << "]  " << _planet.getOption(i) << endl;
    }
    return out;
}