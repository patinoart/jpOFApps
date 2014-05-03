#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    
    camW = 320;
    camH = 240;
    
    // setup the video grabber
    grabber.initGrabber(camW, camH);
    
    colorImg.allocate(camW, camH);
    colorHSVImg.allocate(camW, camH);
    
    hueImg.allocate(camW, camH);
    satImg.allocate(camW, camH);
    briImg.allocate(camW, camH);
    
    colorTrackImg.allocate(camW, camH);
    
    grayPixels = new unsigned char [camW * camH];
    
    hueRange = 20;
    satRange = 30;
    briRange = 25;
    
    hue = 0;
    sat = 0;
    bri = 0;
    
    //UI
    hueFader.set(660, 20, 255, 20);
    satFader.set(660, 60, 255, 20);
    briFader.set(660, 100, 255, 20);
    sampleSq.set(660, 140, 255, 255);

}

//--------------------------------------------------------------
void ofApp::update(){
    
    grabber.update();
    
    if (grabber.isFrameNew()){
        
        colorImg.setFromPixels(grabber.getPixelsRef());
        colorHSVImg = colorImg;
        colorHSVImg.convertRgbToHsv();
        
        colorHSVImg.convertToGrayscalePlanarImages(hueImg, satImg, briImg);
        
        unsigned char * colorHsvPixels = colorHSVImg.getPixels();
        
        for (int i = 0; i < camW*camH; i++){
            
            // since hue is cyclical:
            int hueDiff = colorHsvPixels[i*3] - hue;
            if (hueDiff < -127) {
                hueDiff += 255;
            }
            if (hueDiff > 127) {
                hueDiff -= 255;
            }
            
            if ( (fabs(hueDiff) < hueRange) &&
                (colorHsvPixels[i*3+1] > (sat - satRange) && colorHsvPixels[i*3+1] < (sat + satRange)) &&
                (colorHsvPixels[i*3+2] > (bri - briRange) && colorHsvPixels[i*3+2] < (bri + briRange))){
                
                grayPixels[i] = 255;
            } else {
                grayPixels[i] = 0;
            }
        }
        
        colorTrackImg.setFromPixels(grayPixels, camW, camH);
    }
    
     pixels = briImg.getPixels();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(255);
    colorImg.draw(0, 0, camW, camH);
    colorTrackImg.draw(0, camH, camW, camH);
    briImg.draw(0, camH*2, camW, camH);
    
    //grayscale angle image
    for (int i = 0; i < camW; i += 8) {
        for (int j = 0; j < camH; j += 8) {
            int pixelVal = pixels[j*camW+i];
            
            float angle = ofMap(pixelVal, 0, 255, 0, 180);
            
            ofPushMatrix();
            ofSetRectMode(OF_RECTMODE_CENTER);
            ofTranslate(i + camW+5, 5+j + camH*2);
            ofRotateZ(angle);
            ofRect(0, 0, 8, 2);
            ofSetRectMode(OF_RECTMODE_CORNER);
            ofPopMatrix();
        }
    }
    
    //UI
    ofSetColor(255);
    ofRect(hueFader);
    ofRect(satFader);
    ofRect(briFader);
    ofRect(sampleSq);
    
    ofSetColor(ofColor::lightBlue);
    ofRect(hueFader.x, hueFader.y, hueRange, hueFader.height);
    ofRect(satFader.x, satFader.y, satRange, satFader.height);
    ofRect(briFader.x, briFader.y, briRange, briFader.height);
    
    ofSetColor(0);
    ofDrawBitmapString("Sample Color: " + ofToString(sampleC), sampleSq.position-5);
    ofSetColor(sampleC);
    ofRect(sampleSq.x, sampleSq.y, sampleSq.width, sampleSq.height);
    

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
    
    //UI
    if(hueFader.inside(x, y)) hueRange = x - hueFader.x;
    if(satFader.inside(x, y)) satRange = x - satFader.x;
    if(briFader.inside(x, y)) briRange = x - briFader.x;
    

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    //color picking
    if (x >= 0 && x < camW && y >= 0 && y < camH) {
        int pixel = y * camW + x;
        hue = hueImg.getPixels()[pixel];
        sat = satImg.getPixels()[pixel];
        bri = briImg.getPixels()[pixel];
        sampleC.setHsb(hue, sat, bri);
    }
    
    //UI
    if(hueFader.inside(x, y)) hueRange = x - hueFader.x;
    if(satFader.inside(x, y)) satRange = x - satFader.x;
    if(briFader.inside(x, y)) briRange = x - briFader.x;
    

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
