#ifndef CHAPTER_H
#define CHAPTER_H

#include "helper.h"
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
        int fileNum;
    public:
        chapter();
        chapter(int); // opens a file with the int given and reads in files to fill the chapter with information
        chapter(std::string, std::vector<option>);
        ~chapter();
        void setChapter(int);
        void emptyChapter(); // removes everything from the chapter
        option getOption(int);
        void addOption(option); //unused
        void addBlankOption(); //unused should add a blank option after the last option that is blank
        void removeOption(int);
        std::string getDescription();
        void setDescription(std::string);
        int getFileNum();
        int numOfOptions(); // returns the size of the option vector
        friend std::ostream& operator<<(std::ostream& out, chapter chap);

};


chapter::chapter(){
    description = "";
    fileNum = -99;
}

chapter::~chapter(){}

chapter::chapter(int chapNum){
    fileNum = chapNum;
    std::ifstream inFS;
    std::string stream;
    int count = 0;

    //checks to see if you can open the file
    try{
        if( chapNum < 10){
            inFS.open("chap/events/0" + std::to_string(chapNum) + ".txt");
            //cout << "chap/30,0" << std::to_string(chapNum) << ".txt";
        }else{
            inFS.open("chap/events/" + std::to_string(chapNum) + ".txt");
        }
        if(!inFS.is_open()){
            throw std::runtime_error("No File");
        }
    }catch(std::runtime_error& excpt){
        std::cout << excpt.what() << std::endl;
    }


    std::getline(inFS, description);
    insert_nlines(description, 100);
   

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

chapter::chapter(std::string _text, std::vector<option> ops){
    description = _text;
    for(int i = 0; i < ops.size(); i++){
        options.push_back(ops.at(i));
    }
}

//works the same as the constructor 
void chapter::setChapter(int num){
    
    std::ifstream inFS;
    std::string stream;
    int count = 0;

    //checks to see if you can open the file
    try{
        if( num < 10){
            inFS.open("chap/events/0" + std::to_string(num) + ".txt");
            //cout << "chap/30,0" << std::to_string(num) << ".txt";
        }else{
            inFS.open("chap/events/" + std::to_string(num) + ".txt");
            //cout << "chap/30," << std::to_string(num) << ".txt";
        }
        if(!inFS.is_open()){
            throw std::runtime_error("No File");
        }
    }catch(std::runtime_error& excpt){
        std::cout << excpt.what() << std::endl;
    }


    std::getline(inFS, description);
    insert_nlines(description, 100);
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
            options.push_back(op_temp);
            //std::cout << options.at(count) << std::endl;

            count++;
    }
    
}

void chapter::emptyChapter(){
    description = "";
    options.clear();
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
        if(index > options.size() || index < 0){
            throw std::runtime_error("invalid index");
        }
        options.erase(options.begin() + index); // make a new class??
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

int chapter::getFileNum(){
    return fileNum;
}

int chapter::numOfOptions(){
    return options.size();
}

std::ostream& operator<<(std::ostream& out, chapter chap){
    out << chap.getDescription() << std::endl;
    for(int i = 0; i < chap.numOfOptions(); i++){
        out  << i << "]  ";
        chap.getOption(i).print();
        out << std::endl;
    }
    return out;
}

#endif