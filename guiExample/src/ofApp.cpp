#include "ofApp.h"
#include "ofAppGLFWWindow.h"
 
//--------------------------------------------------------------
void ofApp::setup(){
	// Sets Application Title
	ofSetWindowTitle("Photon");

	// Sets Application Icon
	ofAppGLFWWindow* win; 
	win = dynamic_cast<ofAppGLFWWindow *> (ofGetWindowPtr());
	win->setWindowIcon("icon.png"); 

	// Running at 60
	ofSetVerticalSync(true);
	
	// Window Size
	ofSetWindowShape(1920, 1080);
	
	// Window stars at middle of screen
	ofSetWindowPosition(ofGetScreenWidth()/2 - ofGetWidth()/2, ofGetScreenHeight()/2 - ofGetHeight()/2);
	//ofSetWindowPosition(960,540);

	// Spawns window a second during start up
	//openRenderWindow();

	// Turns off Esc Quit
	ofSetEscapeQuitsApp(false);

	// Background color
	ofBackground(0,0,0);
	
	// Loads gui for use but is commented out in draw.
	gui.setup();
    gui.add(color.setup("color", 1, 10, 255));

	// Load Image for manipulation at corner points refer to keybinds below.
	
	ofLoadImage(imageTexture, "test.png");
	/*	
    points[0].x = 100; points[0].y = 100;
    points[1].x = 600; points[1].y = 100;
    points[2].x = 600; points[2].y = 600;
    points[3].x = 100; points[3].y = 600;
	*/

	
	// Load Image in different format.
	img.load("test.png");

	//test
	//we run at 60 fps!
    warper.setup(70, 120, img.getWidth(), img.getHeight()); //initializates ofxGLWarper
	warper.activate();// this allows ofxGLWarper to automatically listen to the mouse and keyboard input and updates automatically it's matrixes.

	warper.drawSettings.bDrawRectangle = true; // default: true. Check drawSettings options for customization

}

//--------------------------------------------------------------
void ofApp::exit(){
}

//--------------------------------------------------------------
void ofApp::openRenderWindow() {
	// Magical Window Spawner~
	ofGLFWWindowSettings settings;
	settings.setSize(540, 960);
	settings.setPosition(ofVec2f(ofGetScreenWidth()/2 - ofGetWidth()/2 + 550, ofGetScreenHeight()/2 - ofGetHeight()/2));
	//ofSetWindowPosition();
	//settings.resizable = false;
	//settings.shareContextWith = &ofApp;
	//settings.setGLVersion(4, 5);
	windows.push_back(ofCreateWindow(settings));
	//windows.back()->setVerticalSync(false);

	// Sets Application Title
	ofSetWindowTitle("Photon2");

	// Sets Application Icon
	ofAppGLFWWindow* win; 
	win = dynamic_cast<ofAppGLFWWindow *> (ofGetWindowPtr());
	win->setWindowIcon("icon.png"); 

	// Representation of how to send function data between windows?
	ofAddListener(windows.back()->events().draw, this, &ofApp::drawRandomInWindow);

}
//--------------------------------------------------------------
void ofApp::drawRandomInWindow(ofEventArgs &args) {
	// Refer to bottom of openRenderWindow()
}
//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	// Draw() updates function.

	// Draws circle in middle of canvas
	float xCenter = ofGetWidth() / 2;
    float yCenter = ofGetHeight() / 2;
    ofDrawCircle(xCenter, yCenter, 4);

	// Draws the image that can be manipulated with keybinds.
	//imageTexture.draw(points[0], points[1], points[2], points[3]);

	// Sets some kind of poly mode idk?
	//ofSetPolyMode(OF_POLY_WINDING_NONZERO);
	
	// Basic shape drawing
	/*
	ofBeginShape();
		ofVertex(25,0);
  		ofVertex(0,50);
		ofVertex(25,100);
		ofVertex(50,50);
	ofEndShape();
	*/
	
	/*
	ofBeginShape();
		ofVertex(400,135);
  		ofVertex(215,135);
		ofVertex(365,25);
  		ofVertex(305,200);
  		ofVertex(250,25);
	ofEndShape();
	*/

	// Uncomment to show built in side gui that changes background color.
	//gui.draw();

	// Projection Mapping - 3d transform
	/*
	cam.begin();
	img.draw(0,0);
	cam.end();
	*/

	// Projection Mapping - interesting perspective change
	/*
	cam.begin();
	ofPushMatrix();
	ofRotate(30,1,1,0);
	img.draw(20,50,10);
	ofPopMatrix();
	cam.end();
	*/

	//test
	warper.begin();
	
	img.draw(70, 120);

	warper.end();
	
	stringstream ss;
	ss << "It finally works x_x some how." << endl;
	ss << "Move the points or hold shift and drag the image to move it.";
	ofDrawBitmapString(ss.str(), 20, 100);

}

//--------------------------------------------------------------
// Basic image manipulation key binds.
void ofApp::keyPressed(int key){
	/*
	if (key == '1') {
        cornerIndex = 0;
    }
    if (key == '2') {
        cornerIndex = 1;
    }
    if (key == '3') {
        cornerIndex = 2;
    }
    if (key == '4') {
        cornerIndex = 3;
    }
    
    if (key == OF_KEY_LEFT) {
        points[cornerIndex].x -= 30;
    }
    if (key == OF_KEY_RIGHT) {
        points[cornerIndex].x += 30;
    }
    if (key == OF_KEY_UP) {
        points[cornerIndex].y -= 30;
    }
    if (key == OF_KEY_DOWN) {
        points[cornerIndex].y += 30;
    }
	*/

	switch (key) {
	case ' ':
		if (warper.isActive()) {
			warper.deactivate();
		}else {
			warper.activate();
		}

		break;
			default:
		break;
	}
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
