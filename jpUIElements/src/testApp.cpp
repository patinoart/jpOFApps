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
    bSize.set(300, 50);
    bPos.set(50, 50);
    buttonLabel = "I'M A BUTTON";
    button1.setup(buttonLabel, bPos.x, bPos.y, bSize.x, bSize.y);
    button1.style(cNormal, cHilite, cLabel);
    b1Click = false;
    
    // float Slider setup
    fSSize.set(500, 50);
    fSPos.set(50, 150);
    fLabel = "FLOAT SLIDER";
    fSMove = false;
    fSlider.setup(fLabel, fSPos.x, fSPos.y, fSSize.x, fSSize.y, 0.0f, 1.0f);
    fSlider.style(cNormal, cHilite, cLabel);
    
    // int slider setup
    iSSize = fSSize;
    iSPos.set(50, 250);
    iLabel = "INTEGER";
    iSMove = false;
    iSlider.setup(iLabel, iSPos.x, iSPos.y, iSSize.x, iSSize.y, 0, 10);
    iSlider.style(cNormal, cHilite, cLabel);
    
    // dropdown menu setup
    ddSize = iSSize;
    ddPos.set(50, 350);
    list.push_back("ITEM ONE");
    list.push_back("ITEM TWO");
    list.push_back("ITEM THREE");
    list.push_back("ITEM FOUR");
    list.push_back("ITEM FIVE");
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

}

//--------------------------------------------------------------
void testApp::draw(){
    
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