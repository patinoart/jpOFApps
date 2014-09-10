#pragma once

#include "ofMain.h"

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
    
    // this is Detroit!
    ofVideoGrabber cam;
    
    bool bIsFrameNew;
    
    ofPixels    thisFrame,
                lastFrame,
                diffImage;
    
    // variables to find the HI / LOW values
    int movementSum, lastMS, mLOW, mHIGH;
    bool bIsHigh, bIsLow;
    
    // vector for the graph
    vector<ofRectangle> boxes;
    int xPos, yPos;
    float graphW, graphH;
    
    // vector to add individual colors
    vector<ofColor> boxColors;
    float hue;
		
};
