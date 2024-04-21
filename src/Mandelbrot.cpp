#include "Mandelbrot.h"

void Mandelbrot::draw(float x, float y, int n,float size,float r, float length) {
       double dx = (xMax - xMin) / size; 
    double dy = (yMax - yMin) / r;    

    // Loop atraves de cada píxel 
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < r; j++) {
         
            double cx = xMin + (x + i) * dx;
            double cy = yMin + (y + j) * dy;

            // Calculate if the point is part of the mandelbrot set
            int iteration = calculateMandelbrot(cx, cy, 0, n);

             if (iteration == n) {
                ofSetColor(255);
            ofDrawRectangle(x + i, y + j, 1, 1);
        }
    }

}
}

int Mandelbrot::calculateMandelbrot(double cx, double cy,int iteration,int n) {
    // Base case: escape condition is met or maximum iterations reached
    if (iteration >= n || (cx * cx + cy * cy) >= 4) {
        return iteration;
    }

    // Perform Mandelbrot iteration
    double x = cx * cx - cy * cy + cx;
    double y = 2 * cx * cy + cy;

    // Recursive call with updated complex coordinates and iteration count
    return calculateMandelbrot(x, y, iteration + 1,n);
}
