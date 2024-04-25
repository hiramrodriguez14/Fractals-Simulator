#include "Tree.h"

void Tree::draw(){
        float length = 0.31 * ofGetHeight();
        float length2 = 0.31 * ofGetHeight()/2.7;
        float length3 = 0.31 * ofGetHeight()/2.7;
        draw(ofGetWidth() / 2, ofGetHeight() - 20, this->getLevel(), 1.5 * PI, length);
        draw(ofGetWidth()-1260, ofGetHeight() - 20, this->getLevel(), 1.5 * PI, length2);
        draw(ofGetWidth()-180, ofGetHeight() - 20, this->getLevel(), 1.5 * PI, length3);

}
void Tree::draw(float x, float y, int n,float r,float length) {
  if (n == 0) return;
  if (n>=1 && n<=5){
    ofNoFill();
    ofSetColor( 17*n, 255, 17*n);
  }
  if (n>=6 && n<=10){
    ofNoFill();
    ofSetColor( 17*n, 17*n, 255);
  }
  if (n>=11 && n<=15){
    ofNoFill();
    ofSetColor( 255, 17*n, 17*n);
  }
    float x2 = x + length * cos(r);
    float y2 = y + length * sin(r);

    ofDrawLine(x, y, x2, y2);

    draw(x2, y2, n - 1,r + 0.2 * PI, 0.7 * length);
    draw(x2, y2, n - 1, r - 0.2 * PI, 0.7 * length);


}
