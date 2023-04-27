#ifndef CHAPTER_H
#define CHAPTER_H

#include "option.h"
#include "consequence.h"
#include "condition.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

class chapter{
    protected:
        vector<option> options; 
        string description;
        int chapNum;
    public:
        chapter();
        chapter(int);
        chapter(string, vector<option>, int);
        option getOption(int);
        void addOption(option); // should add a option after the last option...i dont think i did it right
        void addBlankOption(); // should add a blank option after the last option that is blank
        void removeOption(int);
        string getDescription();
        void setDescription(string);
        int getChapterNum();
        void setChapterNum(int);
        int numOfOptions(); // returns the size of the vector
        friend ostream& operator<<(ostream& out, chapter chap);

};

#endif