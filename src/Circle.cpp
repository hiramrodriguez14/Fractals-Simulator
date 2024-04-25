#include "Circle.h"


void Circle::draw(){
    float r = 0.31 * ofGetHeight();
    draw(ofGetWidth() / 2, ofGetHeight() / 2,r,this->getLevel());
}
void Circle::draw(float x, float y, float r, int n) {
   angle += 0.000001;
   ofColor color;
   if (n == 0) return;
   if (n == 1){
    color = ofColor::pink;
   }
   if (n == 2){
    color = ofColor::purple;
   }
   if (n == 3){
    color = ofColor::blue;
   }
   if (n == 4){
    color = ofColor::cyan;
   }
   if (n == 5){
    color=ofColor::green;
   }

   ofNoFill();
   ofSetColor(color);
    

    int delta = r * 0.35;
    ofDrawCircle(x, y, r);

    double angle1 = angle;
    double angle2 = PI / 3 + angle;
    double angle3 = PI + angle;
    double angle4 = 2 * PI / 3 + angle;
    double angle5 = 4 * PI / 3 + angle;
    double angle6 = 5 * PI / 3 + angle;
    draw(x + r * cos(angle1), y + r * sin(angle1), delta,n - 1);
    draw(x + r * cos(angle2), y + r * sin(angle2), delta,n - 1);
    draw(x + r * cos(angle3), y + r * sin(angle3), delta,n - 1);
    draw(x + r * cos(angle4), y + r * sin(angle4), delta,n - 1);
    draw(x + r * cos(angle5), y + r * sin(angle5), delta,n - 1);
    draw(x + r * cos(angle6), y + r * sin(angle6), delta,n - 1);


}
