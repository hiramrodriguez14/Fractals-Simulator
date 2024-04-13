#pragma once
#include "AbstractFractal.h"
#include "ofMain.h"

class Tree : public AbstractFractal {
public:
    Tree(const std::string& name, int level) : AbstractFractal(name, level) {} // Constructor to initialize name and level
    void draw(float x, float y, int n,float size,float r, float length)override;


};
