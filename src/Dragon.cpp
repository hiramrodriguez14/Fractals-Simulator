#include "Dragon.h"
#include "ofMath.h"

void Dragon::draw(){

    draw(ofGetWidth()/2, ofGetHeight()/2-150,this->getLevel(), 0, 325);
}
void Dragon::draw(float x, float y, int n,float r, float length) {
    //r=angle
    ofColor color;
    if (n == 0) {
        // Base case: draw a line segment
        float endX = x+length*cos(r);
        float endY= y+length*sin(r);

        ofDrawLine(x, y, endX, endY);
        return;
    }
    if(n==1){
        color = ofColor::cyan;
    }
    if(n==2){
        color = ofColor::lightBlue;
    }
    if(n==3){
        color = ofColor::gold;
    }
    if(n==4){
        color = ofColor::blue;
    }
    if(n>=5 && n<=10){
        color = ofColor::purple;
    }
    if(n>=11 && n<=15){
        color = ofColor::green;
    }
    
   
    draw(x,y,n-1,r+pi/4,length*scalingFactor);
    x+=length*scalingFactor*cos(r+pi/4);
    y+=length*scalingFactor*sin(r+pi/4);
    draw(x,y,n-1,r+pi/4,length*scalingFactor);

    ofNoFill();
    ofSetColor(color);
    }
       






