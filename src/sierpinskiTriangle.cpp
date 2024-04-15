#include "sierpinskiTriangle.h"


void SierpinskiTriangle::draw(float x, float y, int n,float size,float r, float length) {
    if (n == 0) {
        return;
    }
    ofColor color;
    if(n==1){
        color = ofColor::limeGreen;
    }
    if(n==2){
        color = ofColor::blue;
    }
    if(n==3){
        color = ofColor::purple;
    }
    if(n==4){
        color = ofColor::darkGreen;
    }
    if(n==5){
        color = ofColor::purple;
    }
    if(n==6){
        color = ofColor::magenta;
    }
    if(n==7){
        color = ofColor::darkMagenta;
    }
    if(n==8){
        color = ofColor::indianRed;
    }
    if(n==9){
        color = ofColor::red;
    }
    if(n==10){
        color = ofColor::black;
    }

    
    
    ofPoint a(x, y);
    ofPoint b(x + size, y);
    ofPoint c(x + size / 2, y + ((sqrt(3) * size) / 2));

    ofDrawTriangle(a, b, c);

    //Draw 1 ------------------------------------------------------------------
    draw(x, y,n - 1, size / 2,0,0);

    

    //Draw 2 ------------------------------------------------------------------
    draw((a.x + b.x) / 2, (a.y + b.y) / 2, n - 1, size / 2,0,0);

    

    //Draw 3 ------------------------------------------------------------------
    draw((a.x + c.x) / 2, (a.y + c.y) / 2, n - 1, size / 2,0,0);

    ofNoFill();
    ofSetColor(color);

}
