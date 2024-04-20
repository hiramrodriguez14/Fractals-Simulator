#pragma once

#include <cmath>
#include "Fractal.h"
#include "AbstractFractal.h"
#include "Tree.h"
#include "Circle.h"
#include "sierpinskiTriangle.h"
#include "BarnsleyFern.h"
#include "ofMain.h"
#include "Dragon.h"
class ofApp : public ofBaseApp {
  private:
    char mode = '1';
    string s = "Fractals";
    float increasecircle = 0;
    float increasetree = 0;
    float increasetriangle = 0;
    float increasebarleyfern = 0;
    float increasesnowflake = 0;
    float increase3dfractal = 0;
    float increaseDragonfractal=0;
     std::vector<Fractal*> fractals;
  public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);



    ofEasyCam cam;
    ofTrueTypeFont text;
    ofTrueTypeFont dataText;
};
