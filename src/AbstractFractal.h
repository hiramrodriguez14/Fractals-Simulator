#pragma once

#include "ofMain.h"
#include "Fractal.h"

class AbstractFractal:public Fractal{

protected:
string name;
int level;

public:
AbstractFractal(){}
AbstractFractal(string name,int level){
    this->name=name;
    this->level=level;
}
string getName(){return name;}
int getLevel(){return level;}
void setName(){this->name=name;}

};
