#include "Tree.h"


void Tree::draw(float x, float y, int n,float size,float r, float length) {
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

    draw(x2, y2, n - 1,0,r + 0.2 * PI, 0.7 * length);
    draw(x2, y2, n - 1,0, r - 0.2 * PI, 0.7 * length);


}
