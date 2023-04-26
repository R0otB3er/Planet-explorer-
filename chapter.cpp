#include "chapter.h"

chapter::chapter(){
    description = "";
    chapNum = -1;
}

chapter::chapter(int chapNum){
    ifstream inFS;
    string stream;
    int count = 0;

    //checks to see if you can open the file
    try{
        inFS.open("chap/" + to_string(chapNum) + ".txt");
        if(!inFS.is_open()){
            throw runtime_error("No File");
        }
    }

    getline(inFS, description);

    catch(runtime_error& excpt){
         cout << excpt.what() << endl;
    }

    getline(inFS,stream,'@');
    options[count].setText(string); 

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

chapter::chapter(string _text, vector<option> ops, int num){
    chapNum = num;
    description = _text;
    for(int i = 0; i < ops.size(); i++){
        options.push_back(ops.at(i));
    }
}

option chapter::getOption(int index){ // STARTS AT 0!!!!
    try{
        if(index > options.size()){
            throw runtime_error("invalid index");
        }
         return options.at(index); 
    }
    catch(runtime_error& excpt){
        cout << excpt.what() << endl;
    }
}

void chapter::addOption(option op){
    options.push_back(op);
}

void chapter::removeOption(int index){
    try{
        if(index > options.size()){
            throw runtime_error("invalid index");
        }
 //       options.remove(index); // make a new class??
    }
    catch(runtime_error& excpt){
        cout << excpt.what() << endl;
    }
}
        
string chapter::getDescription(){
    return description;
}

void chapter::setDescription(string text){
    description = text;
}
        
int chapter::getChapterNum(){
    return chapNum;
}
        
void chapter::setChapterNum(int num){
    chapNum = num;
}

int chapter::numOfOptions(){
    return options.size();
}

ostream& operator<<(ostream& out, chapter chap){
    out << chap.getDescription() << endl << endl;
    for(int i = 0; i < chap.numOfOptions(); i++){
        out << i << "]  " << chap.getOption(i) << endl;
    }
    return out;
}