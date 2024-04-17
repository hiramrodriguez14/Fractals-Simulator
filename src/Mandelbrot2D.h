#pragma once
#include "AbstractFractal.h"
#include "ofMain.h"
#include <complex>

class Mandelbrot : public AbstractFractal {
public:
    Mandelbrot(const std::string& name, int level) : AbstractFractal(name, level) {}

    void draw(float x, float y, int n,float size,float r, float length);

private:
    float maxSize;
    ofMesh mesh;

    int calculateMandelbrot(const std::complex<double>& c, const std::complex<double>& z, int maxIterations);
    void generateFractal(float x, float y, int n,float size);
    void addPointToMesh(int x, int y, int mandelbrotValue,int n);
};
