#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetWindowShape(900, 900);
    ofSetRectMode(OF_RECTMODE_CENTER);
//    ofSetBackgroundAuto(false);
    ofSetCircleResolution(100);
    
    angle = 0;
    angleTwo = 0;
    angleThree = 0;
    angleFour = 0;
    angleFive = 0;
    angleSix = 0;
    angleSeven = 0;
    angleEight = 0;
    alpha = 0;
    size = 10;
    maxSize = 30;
    sizeIncrement = 1;
    
//    ofNoFill();
    sunYellow.setHex(0xFFFF33);
    mercuryGrey.setHex(0x999966);
    venusGreen.setHex(0xA3CC52);
    earthBlue.setHex(0x3399FF);
    marsRed.setHex(0xD14719);
    jupiterOrange.setHex(0xFF9933);
    saturnPaleOrange.setHex(0xFFCC80);
    uranusTurquoise.setHex(0x52CCCC);
    neptuneBlue.setHex(0x66C2E0);
    
    
    // for scaling these are all accurate numbers for diameter in Km
    // divide by 2 for radius
    // except for the sun, because it is so large
    // for viewing purposes divide by 4
    sunRad = (1377648/4);
    mercRad = (4880/2);
    venusRad = (12104/2);
    earthRad = (12756/2);
    marsRad = (6788/2);
    jupiterRad = (142740/2);
    saturnRad = (142740/2);
    uranusRad = (51152/2);
    neptuneRad = (49620/2);
    
    
    gui.setup(); // most of the time you don't need a name
    gui.add(offSet.setup( "offSet", 50, 30, 100 ));
    gui.add(scaleFactor.setup( "scaleFactor", 0.0002, 0.0001, 0.001));
    gui.add(speedFactor.setup( "speed", 1, 1, 5));
    
    bHide = true;

}

//--------------------------------------------------------------
void ofApp::update(){
    
    // in order to get different speeds, they all need to be different values
    // otherwise the all spin together
    // probably because of matrix
    angle += speedFactor;
    angleTwo += speedFactor*.95;
    angleThree += speedFactor*.9;
    angleFour += speedFactor*.85;
    angleFive += speedFactor*.8;
    angleSix += speedFactor*.75;
    angleSeven += speedFactor*.7;
    angleEight += speedFactor*.65;
    
    alpha += 1.0;
    size += sizeIncrement;
    
    if (size <= 0 || size >= maxSize) {
        sizeIncrement *= -1;
        //alpha *= -1;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    //my solution
//    ofPushMatrix();
//        ofTranslate(ofGetWidth()*0.5, ofGetHeight()*0.5);
//        //ofRotate(30);
//        ofSetColor(ofColor::indianRed);
//        ofCircle(0, 0, 50, 50);
//    
//    
//        ofSetColor(ofColor::coral);
//        ofRotate(angle);
//        ofTranslate(200, 0);
//        ofCircle(0, 0, 25);
//    
//
//        ofTranslate(50, 0);
//    
//        ofSetColor(ofColor::blanchedAlmond);
//        ofCircle(0, 0, 5);
//ofRotate(angle*10);
//    ofPopMatrix();
    
    // from Bernardo Walkthrough
    
//    ofSetColor(alpha, 0, 0);
    
//    ofTranslate(ofGetWidth()*0.5, ofGetHeight()*0.5);
//    
//   
//    ofSetColor(ofColor::indianRed);
//    ofCircle(0, 0, 50);
//    
//    ofRotate(angle);
//    ofTranslate(250, 0);
//    ofSetColor(ofColor::coral);
//    ofCircle(0, 0, 30);
//    
//    ofPushMatrix();
//    ofRotate(angleTwo);
//    ofSetColor(ofColor::blanchedAlmond);
//    ofCircle(100, 0, 10);
//    ofPopMatrix();
//    
//    ofCircle(0, 250, 30);
    
    ofColor gunMetal;
    gunMetal.setHex(0x2C3539);
    ofBackgroundGradient(ofColor::black, gunMetal);

    
    //solar system test
    //Sun in the center
    ofPushMatrix();
    ofTranslate(ofGetWidth()*0.5, ofGetHeight()*0.5);
    ofSetColor(sunYellow);
    ofCircle(0, 0, sunRad * scaleFactor);
    
    //Mercury
    ofPushMatrix();
    ofRotate(angle);
    ofTranslate(offSet, 0);
    ofSetColor(mercuryGrey);
    ofCircle(0, 0, mercRad * scaleFactor);
    ofPopMatrix();
    
    //Venus
    ofPushMatrix();
    ofRotate(angleTwo);
    ofTranslate(offSet*2, 0);
    ofSetColor(venusGreen);
    ofCircle(0, 0, venusRad * scaleFactor);
    ofPopMatrix();
    
    //Earth
    ofPushMatrix();
    ofRotate(angleThree);
    ofTranslate(offSet*3, 0);
    ofSetColor(earthBlue);
    ofCircle(0, 0, earthRad * scaleFactor);
    ofPopMatrix();
    
    //Mars
    ofPushMatrix();
    ofRotate(angleFour);
    ofTranslate(offSet*4, 0);
    ofSetColor(marsRed);
    ofCircle(0, 0, marsRad * scaleFactor);
    ofPopMatrix();
    
    //Asteroid Belt
    
    //Jupiter
    ofPushMatrix();
    ofRotate(angleFive);
    ofTranslate(offSet*5, 0);
    ofSetColor(jupiterOrange);
    ofCircle(0, 0, jupiterRad * scaleFactor);
    ofPopMatrix();
    
    //Saturn
    ofPushMatrix();
    ofRotate(angleSix);
    ofTranslate(offSet*6, 0);
    ofSetColor(saturnPaleOrange);
    ofCircle(0, 0, saturnRad * scaleFactor);
    ofPopMatrix();
    
    //Uranus
    ofPushMatrix();
    ofRotate(angleSeven);
    ofTranslate(offSet*7, 0);
    ofSetColor(uranusTurquoise);
    ofCircle(0, 0, uranusRad * scaleFactor);
    ofPopMatrix();
    
    //Neptune
    ofPushMatrix();
    ofRotate(angleEight);
    ofTranslate(offSet*8, 0);
    ofSetColor(neptuneBlue);
    ofCircle(0, 0, neptuneRad * scaleFactor);
    ofPopMatrix();
    
    ofPopMatrix();
    
    
    if (bHide) {
        gui.draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
	if(key == 'h') {
		bHide = !bHide;
	}
    if(key == 's') {
		gui.saveToFile("settings.xml");
	}
	if(key == 'l') {
		gui.loadFromFile("settings.xml");
	}

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
