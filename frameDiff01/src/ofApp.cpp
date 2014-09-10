#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(ofColor::white);
    
    cam.initGrabber(640, 480);
    
    thisFrame.allocate(640, 480, OF_IMAGE_COLOR);
    lastFrame.allocate(640, 480, OF_IMAGE_COLOR);
    diffImage.allocate(640, 480, OF_IMAGE_COLOR);
    
    // it's a little weird but we start drawing off screen
    // so we can
    xPos = -10;
    yPos = ofGetHeight();
    graphW = 10;
    //graphH = 100;
    
    bIsHigh = false;
    bIsLow = false;
    
}

//--------------------------------------------------------------
void ofApp::update(){

    cam.update();
    
    bIsFrameNew = cam.isFrameNew();
    
    if (bIsFrameNew) {
        thisFrame.setFromPixels(cam.getPixels(), 640, 480, OF_IMAGE_COLOR);
        // make the prev MovementSum
        lastMS = movementSum;
        movementSum = 0;
        
        for (int i = 0; i < 480; i++) {
            for (int j = 0; j < 640; j++) {
                
                ofColor currColor = thisFrame.getColor(j, i);
                ofColor prevColor = lastFrame.getColor(j, i);
                
                int currR = currColor.r;
                int currG = currColor.g;
                int currB = currColor.b;
                
                int prevR = prevColor.r;
                int prevG = prevColor.g;
                int prevB = prevColor.b;
                
                int diffR = abs(currR - prevR);
                int diffG = abs(currG - prevG);
                int diffB = abs(currB - prevB);
                
                movementSum += diffR + diffG + diffB;
                
                ofColor diff = ofColor(diffR, diffG, diffB);
                diffImage.setColor(j, i, diff);
                
                lastFrame.setColor(j, i, currColor);

            }
        }
        
        // use IF statement to find out the HI LOW values
        // this is mostly to debug so we can map some
        // good values for the colors of the graph
        if (movementSum > lastMS) {
            mHIGH = movementSum;
            bIsHigh = true;
            bIsLow = false;
        } else if (movementSum < lastMS) {
            mLOW = movementSum;
            bIsLow = true;
            bIsHigh = false;
        }
        
        // scale down the movementSum A LOT
        graphH = movementSum * 0.00001;
        
        // make a new box and push it to the stack
        ofRectangle newBox;
        newBox.set(xPos, yPos-graphH, graphW, graphH);
        boxes.push_back(newBox);
        
        // map the hue to the movement scale
        // LOW = COOL
        // HIGH = WARM
        hue = ofMap(movementSum, 70000000, 100000, 255, 170);
        
        // make a new color and put it to the stack
        ofColor boxColor;
        boxColor.setHsb(hue, 255, 255);
        boxColors.push_back(boxColor);
        
        // delete the boxes from the stack
        // to make room for new boxes + colors
        for (int i = 0; i < boxes.size(); i++) {
            boxes[i].position.x += 10;
            if (boxes[i].position.x > ofGetWidth()) {
                boxes.erase(boxes.begin());
                boxColors.erase(boxColors.begin());
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(ofColor::white);
    cam.draw(0, 0, 320, 240);
    
    ofImage myImage;
    myImage.setFromPixels(diffImage.getPixels(), 640, 480, OF_IMAGE_COLOR);
    myImage.draw(320, 0, 320, 240);
    
    // let's draw ALL the boxes
    for (int i = 0; i < boxes.size(); i++) {
        ofPushStyle();
        ofSetColor(boxColors[i]);
        ofRect(boxes[i]);
        ofPopStyle();
    }
    
    // Debugging Strings!!!
    ofSetColor(ofColor::black);
    ofDrawBitmapString("Movement SUM: " + ofToString(movementSum), 10, 250);
    ofDrawBitmapString("Movement LOW: " + ofToString(bIsLow)+", "+ofToString(mLOW), 10, 275);
    ofDrawBitmapString("Movement HIGH: " + ofToString(bIsHigh)+", "+ofToString(mHIGH), 10, 300);
    ofDrawBitmapString("Last mSUM: " + ofToString(lastMS), 10, 325);
    ofDrawBitmapString("HUE: " + ofToString(hue), 10, 350);
    ofDrawBitmapString("Vector Size: " + ofToString(boxes.size()), 10, 375);


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

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
