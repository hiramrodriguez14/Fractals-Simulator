#pragma once
#include "AbstractFractal.h"
#include "ofMain.h"
class Circle: public AbstractFractal {
    protected:
      float angle = 0;
public:
    Circle(const std::string& name, int level) : AbstractFractal(name, level) {} // Constructor to initialize name and level
    void draw(float x, float y, float r, int n);
    void draw()override;
  
    
};
