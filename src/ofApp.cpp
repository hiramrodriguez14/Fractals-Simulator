#include "ofApp.h"
#include "SnowFlake.h"
#include "Fractal3D.h"

//--------------------------------------------------------------
void ofApp::setup() {
    cam.setUpAxis({0,0,1});
    cam.setDistance(200);
    text.load("Fonts/fractalFont.otf",40);
    dataText.load("Fonts/fractalFont.otf",15);

    SierpinskiTriangle* sierpinski = new SierpinskiTriangle("Sierpinski", 0);
    Tree* tree = new Tree("Tree", 0);
    Fern* fern = new Fern("Bernsley Fern", 0);
    Circle* circle = new Circle("Circle", 0);

    fractals.push_back(circle);
    fractals.push_back(tree);
    fractals.push_back(sierpinski);
    fractals.push_back(fern);
}

//--------------------------------------------------------------
void ofApp::update() {
}

//--------------------------------------------------------------
void ofApp::draw() {
    ofBackgroundGradient(ofColor(65), ofColor(0), OF_GRADIENT_BAR);

    text.drawString("(Insert Fractal Name Here)",25,60);

    ofNoFill();
    switch (mode) {
    case '1': {
        // Circle
       
        float r = 0.31 * ofGetHeight();
        fractals[0]->draw(ofGetWidth() / 2, ofGetHeight() / 2,3,0,r, 0);
        
    } break;
    case '2': {
        // Tree
    float length = 0.31 * ofGetHeight();
      float length2 = 0.31 * ofGetHeight()/2.7;
       float length3 = 0.31 * ofGetHeight()/2.7;
        fractals[1]->draw(ofGetWidth() / 2, ofGetHeight() - 20, 10,0,1.5 * PI, length);
        fractals[1]->draw(ofGetWidth()-1195, ofGetHeight() - 20, 10,0,1.5 * PI, length2);
        fractals[1]->draw(ofGetWidth()-250, ofGetHeight() - 20, 10,0,1.5 * PI, length3);

    } break;
    case '3': {
        // Sierpinski Triangle
        float size = 0.88 * ofGetHeight();
        fractals[2]->draw((ofGetWidth() - size) / 2, ofGetHeight() / 2 - 0.4 * size,7, size,0,0);
       
    } break;
    case '4': {
        // Barnsley Fern
        fractals[3]->draw(0, 0, 10 * 1000,0,0,0);
   
    }    break;
    case '5': {
        // Koch SnowFlake
        SnowFlake().draw();
    }   break;
    case '6': {
        //3d Fractal
        Fractal3D(&cam).draw(map<string, float> {{"n", 3}, {"scale", 100}});
    }   break;
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    if (key >= '1' && key <= '6'){
        mode = key;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {
}
