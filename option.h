#ifndef OPTION_H
#define OPTION_H

#include "condition.h"
#include "consequence.h"
#include <iostream>
#include <string>

class option{
    private:
        std::string text;
        condition condition_o;
        consequence consequence_o;

    public:
        option();
        option(std::string, condition, consequence);
        option(std::string, consequence);
        ~option();
        void print();
        std::string getText();
        void setText(std::string);
        condition getCondition();
        void setCondition(condition);
        consequence getConsequence();
        void setConsequence(consequence);
        friend std::ostream& operator<<(std::ostream& out, option op);
};



option::option(){
    text = "";
    condition_o;
    consequence_o;
}

option::~option(){}

option::option(std::string _text, condition cond, consequence cons){
    text = _text;
    condition_o = cond;
    consequence_o = cons;
}

option::option(std::string _text, consequence cons){
    text = _text;
    condition_o;
    consequence_o = cons;
}

std::string option::getText(){
    return text;
}

void option::setText(std::string txt){
    text = txt;
}

condition option::getCondition(){
    return condition_o;
}

void option::setCondition(condition cond){
    condition_o = cond;
}

consequence option::getConsequence(){
    return consequence_o;
}

void option::setConsequence(consequence cons){
    consequence_o = cons;
}

void option::print(){
    std::cout<< text;
    if(condition_o.getFuelNeeded() > 0 || condition_o.getCrewNeeded() > 0){
        std::cout << " (" << condition_o << ") ";
    }
    std::cout << consequence_o;
}

std::ostream& operator<<(std::ostream& out, option op){
    out<< op.getText();
    if(op.getCondition().getFuelNeeded() > 0 || op.getCondition().getCrewNeeded() > 0){
        out << " ( " << op.getCondition() << " )";
    }
    //out << op.getConsequence();
    return out;
}


#endif