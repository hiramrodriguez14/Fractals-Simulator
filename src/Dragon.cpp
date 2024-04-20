#include "Dragon.h"
#include "ofMath.h"

void Dragon::draw(float x, float y, int n,float size,float r, float length) {
    //r=angle
    if (n <=0) {
        // Base case: draw a line segment
       float endX = x+length*cos(r);
       float endY= y+length*sin(r);
        ofSetColor(255); // Set color
        ofDrawLine(x, y, endX, endY);
        return;
    } 
 
   
    draw(x,y,n-1,0,r+pi/4,length*scalingFactor);
    x+=length*scalingFactor*cos(r+pi/4);
     y+=length*scalingFactor*sin(r+pi/4);
     draw(x,y,n-1,0,r+pi/4,length*scalingFactor);
 
    }
       






