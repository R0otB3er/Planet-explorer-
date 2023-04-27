#ifndef CHAPTER_H
#define CHAPTER_H

#include "option.h"
#include "consequence.h"
#include "condition.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>

class chapter{
    protected:
        std::vector<option> options; 
        std::string description;
        int chapNum;
    public:
        chapter();
        chapter(int);
        chapter(std::string, std::vector<option>, int);
        ~chapter();
        option getOption(int);
        void addOption(option); // should add a option after the last option...i dont think i did it right
        void addBlankOption(); // should add a blank option after the last option that is blank
        void removeOption(int);
        std::string getDescription();
        void setDescription(std::string);
        int getChapterNum();
        void setChapterNum(int);
        int numOfOptions(); // returns the size of the vector
        friend std::ostream& operator<<(std::ostream& out, const chapter chap);

};


chapter::chapter(){
    description = "";
    chapNum = -1;
}

chapter::~chapter(){}

chapter::chapter(int chapNum){
    std::ifstream inFS;
    std::string stream;
    int count = 0;

    //checks to see if you can open the file
    try{
        inFS.open("chap/" + std::to_string(chapNum) + ".txt");
        if(!inFS.is_open()){
            throw std::runtime_error("No File");
        }
    }catch(std::runtime_error& excpt){
        std::cout << excpt.what() << std::endl;
    }


    std::getline(inFS, description);
    std::cout<< "grabbed description" << std:: endl;
    
   

        while(!inFS.eof()){
        condition cond_temp;
        consequence cons_temp;
        getline(inFS,stream,'@');
        options[count].setText(stream); 
        
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

chapter::chapter(std::string _text, std::vector<option> ops, int num){
    chapNum = num;
    description = _text;
    for(int i = 0; i < ops.size(); i++){
        options.push_back(ops.at(i));
    }
}

option chapter::getOption(int index){ // STARTS AT 0!!!!
    try{
        if(index > options.size()){
            throw std::runtime_error("invalid index");
        }
         return options.at(index); 
    }
    catch(std::runtime_error& excpt){
        std::cout << excpt.what() << std::endl;
    }
    option blank;
    return blank;
}

void chapter::addOption(option op){
    options.push_back(op);
}

void chapter::removeOption(int index){
    try{
        if(index > options.size()){
            throw std::runtime_error("invalid index");
        }
 //       options.remove(index); // make a new class??
    }
    catch(std::runtime_error& excpt){
        std::cout << excpt.what() << std::endl;
    }
}
        
std::string chapter::getDescription(){
    return description;
}

void chapter::setDescription(std::string text){
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

std::ostream& operator<<(std::ostream& out, const chapter chap){
    out << chap.getDescription() << std::endl << std::endl;
    std::cout << "here?";
    for(int i = 0; i < chap.numOfOptions(); i++){
        out << i << "]  " << chap.getOption(i) << std::endl;
    }
    return out;
}

#endif