#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"

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
    
    int camW, camH;
    
    ofVideoGrabber grabber;
    ofxCvColorImage colorImg;
    ofxCvColorImage colorHSVImg;
    
    ofxCvGrayscaleImage hueImg;
    ofxCvGrayscaleImage satImg;
    ofxCvGrayscaleImage briImg;
    
    
    unsigned char * grayPixels;
    ofxCvGrayscaleImage colorTrackImg;
    
    unsigned char * pixels;
    
    
    // for tracking
    int hue, sat, bri;
    ofColor sampleC;
    
    int hueRange;
    int satRange;
    int briRange;
    
    //UI
    ofRectangle hueFader;
    ofRectangle satFader;
    ofRectangle briFader;
    ofRectangle sampleSq;
    
    
		
};
