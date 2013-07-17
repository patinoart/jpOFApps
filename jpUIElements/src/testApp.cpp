#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofBackground(127);
    ofSetCircleResolution(100);
    
    // setup colors
    cNormal.setHex(0x000000);
    cHilite.setHex(0x00796a);
    cLabel.setHex(0xffffff);
    
    // Button Setup
    bSize.set(500, 50);
    bPos.set(ofGetWidth()*0.5 - bSize.x*0.5, ofGetHeight()*0.5 - bSize.y*0.5);
    buttonLabel = "Click Me!";
    button1.setup(buttonLabel, bPos.x, bPos.y, bSize.x, bSize.y);
    button1.style(cNormal, cHilite, cLabel);
    b1Click = false;

}

//--------------------------------------------------------------
void testApp::update(){
    
    // Button Update
    button1.update(b1Click, user);

}

//--------------------------------------------------------------
void testApp::draw(){
    
    // Button draw
    button1.draw();

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
    user.set(x, y);
    cout << "X: " << user.x << ", Y: " << user.y << endl;
    
    // button
    b1Click = true;

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
    // button
    b1Click = false;
    
    if (button1.bisHit) {
        // do something
        cout << "button1 Hit" << endl;
    }

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}