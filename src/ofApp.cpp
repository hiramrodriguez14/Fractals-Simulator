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
    Dragon* dragon = new Dragon("Dragon",0);
    fractals.push_back(circle);
    fractals.push_back(tree);
    fractals.push_back(sierpinski);
    fractals.push_back(fern);
    fractals.push_back(dragon);
}

//--------------------------------------------------------------
void ofApp::update() {
}

//--------------------------------------------------------------
void ofApp::draw() {
    ofBackgroundGradient(ofColor(65), ofColor(0), OF_GRADIENT_BAR);

    ofNoFill();
    ofSetColor(ofColor::white);
    text.drawString(s,25,60);
    dataText.drawString("Press Right Arrow to level up the Recursion",1025,30);
    dataText.drawString("Press Right Arrow to level down the Recursion",1025,60);
    if (extra == true){
        dataText.drawString("Press 'd' to hide fractals info!",25,90);
        dataText.drawString("1.Circle level: "+to_string(3 + increasecircle),25,120);
        dataText.drawString("2.Tree level: "+to_string(10 + increasetree),25,150);
        dataText.drawString("3.Triangle level: "+to_string(7 + increasetriangle),25,180);
        dataText.drawString("4.Barnsley level: "+to_string(10 + increasebarleyfern),25,210);
        dataText.drawString("5.SnowFlake level: "+to_string(5 + increasesnowflake),25,240);
        dataText.drawString("6.3d Fractal level: "+to_string(3 + increase3dfractal),25,270);
        dataText.drawString("7.Dragon Fractal level: "+to_string(9 + increaseDragonfractal),25,300);
    }else{ dataText.drawString("Press 'd' to see fractals info!",25,90);}
    

    
    switch (mode) {
    case '1': {
        // Circle
        s = "Circle";
        float r = 0.31 * ofGetHeight();
        fractals[0]->draw(ofGetWidth() / 2, ofGetHeight() / 2, 3+increasecircle, 0, r, 0);
        
    } break;
    case '2': {
        // Tree
        s = "Tree";
        float length = 0.31 * ofGetHeight();
        float length2 = 0.31 * ofGetHeight()/2.7;
        float length3 = 0.31 * ofGetHeight()/2.7;
        fractals[1]->draw(ofGetWidth() / 2, ofGetHeight() - 20, 10+increasetree, 0, 1.5 * PI, length);
        fractals[1]->draw(ofGetWidth()-1260, ofGetHeight() - 20, 10+increasetree, 0, 1.5 * PI, length2);
        fractals[1]->draw(ofGetWidth()-180, ofGetHeight() - 20, 10+increasetree, 0, 1.5 * PI, length3);

    } break;
    case '3': {
        // Sierpinski Triangle
        s = "Sierpinski Triangle";
        float size = 0.88 * ofGetHeight();
        fractals[2]->draw((ofGetWidth() - size) / 2, ofGetHeight() / 2 - 0.4 * size, 7+increasetriangle, size,0,0);
       
    } break;
    case '4': {
        // Barnsley Fern
        s = "Barnsley Fern";
        fractals[3]->draw(0, 0, (10+increasebarleyfern) * 1000, 0, 0, 0);
   
    }    break;
    case '5': {
        // Koch SnowFlake
        s = "Koch SnowFlake";
        SnowFlake().draw(5+increasesnowflake);
    }   break;
    case '6': {
        //3d Fractal
        s = "3d Fractal";
        Fractal3D(&cam).draw(map<string, float> {{"n", 3+increase3dfractal}, {"scale", 100}});
    }   break;
      case '7': {
        //Dragon
        s = "Dragon";
        fractals[4]->draw(ofGetWidth()/2, ofGetHeight()/2-150,9+increaseDragonfractal,0, 0, 325);

    }   break;
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    //Switch Fractals logic
    if (key >= '1' && key <= '7'){
        mode = key;
    }

    //Extra info about fractals logic
    if (tolower(key) == 'd'){
        if (extra == true){
            extra = false;
        }
        else{
            extra = true;
        }
    }

    //Increase and decrease recursions logic ( shift + < or shift + > )
        switch (mode) {
    case '1': {
        // Circle
        if (key==OF_KEY_RIGHT && increasecircle < 2){
            increasecircle += 1;
        }
        else if (key==OF_KEY_LEFT && increasecircle > -2){
            increasecircle -= 1;
        }
    } break;
    case '2': {
        // Tree
    	if (key==OF_KEY_RIGHT && increasetree < 5){
            increasetree += 1;
        }
        else if (key==OF_KEY_LEFT && increasetree > -9){
            increasetree -= 1;
        }
    } break;
    case '3': {
        // Sierpinski Triangle
    	if (key==OF_KEY_RIGHT && increasetriangle < 3){
            increasetriangle += 1;
        }
        else if (key==OF_KEY_LEFT && increasetriangle > -6){
            increasetriangle -= 1;
        }
    } break;
    case '4': {
        // Barnsley Fern
        if (key==OF_KEY_RIGHT && increasebarleyfern < 40){
            increasebarleyfern += 1;
        }
        else if (key==OF_KEY_LEFT && increasebarleyfern > -5){
            increasebarleyfern -= 1;
        }
    }    break;
    case '5': {
        // Koch SnowFlake
        if (key==OF_KEY_RIGHT && increasesnowflake < 1){
            increasesnowflake += 1;
        }
        else if (key==OF_KEY_LEFT && increasesnowflake > -4){
            increasesnowflake -= 1;
        }
    }   break;
    case '6': {
        //3d Fractal
        if (key==OF_KEY_RIGHT && increase3dfractal < 7){
            increase3dfractal += 1;
        }
        else if (key==OF_KEY_LEFT && increase3dfractal > -9){
            increase3dfractal -= 1;
        }
    }   break;
     case '7': {
        //Dragon Fractal
        if (key==OF_KEY_RIGHT && increaseDragonfractal < 6){
            increaseDragonfractal += 1;
        }
        else if (key==OF_KEY_LEFT && increaseDragonfractal > -10){
            increaseDragonfractal -= 1;
        }  
    }break;
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
