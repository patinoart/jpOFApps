#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    //ofBackground(127);
    ofEnableAlphaBlending();
    ofSetVerticalSync(true);
    ofSetCircleResolution(100);
    ofEnableSmoothing();
    
    // setup colors
    cNormal.setHex(0x000000);
    cHilite.setHex(0x00796a);
    cLabel.setHex(0xffffff);
    
    // Button Setup
    bSize.set(300, 50);
    bPos.set(50, 50);
    buttonLabel = "CLEAR BUTTON";
    button1.setup(buttonLabel, bPos.x, bPos.y, bSize.x, bSize.y);
    button1.style(cNormal, cHilite, cLabel);
    b1Click = false;
    
    // float Slider setup
    fSSize.set(500, 50);
    fSPos.set(50, 150);
    fLabel = "PATTERN SPEED";
    fSMove = false;
    fSlider.setup(fLabel, fSPos.x, fSPos.y, fSSize.x, fSSize.y, 0.0f, 3.0f);
    fSlider.style(cNormal, cHilite, cLabel);
    
    // int slider setup
    iSSize = fSSize;
    iSPos.set(50, 250);
    iLabel = "TAIL LENGTH";
    iSMove = false;
    iSlider.setup(iLabel, iSPos.x, iSPos.y, iSSize.x, iSSize.y, 0, 10);
    iSlider.style(cNormal, cHilite, cLabel);
    
    // dropdown menu setup
    ddSize = iSSize;
    ddPos.set(50, 350);
    list.push_back("PATTERN ONE");
    list.push_back("PATTERN TWO");
    list.push_back("PATTERN THREE");
    list.push_back("PATTERN FOUR");
    list.push_back("PATTERN FIVE");
    ddString = "CHOOSE ONE";
    bDDClick = false;
    dropdown.setup("SELECT", ddPos.x, ddPos.y, ddSize.x, ddSize.y);
    dropdown.style(cNormal, cHilite, cLabel);
    dropdown.loadItems(list);
    dropdown.itemNameSelected = ddString;    

}

//--------------------------------------------------------------
void testApp::update(){
    
    // Button Update
    button1.update(b1Click, user);
    
    // float slider
    fSlider.update(fSMove);
    
    // int slider
    iSlider.update(iSMove);
    
    // dropdown menu update
    dropdown.update(bDDClick, user);
    
    if (ddString == list.at(0)) {
        newX = 1;
        newY = 32;
    } else if (ddString == list.at(1)) {
        newX = 2;
        newY = 16;
    } else if (ddString == list.at(2)) {
        newX = 4;
        newY = 8;
    } else if (ddString == list.at(3)) {
        newX = 8;
        newY = 4;
    } else if (ddString == list.at(4)) {
        newX = 16;
        newY = 2;
    } else {
        newX = 1;
        newY = 1;
    }

}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofBackgroundGradient(ofColor(127), ofColor(0), OF_GRADIENT_CIRCULAR);
    
    // draw Lissajous pattern
    float xorig = ofGetWidth()*0.5f;
	float yorig = ofGetHeight()*0.5f;
	float angle = ofGetElapsedTimef()*fSlider.value;
	float radius = ofGetHeight()*0.5f;
	float x = xorig + radius * cos(angle * newX);
	float y = yorig + radius * -sin(angle * newY);
    int tailEnd = 100 * iSlider.value;
	
	ofPoint temp;
	temp.x = x;
	temp.y = y;
	points.push_back(temp);
	if (points.size() > tailEnd){
		points.erase(points.begin());
	}
	
	
	ofSetRectMode(OF_RECTMODE_CENTER);
	ofSetColor(255,0,127);
	ofFill();
	ofCircle(x,y,10);
	
	ofSetColor(255,255,255);
	
	ofNoFill();
	ofBeginShape();
	for (int i = 0; i < points.size(); i++){
		ofVertex(points[i].x, points[i].y);
	}
	ofEndShape();
    
    ofFill();
    ofSetRectMode(OF_RECTMODE_CORNER);
    
    // Button draw
    button1.draw();
    
    // float slider draw
    fSlider.draw();
    
    // int slider draw
    iSlider.draw();
    
    // dropdown menu draw
    dropdown.draw();

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
    
    // dropdown menu
    if (dropdown.bisHit) {
        dropdown.touchItem(x, y);
        fSMove = false;
        iSMove = false;
    }
    
    // float slider
    fSMove = true;
    if (fSMove) {
        fSlider.moveSlider(x, y);
    }
    
    // int slider
    iSMove = true;
    if (iSMove) {
        iSlider.moveSlider(x, y);
    }

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
    user.set(x, y);
    cout << "X: " << user.x << ", Y: " << user.y << endl;
    
    // button
    b1Click = true;
    
    // float slider
    fSlider.moveSlider(x, y);
    
    // int slider
    iSlider.moveSlider(x, y);
    
    // dropdown menu
    bDDClick = true;

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
    // button
    b1Click = false;
    
    if (button1.bisHit) {
        // do something
        cout << "button1 Hit" << endl;
        for (int i = 0; i < points.size(); i += 1) {
            points.erase(points.begin(), points.end());
        }
    }
    
    // float slider
    fSMove = false;
    
    // int slider
    iSMove = false;
    
    // dropdown menu
    bDDClick = false;
    if (dropdown.bisHit) {
        ddString = dropdown.itemNameSelected;
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