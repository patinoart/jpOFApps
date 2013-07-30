#pragma once

#include "ofMain.h"
#include "ofxRfeUIDDMenu.h"
#include "ofxRfeUIImageButton.h"
#include "ofxRfeUIButton.h"
#include "ofxRfeUISlider.h"
#include "ofxRfeUIStepSlider.h"
#include "ofxRfeUIImageButton.h"


class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    
        // User
        ofPoint user;
    
        //Colors
        ofColor cNormal, cHilite, cLabel, cGrey1, cGrey2;
        
        //Button
        ofxRfeUIButton button1, button2, button3, button4;
        ofPoint bPos, bSize;
        bool b1Click, b2Click, b3Click, b4Click;
        string buttonLabel;
        
        // Image Button
        ofxRfeUIImageButton imgButton;
        ofImage buttonImage;
        ofPixels imgButtonPixels;
        ofColor imgBCur;
        bool bImgButton;
        
        // float Slider
        ofxRfeUISlider fSlider;
        ofPoint fSPos, fSSize;
        bool fSMove;
        string fLabel;
        
        
        // int Slider
        ofxRfeUIStepSlider iSlider;
        ofPoint iSPos, iSSize;
        bool iSMove;
        string iLabel;
        
        
        // Dropdown Menu
        ofxRfeUIDDMenu dropdown;
        ofPoint ddPos, ddSize;
        bool bDDClick;
        vector <string> list;
        string ddString;
    
        // Lissajous pattern vector 
        vector < ofPoint > points;
        float newX, newY;
    
    
		
};
