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
    Mandelbrot* mandelbrot = new Mandelbrot("Mandelbrot",0);
    fractals.push_back(circle);
    fractals.push_back(tree);
    fractals.push_back(sierpinski);
    fractals.push_back(fern);
    fractals.push_back(dragon);
    fractals.push_back(mandelbrot);
}

//--------------------------------------------------------------
void ofApp::update() {
    // All logic inside the update is for the Fractals Animations
    ticks += 1;
    
    switch (mode) {
        case '1': {
            // Circle
            if (circleAnimation == true && ticks == 60) {
                if (increase == true) {
                    increasecircle += 1;
                    if (increasecircle == 2) {
                        increase = false;
                    }
                } else {
                    increasecircle -= 1;
                    if (increasecircle == -2) {
                        increase = true;
                    }
                }
                ticks = 0;
            }
        } break;
        case '2': {
            // Tree
            if (treeAnimation == true && ticks == 50) {
                if (increase == true) {
                    increasetree += 1;
                    if (increasetree == 5) {
                        increase = false;
                    }
                } else {
                    increasetree -= 1;
                    if (increasetree == -9) {
                        increase = true;
                    }
                }
                ticks = 0;
            }
        } break;
        case '3': {
            // Sierpinski Triangle
            if (triangleAnimation == true && ticks == 50) {
                if (increase == true) {
                    increasetriangle += 1;
                    if (increasetriangle == 3) {
                        increase = false;
                    }
                } else {
                    increasetriangle -= 1;
                    if (increasetriangle == -6) {
                        increase = true;
                    }
                }
                ticks = 0;
            }
        } break;
        case '4': {
            // Barnsley Fern
            if (barleyAnimation == true && ticks == 10) {
                if (increase == true) {
                    increasebarleyfern += 1;
                    if (increasebarleyfern == 40) {
                        increase = false;
                    }
                } else {
                    increasebarleyfern -= 1;
                    if (increasebarleyfern == -5) {
                        increase = true;
                    }
                }
                ticks = 0;
            }
        } break;
        case '5': {
            // Koch SnowFlake
            if (snowAnimation == true && ticks == 60) {
                if (increase == true) {
                    increasesnowflake += 1;
                    if (increasesnowflake == 1) {
                        increase = false;
                    }
                } else {
                    increasesnowflake -= 1;
                    if (increasesnowflake == -4) {
                        increase = true;
                    }
                }
                ticks = 0;
            }
        } break;
        case '6': {
            // 3d Fractal
            if (DfractAnimation == true && ticks == 60) {
                if (increase == true) {
                    increase3dfractal += 1;
                    if (increase3dfractal == 6) {
                        increase = false;
                    }
                } else {
                    increase3dfractal -= 1;
                    if (increase3dfractal == -3) {
                        increase = true;
                    }
                }
                ticks = 0;
            }
        } break;
        case '7': {
            // Dragon Fractal
            if (dragonAnimation == true && ticks == 60) {
                if (increase == true) {
                    increaseDragonfractal += 1;
                    if (increaseDragonfractal == 6) {
                        increase = false;
                    }
                } else {
                    increaseDragonfractal -= 1;
                    if (increaseDragonfractal == -9) {
                        increase = true;
                    }
                }
                ticks = 0;
            }
        } break;
        // case '8': {
        //     //Mandelbrot
        //     if (dragonAnimation == true && ticks == 60) {
        //         if (increase == true) {
        //             increaseDragonfractal += 1;
        //             if (increaseDragonfractal == 6) {
        //                 increase = false;
        //             }
        //         } else {
        //             increaseDragonfractal -= 1;
        //             if (increaseDragonfractal == -9) {
        //                 increase = true;
        //             }
        //         }
        //         ticks = 0;
        //     }
        // } break;
    }
    
    // Reset ticks if it reaches 70
    if (ticks == 70) {
        ticks = 0;
    }
}


