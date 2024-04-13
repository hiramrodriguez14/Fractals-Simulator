#pragma once
#include "AbstractFractal.h"

class Fern : public AbstractFractal {
public:
    Fern(const std::string& name, int level) : AbstractFractal(name, level) {}
    virtual ~Fern() {}

    void draw(float x, float y, int n,float size,float r, float length)override; // Declare the draw function without 'override'
   
};
