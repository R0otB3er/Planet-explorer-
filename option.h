#ifndef OPTION_H
#define OPTION_H

#include "condition.h"
#include "consequence.h"
#include <iostream>
#include <string>

class option{
    private:
        string text;
        condition condition_o;
        consequence consequence_o;

    public:
        option();
        option(string, condition, consequence);
        option(string, consequence);
        string getText();
        void setText(string);
        condition getCondition();
        void setCondition(condition);
        consequence getConsequence();
        void setConsequence(consequence);
        friend ostream& operator<<(ostream& out, option op);
};

#endif