#include "ofApp.h"
#include "SnowFlake.h"
#include "Fractal3D.h"

//--------------------------------------------------------------
void ofApp::setup() {
    cam.setUpAxis({0,0,1});
    cam.setDistance(200);
    text.load("Fonts/fractalFont.otf",40);
    dataText.load("Fonts/fractalFont.otf",15);

    //New pointers for fractal objects
    SierpinskiTriangle* sierpinski = new SierpinskiTriangle("Sierpinski", 10);
    Tree* tree = new Tree("Tree", 15);
    Fern* fern = new Fern("Bernsley Fern", 50);
    Circle* circle = new Circle("Circle", 5);
    Dragon* dragon = new Dragon("Dragon Curve",15);
    Mandelbrot* mandelbrot = new Mandelbrot("Four Leaf Clover Mandelbrot",15);
    SnowFlake* snowflake = new SnowFlake("Snowflake",6);
    Fractal3D* fractal3d = new Fractal3D("3D Fractal",9,&cam);

    //Pushing the objects on the polymorphic vector fractals
    fractals.push_back(circle);
    fractals.push_back(tree);
    fractals.push_back(sierpinski);
    fractals.push_back(fern);
    fractals.push_back(snowflake);
    fractals.push_back(fractal3d);
    fractals.push_back(dragon);
    fractals.push_back(mandelbrot);

    //Music
    backgroundMusic.load("Sounds/Summer_Night.mp3");
	backgroundMusic.setLoop(true);
	backgroundMusic.play();
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
                    if (fractals[0]->getLevel()==5) {
                        increase = false;
                    }
                    else if(increase == true){
                          fractals[0]->setLevel(fractals[0]->getLevel()+1);
                    }
                } else {
                    if (fractals[0]->getLevel() == 1) {
                        increase = true;
                    }
                    else if(increase == false){
                          fractals[0]->setLevel(fractals[0]->getLevel()-1);
                    }
                }
                ticks = 0;
            }
        } break;
        case '2': {
            // Tree
            if (treeAnimation == true && ticks == 50) {
                if (increase == true) {
                    if (fractals[1]->getLevel()==15) {
                        increase = false;
                    }
                    else if (increase == true) {
                          fractals[1]->setLevel(fractals[1]->getLevel()+1);
                    }
                } else {
                    if (fractals[1]->getLevel()== 1) {
                        increase = true;
                    }
                    else if(increase == false){
                      fractals[1]->setLevel(fractals[1]->getLevel()-1);
                    }
                }
                ticks = 0;
            }
        } break;
        case '3': {
            // Sierpinski Triangle
            if (triangleAnimation == true && ticks == 50) {
                if (increase == true) {
                    if (fractals[2]->getLevel() == 10) {
                        increase = false;
                    }
                    else if(increase == true){
                        fractals[2]->setLevel(fractals[2]->getLevel()+1);
                    }
                } else {
                    if (fractals[2]->getLevel() == 1) {
                        increase = true;
                    }
                    else if(increase == false){
                      fractals[2]->setLevel(fractals[2]->getLevel()-1);
                    }
                }
                ticks = 0;
            }
        } break;
        case '4': {
            // Barnsley Fern
            if (barleyAnimation == true && ticks == 10) {
                if (increase == true) {
                    if (fractals[3]->getLevel() == 50) {
                        increase = false;
                    }
                    else if(increase == true){
                    fractals[3]->setLevel(fractals[3]->getLevel()+1);
                    }
                } else {
                    if (fractals[3]->getLevel() == 5) {
                        increase = true;
                    }
                    else if(increase == false){
                       fractals[3]->setLevel(fractals[3]->getLevel()-1);
                    }
                }
                ticks = 0;
            }
        } break;
        case '5': {
            // Koch SnowFlake
            if (snowAnimation == true && ticks == 60) {
                if (increase == true) {
                    if (fractals[4]->getLevel() == 6) {
                        increase = false;
                    }
                    else if(increase == true){
                       fractals[4]->setLevel(fractals[4]->getLevel()+1);
                    }
                } else {
                    if (fractals[4]->getLevel() == 1) {
                        increase = true;
                    }
                    else if(increase == false){
                       fractals[4]->setLevel(fractals[4]->getLevel()-1);
                    }
                }
                ticks = 0;
            }
        } break;
        case '6': {
            // 3d Fractal
            if (DfractAnimation == true && ticks == 60) {
                if (increase == true) {
                    if (fractals[5]->getLevel() == 9) {
                        increase = false;
                    }
                    else if(increase == true){
                        fractals[5]->setLevel(fractals[5]->getLevel()+1);
                    }
                } else {
                    if (fractals[5]->getLevel() == 0) {
                        increase = true;
                    }
                    else if(increase == false){
                      fractals[5]->setLevel(fractals[5]->getLevel()-1);
                    }
                }
                ticks = 0;
            }
        } break;
        case '7': {
            // Dragon Fractal
            if (dragonAnimation == true && ticks == 60) {
                if (increase == true) {
                    if (fractals[6]->getLevel() == 15) {
                        increase = false;
                    }
                    else if(increase == true){
                       fractals[6]->setLevel(fractals[6]->getLevel()+1);
                    }
                } else {
                    if ( fractals[6]->getLevel() == 0) {
                        increase = true;
                    }
                    else if(increase == false){
                        fractals[6]->setLevel(fractals[6]->getLevel()-1);
                    }
                }
                ticks = 0;
            }
        } break;
        case '8': {
            // Mandelbrot Fractal
            if (mandelbrotAnimation == true && ticks == 40) {
                if (increase == true) {
                    if (fractals[7]->getLevel() == 15) {
                        increase = false;
                    }
                    else if(increase == true){
                fractals[7]->setLevel(fractals[7]->getLevel()+1);
                    }
                } else {
                    if (fractals[7]->getLevel() == 3) {
                        increase = true;
                    }
                    else if(increase == false){
                       fractals[7]->setLevel(fractals[7]->getLevel()-1);
                    }
                }
                ticks = 0;
            }
        } break;
        
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

    //When 'd' is pressed, extra information is drawn -----------------------------------------------------
    if (extra == true){
        dataText.drawString("Press 'd' to hide fractals info!",25,90);
        dataText.drawString("1.Circle level: "+to_string(fractals[0]->getLevel()),25,120);
        dataText.drawString("2.Tree level: "+to_string(fractals[1]->getLevel()),25,150);
        dataText.drawString("3.Triangle level: "+to_string(fractals[2]->getLevel()),25,180);
        dataText.drawString("4.Barnsley level: "+to_string(fractals[3]->getLevel()),25,210);
        dataText.drawString("5.SnowFlake level: "+to_string(fractals[4]->getLevel()),25,240);
        dataText.drawString("6.3d Fractal level: "+to_string(fractals[5]->getLevel()),25,270);
        dataText.drawString("7.Dragon Fractal level: "+to_string(fractals[6]->getLevel()),25,300);
        dataText.drawString("8.Mandelbrot level:  "+to_string(fractals[7]->getLevel()),25,330);
        dataText.drawString("Aditional Info: ",25,360);
        dataText.drawString("Ticks per second: "+to_string(ticks),25,390);

    }else{
        dataText.drawString("Press 'd' to see fractals info!",25,90);
    }
    
    //Draw logic for fractals--------------------------------------------------------------------------------
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

        s = fractals[0]->getName();
        fractals[0]->draw();
        
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

        s = fractals[1]->getName();
        fractals[1]->draw();
        
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

        s = fractals[2]->getName();
        fractals[2]->draw();
       
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

        s = fractals[3]->getName();
        fractals[3]->draw();
   
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

        s = fractals[4]->getName();
       fractals[4]->draw();
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

        s = fractals[5]->getName();
             fractals[5]->draw();
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
        s = fractals[6]->getName();
        fractals[6]->draw();

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
        s = fractals[7]->getName();
        fractals[7]->draw();

    }   break;
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    //Switch Fractals logic
    if (key >= '1' && key <= '8'){
        mode = key;
    }

    //Extra info about fractals logic ----------------------------------------
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
        if (key==OF_KEY_RIGHT && fractals[0]->getLevel() < 5 && circleAnimation==false){
            fractals[0]->setLevel(fractals[0]->getLevel()+1);
        }
        else if (key==OF_KEY_LEFT && fractals[0]->getLevel() > 1 && circleAnimation==false){
            fractals[0]->setLevel(fractals[0]->getLevel()-1);
        }
    } break;
    case '2': {
        // Tree
    	if (key==OF_KEY_RIGHT && fractals[1]->getLevel() < 15 && treeAnimation==false){
            fractals[1]->setLevel(fractals[1]->getLevel()+1);
        }
        else if (key==OF_KEY_LEFT && fractals[1]->getLevel() > 1 && treeAnimation==false){
              fractals[1]->setLevel(fractals[1]->getLevel()-1);
        }
    } break;
    case '3': {
        // Sierpinski Triangle
    	if (key==OF_KEY_RIGHT && fractals[2]->getLevel() < 10 && triangleAnimation==false){
             fractals[2]->setLevel(fractals[2]->getLevel()+1);
        }
        else if (key==OF_KEY_LEFT && fractals[2]->getLevel() > 1 && triangleAnimation==false){
              fractals[2]->setLevel(fractals[2]->getLevel()-1);
        }
    } break;
    case '4': {
        // Barnsley Fern
        if (key==OF_KEY_RIGHT && fractals[3]->getLevel() < 50 && barleyAnimation==false){
             fractals[3]->setLevel(fractals[3]->getLevel()+1);
        }
        else if (key==OF_KEY_LEFT && fractals[3]->getLevel() > 5 && barleyAnimation==false){
             fractals[3]->setLevel(fractals[3]->getLevel()-1);
        }
    }    break;
    case '5': {
        // Koch SnowFlake
        if (key==OF_KEY_RIGHT && fractals[4]->getLevel() < 6 && snowAnimation==false){
             fractals[4]->setLevel(fractals[4]->getLevel()+1);
        }
        else if (key==OF_KEY_LEFT && fractals[4]->getLevel() > 1 && snowAnimation==false){
             fractals[4]->setLevel(fractals[4]->getLevel()-1);
        }
    }   break;
    case '6': {
        //3d Fractal
        if (key==OF_KEY_RIGHT && fractals[5]->getLevel() < 9 && DfractAnimation==false){
           fractals[5]->setLevel(fractals[5]->getLevel()+1);
        }
        else if (key==OF_KEY_LEFT && fractals[5]->getLevel() > 0 && DfractAnimation==false){
             fractals[5]->setLevel(fractals[5]->getLevel()-1);
        }
    }   break;
     case '7': {
        //Dragon Fractal
        if (key==OF_KEY_RIGHT && fractals[6]->getLevel() < 15 && dragonAnimation==false){
             fractals[6]->setLevel(fractals[6]->getLevel()+1);
        }
        else if (key==OF_KEY_LEFT && fractals[6]->getLevel()  > 0 && dragonAnimation==false){
             fractals[6]->setLevel(fractals[6]->getLevel()-1);
        }  
    }break;
     case '8': {
        //Mandelbrot
        if (key==OF_KEY_RIGHT &&  fractals[7]->getLevel() < 15 && mandelbrotAnimation==false){
             fractals[7]->setLevel(fractals[7]->getLevel()+1);
        }
        else if (key==OF_KEY_LEFT &&  fractals[7]->getLevel() > 3 && mandelbrotAnimation==false){
              fractals[7]->setLevel(fractals[7]->getLevel()-1);
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
    case '8':{
        //MandelBrot Fractal
        if (key==' ' &&  mandelbrotAnimation == false){
            mandelbrotAnimation = true;
        }
        else if (key==' ' && mandelbrotAnimation == true){
            mandelbrotAnimation = false;
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
