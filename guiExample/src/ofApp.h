#pragma once

#include "ofMain.h"
#include "ofxGui.h"

#include "ofxGLWarper.h"

class ofApp : public ofBaseApp{
	
public:
	// Header reference for openRenderWindow()
	std::vector<shared_ptr<ofAppBaseWindow> > windows;

	// General program startup
	void setup();
	void update();
	void draw();
	
	// openRenderWindow() header reference
	void drawRandomInWindow(ofEventArgs & args);
	void openRenderWindow();
	
	// General program exit function.
	void exit();

	// Keybind functions
	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);		

	// openframeworks gui functions.
	void circleResolutionChanged(int & circleResolution);
	void ringButtonPressed();
	bool bHide;


	ofxFloatSlider var1;
	ofxColorSlider color;
	ofxVec2Slider center;
	ofxIntSlider circleResolution;
	ofxToggle filled;
	ofxButton twoCircles;
	ofxButton ringButton;
	ofxLabel screenSize;



	ofxPanel gui;

	ofSoundPlayer ring;

	ofTexture imageTexture;
    ofPoint points[4];
    int cornerIndex = 0;

	ofImage img;
	ofEasyCam cam;

	ofxGLWarper warper;

	private:
};

