#pragma once
#include "AbstractFractal.h"
#include "ofMain.h"
#include <complex>
#include <math.h>
class Dragon : public AbstractFractal {
public:
    Dragon(const std::string& name, int level) : AbstractFractal(name, level) {}
      void draw(float x, float y, int n,float r, float length);
      void draw()override;
  
private:

   float scalingFactor = sqrt(2.0)/2;
   float pi=PI;
};

  


