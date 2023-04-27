#include "option.h"

//MOVED TO OPTION.H

option::option(){
    text = "";
    condition_o;
    consequence_o;
}

option::option(string _text, condition cond, consequence cons){
    text = _text;
    condition_o = cond;
    consequence_o = cons;
}

option::option(string _text, consequence cons){
    text = _text;
    condition_o;
    consequence_o = cons;
}

string option::getText(){
    return text;
}

void option::setText(string txt){
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

ostream& operator<<(ostream& out, option op){
    out<< op.getText();
    out << " ( " << op.getCondition() << " )";
    return out;
}
