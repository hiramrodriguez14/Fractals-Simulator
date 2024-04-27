#include "Mandelbrot.h"

/*PD: This code didn't worked as expected, if you look at the internet for a mandelbrot set, it doesn't 
look alike our mandelbrot, but ours turned to look like a four leaf clover!!!Interesting right?*/

void Mandelbrot::draw(){

    draw(0, 0,this->getLevel(),ofGetWidth()*0.6+300,ofGetHeight()*-0.6+1200);

}
void Mandelbrot::draw(float x, float y, int n,float x2,float y2) {
    ofColor color;
    if(n==3){
        color = ofColor::gold;
    }
    if(n==4){
        color = ofColor::blue;
    }
    if(n==5){
        color = ofColor::purple;
    }
    if(n==6){
        color = ofColor::darkViolet;
    }
    if(n>=7 && n<=9){
        color = ofColor::crimson;
    }
    if(n>=10 && n<=12){
        color = ofColor::silver;
    }
    if(n>=13 && n<=15){
        color = ofColor::green;
    }


    double dx = (xMax - xMin) /x2; 
    double dy = (yMax - yMin) / y2;    
    
    // Iteration on every pixel
    for (int i = 0; i < x2; i++) {
        for (int j = 0; j < y2; j++) {
         
         //Complex variables
            double cx = xMin + (x + i) * dx;
            double cy = yMin + (y + j) * dy;

            // Calculate if the point is part of the mandelbrot set
            int iteration = calculateMandelbrot(cx, cy, 0, n);

            if (iteration == n) {
                ofNoFill();
                ofSetColor(color);
                ofDrawRectangle(x + i, y + j, 1, 1);
            }
    }

}
}

int Mandelbrot::calculateMandelbrot(double cx, double cy,int iteration,int n) {
    // Base case: recursion finishes if condition is met or maximum iterations reached
    if (iteration >= n || (cx * cx + cy * cy) >= 4) {
        return iteration;
    }

   
    double x = cx * cx - cy * cy + cx;
    double y = 2 * cx * cy + cy;

    // Recursive call with updated complex coordinates and iteration count
    return calculateMandelbrot(x, y, iteration + 1,n);
}
