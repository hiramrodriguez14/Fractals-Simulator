#pragma once
#include "AbstractFractal.h"
#include "ofMain.h"
#include <complex>
#include "Mandelbrot.h"

class Mandelbrot : public AbstractFractal {
public:
    Mandelbrot(const std::string& name, int level) : AbstractFractal(name, level) {}

    void draw(float x, float y, int n,float x2,float y2);
    void draw()override;
private:

 
    float xMin = -2.5; 
    float xMax = 1.0; 
    float yMin = -1.5;
     float yMax = 1.5;

    int calculateMandelbrot(double cx, double cy, int iteration, int n);
  
};
