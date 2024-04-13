#pragma once
#include <string>
#include "ofMain.h"

// Interface for Fractal
class Fractal {
public:
    virtual void draw() = 0; 
    virtual string getName() const = 0; 
    virtual int getLevel() const = 0; 
    virtual void setName(const string& name) = 0; 
    virtual void setLevel(int level) = 0; 
    virtual ~Fractal() {} 
};
