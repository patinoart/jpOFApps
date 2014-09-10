#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    float alpha;
    float size, maxSize, sizeIncrement;
    
    float angle, angleTwo, angleThree , angleFour, angleFive, angleSix, angleSeven, angleEight;
    
    ofColor sunYellow,
            mercuryGrey,
            venusGreen,
            earthBlue,
            marsRed,
            jupiterOrange,
            saturnPaleOrange,
            uranusTurquoise,
            neptuneBlue;
    
    float   sunRad,
            mercRad,
            venusRad,
            earthRad,
            marsRad,
            jupiterRad,
            saturnRad,
            uranusRad,
            neptuneRad;
    
    ofxFloatSlider  offSet,
                    scaleFactor,
                    speedFactor;
    ofxPanel gui;
    bool bHide;
		
};
