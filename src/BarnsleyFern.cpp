#include "BarnsleyFern.h"

void Fern::draw(){
    draw(0, 0, (this->getLevel()) * 1000);
}
void Fern::draw(float x, float y, float n) {
    if (n == 0) return;
    
    ofColor color;
    float rad = ofRandom(1);

    float px = ofMap(x, -2.1820, 2.6558, 0, ofGetWidth());
    float py = ofMap(y, 0, 9.9983, ofGetHeight(), 0);
    
    if (n>=5000 && n<15000){
        ofFill();
        ofSetColor(ofColor::green);
        ofDrawCircle(px, py, 0.6);
        ofSetColor(ofColor::white);
    }
    else if (n>=15000 && n<25000){
        ofFill();
        ofSetColor(ofColor::blue);
        ofDrawCircle(px, py, 0.6);
        ofSetColor(ofColor::white);
    }
    else if (n>=25000 && n<35000){
        ofFill();
        ofSetColor(ofColor::purple);
        ofDrawCircle(px, py, 0.6);
        ofSetColor(ofColor::white);
    }
    else if (n>=35000 && n<45000){
        ofFill();
        ofSetColor(ofColor::pink);
        ofDrawCircle(px, py, 0.6);
        ofSetColor(ofColor::white);
    }
    else if (n>=45000 && n<=50000){
        ofFill();
        ofSetColor(ofColor::red);
        ofDrawCircle(px, py, 0.6);
        ofSetColor(ofColor::white);
    }
    else{
        ofFill();
        ofSetColor(ofColor::white);
        ofDrawCircle(px, py, 0.6);
        ofSetColor(ofColor::white);
    }

    if (rad < 0.01)
        draw(0, 0.16 * y, n - 1);

    else if (rad < 0.86)
        draw(0.85 * x + 0.04 * y, -0.04 * x + 0.85 * y + 1.6, n - 1);

    else if (rad < 0.93)
        draw(0.2 * x - 0.26 * y, 0.23 * x + 0.22 * y + 1.6, n - 1);

    else
        draw(-0.15 * x + 0.28 * y, 0.26 * x + 0.24 * y + 0.44, n - 1);
}
