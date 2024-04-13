#pragma once

#include "ofMain.h"

class Fractal{


public:
virtual void draw()=0;
virtual string getName()=0;
virtual int getLevel()=0;
virtual void setName()=0;
};
