#pragma once
#include "AbstractFractal.h"
#include "ofMain.h"

class SierpinskiTriangle : public AbstractFractal {
    protected:
    
public:
    SierpinskiTriangle(const std::string& name, int level) : AbstractFractal(name, level) {} // Constructor to initialize name and level
    void draw(float x, float y, int n, float size);
    void draw()override;

 
};