//--------------------------------------------------------------
void ofApp::draw() {
    ofBackgroundGradient(ofColor(65), ofColor(0), OF_GRADIENT_BAR);

    ofNoFill();
    ofSetColor(ofColor::white);
    text.drawString(s,25,60);
    dataText.drawString("Press Right Arrow to level up the Recursion",1025,30);
    dataText.drawString("Press Right Arrow to level down the Recursion",1025,60);
    dataText.drawString("Press SpaceBar to start Animation",1025,90);

    //When 'd' is pressed, extra information is drawn 
    if (extra == true){
        dataText.drawString("Press 'd' to hide fractals info!",25,90);
        dataText.drawString("1.Circle level: "+to_string(3 + increasecircle),25,120);
        dataText.drawString("2.Tree level: "+to_string(10 + increasetree),25,150);
        dataText.drawString("3.Triangle level: "+to_string(7 + increasetriangle),25,180);
        dataText.drawString("4.Barnsley level: "+to_string(10 + increasebarleyfern),25,210);
        dataText.drawString("5.SnowFlake level: "+to_string(5 + increasesnowflake),25,240);
        dataText.drawString("6.3d Fractal level: "+to_string(3 + increase3dfractal),25,270);
        dataText.drawString("7.Dragon Fractal level: "+to_string(9 + increaseDragonfractal),25,300);
           //if more fractals are added just write the name inside the string, write n plus its increase inside the to_string, and uncomment
      
        dataText.drawString("8.Mandelbrot level:  "+to_string(12+increaseMandelbrotfractal),25,330);

        dataText.drawString("Aditional Info: ",25,360);
        dataText.drawString("Ticks per second: "+to_string(ticks),25,390);
    }else{ dataText.drawString("Press 'd' to see fractals info!",25,90);}
    

    
    switch (mode) {
    case '1': {
        // Circle
        if(circleAnimation==true){
            dataText.drawString("Arrows OFF",1025,150);
            dataText.drawString("Animation ON",1025,120);
        }
        else{
            dataText.drawString("Arrows ON",1025,150);
            dataText.drawString("Animation OFF",1025,120);
        }

        s = "Circle";
        float r = 0.31 * ofGetHeight();
        fractals[0]->draw(ofGetWidth() / 2, ofGetHeight() / 2, 3+increasecircle, 0, r, 0);
        
    } break;
    case '2': {
        // Tree
        if(treeAnimation==true){
           dataText.drawString("Arrows OFF",1025,150);
            dataText.drawString("Animation ON",1025,120);
        }
        else{
            dataText.drawString("Arrows ON",1025,150);
            dataText.drawString("Animation OFF",1025,120);
        }

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
        if(triangleAnimation==true){
            dataText.drawString("Arrows OFF",1025,150);
            dataText.drawString("Animation ON",1025,120);
        }
        else{
            dataText.drawString("Arrows ON",1025,150);
            dataText.drawString("Animation OFF",1025,120);
        }

        s = "Sierpinski Triangle";
        float size = 0.88 * ofGetHeight();
        fractals[2]->draw((ofGetWidth() - size) / 2, ofGetHeight() / 2 - 0.4 * size, 7+increasetriangle, size,0,0);
       
    } break;
    case '4': {
        // Barnsley Fern
        if(barleyAnimation==true){
            dataText.drawString("Arrows OFF",1025,150);
            dataText.drawString("Animation ON",1025,120);
        }
        else{
            dataText.drawString("Arrows ON",1025,150);
            dataText.drawString("Animation OFF",1025,120);
        }

        s = "Barnsley Fern";
        fractals[3]->draw(0, 0, (10+increasebarleyfern) * 1000, 0, 0, 0);
   
    }    break;
    case '5': {
        // Koch SnowFlake
        if(snowAnimation==true){
            dataText.drawString("Arrows OFF",1025,150);
            dataText.drawString("Animation ON",1025,120);
        }
        else{
            dataText.drawString("Arrows ON",1025,150);
            dataText.drawString("Animation OFF",1025,120);
        }

        s = "Koch SnowFlake";
        SnowFlake().draw(5+increasesnowflake);
    }   break;
    case '6': {
        //3d Fractal
        if(DfractAnimation==true){
            dataText.drawString("Arrows OFF",1025,150);
            dataText.drawString("Animation ON",1025,120);
        }
        else{
            dataText.drawString("Arrows ON",1025,150);
            dataText.drawString("Animation OFF",1025,120);
        }

        s = "3d Fractal";
        Fractal3D(&cam).draw(map<string, float> {{"n", 3+increase3dfractal}, {"scale", 100}});
    }   break;
      case '7': {
        //Dragon
        if(dragonAnimation==true){
            dataText.drawString("Arrows OFF",1025,150);
            dataText.drawString("Animation ON",1025,120);
        }
        else{
            dataText.drawString("Arrows ON",1025,150);
            dataText.drawString("Animation OFF",1025,120);
        }
        s = "Dragon Curve";
        fractals[4]->draw(ofGetWidth()/2, ofGetHeight()/2-150,9+increaseDragonfractal,0, 0, 325);

    }   break;
     case '8': {
        //Mandelbrot
        if(mandelbrotAnimation==true){
            dataText.drawString("Arrows OFF",1025,150);
            dataText.drawString("Animation ON",1025,120);
        }
        else{
            dataText.drawString("Arrows ON",1025,150);
            dataText.drawString("Animation OFF",1025,120);
        }
        s = "Four Leaf Clover Mandelbrot";
        fractals[5]->draw(0, 0,15+increaseMandelbrotfractal,ofGetWidth()*0.6+300,ofGetHeight()*-0.6+1200,0);

    }   break;
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    //Switch Fractals logic
    if (key >= '1' && key <= '9'){
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

    //Increase and decrease recursions logic ------------------------------------------------
    switch (mode) {
    case '1': {
        // Circle
        if (key==OF_KEY_RIGHT && increasecircle < 2 && circleAnimation==false){
            increasecircle += 1;
        }
        else if (key==OF_KEY_LEFT && increasecircle > -2 && circleAnimation==false){
            increasecircle -= 1;
        }
    } break;
    case '2': {
        // Tree
    	if (key==OF_KEY_RIGHT && increasetree < 5 && treeAnimation==false){
            increasetree += 1;
        }
        else if (key==OF_KEY_LEFT && increasetree > -9 && treeAnimation==false){
            increasetree -= 1;
        }
    } break;
    case '3': {
        // Sierpinski Triangle
    	if (key==OF_KEY_RIGHT && increasetriangle < 3 && triangleAnimation==false){
            increasetriangle += 1;
        }
        else if (key==OF_KEY_LEFT && increasetriangle > -6 && triangleAnimation==false){
            increasetriangle -= 1;
        }
    } break;
    case '4': {
        // Barnsley Fern
        if (key==OF_KEY_RIGHT && increasebarleyfern < 40 && barleyAnimation==false){
            increasebarleyfern += 1;
        }
        else if (key==OF_KEY_LEFT && increasebarleyfern > -5 && barleyAnimation==false){
            increasebarleyfern -= 1;
        }
    }    break;
    case '5': {
        // Koch SnowFlake
        if (key==OF_KEY_RIGHT && increasesnowflake < 1 && snowAnimation==false){
            increasesnowflake += 1;
        }
        else if (key==OF_KEY_LEFT && increasesnowflake > -4 && snowAnimation==false){
            increasesnowflake -= 1;
        }
    }   break;
    case '6': {
        //3d Fractal
        if (key==OF_KEY_RIGHT && increase3dfractal < 6 && DfractAnimation==false){
            increase3dfractal += 1;
        }
        else if (key==OF_KEY_LEFT && increase3dfractal > -3 && DfractAnimation==false){
            increase3dfractal -= 1;
        }
    }   break;
     case '7': {
        //Dragon Fractal
        if (key==OF_KEY_RIGHT && increaseDragonfractal < 6 && dragonAnimation==false){
            increaseDragonfractal += 1;
        }
        else if (key==OF_KEY_LEFT && increaseDragonfractal > -9 && dragonAnimation==false){
            increaseDragonfractal -= 1;
        }  
    }break;
     case '8': {
        //Mandelbrot
        if (key==OF_KEY_RIGHT && increaseMandelbrotfractal < 10 && dragonAnimation==false){
            increaseMandelbrotfractal += 1;
        }
        else if (key==OF_KEY_LEFT && increaseMandelbrotfractal > -12 && dragonAnimation==false){
            increaseMandelbrotfractal -= 1;
        }  
    }break;
        }

         //Activate animations with space_bar ----------------------------------------
    switch (mode) {
    case '1': {
        // Circle
        if (key==' ' && circleAnimation == false){
            circleAnimation = true;
        }
        else if (key==' ' && circleAnimation == true){
            circleAnimation = false;
        }
    } break;
    case '2': {
        // Tree
    	if (key==' ' && treeAnimation == false){
            treeAnimation = true;
        }
        else if (key==' ' && treeAnimation == true){
            treeAnimation = false;
        }
    } break;
    case '3': {
        // Sierpinski Triangle
    	if (key==' ' && triangleAnimation == false){
            triangleAnimation = true;
        }
        else if (key==' ' && triangleAnimation == true){
            triangleAnimation = false;
        }
    } break;
    case '4': {
        // Barnsley Fern
        if (key==' ' && barleyAnimation == false){
            barleyAnimation = true;
        }
        else if (key==' ' && barleyAnimation == true){
            barleyAnimation = false;
        }
    }    break;
    case '5': {
        // Koch SnowFlake
        if (key==' ' && snowAnimation == false){
            snowAnimation = true;
        }
        else if (key==' ' && snowAnimation == true){
            snowAnimation = false;
        }
    }   break;
    case '6': {
        //3d Fractal
        if (key==' ' &&  DfractAnimation == false){
            DfractAnimation = true;
        }
        else if (key==' ' && DfractAnimation == true){
            DfractAnimation = false;
        }
    }   break;
    case '7':{
        //Dragon Fractal
        if (key==' ' &&  dragonAnimation == false){
            dragonAnimation = true;
        }
        else if (key==' ' && dragonAnimation == true){
            dragonAnimation = false;
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
