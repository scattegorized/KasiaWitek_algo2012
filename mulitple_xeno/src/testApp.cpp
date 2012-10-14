#include "testApp.h"
#include "ofMain.h"

//--------------------------------------------------------------
void testApp::setup(){

	
    
	
	ofSetVerticalSync(true);
	
	
	ofEnableAlphaBlending();
	ofBackground(30,30,30);
	
	
	
	myRectangle.pos.x = 100;
	myRectangle.pos.y = 50;
    
    radius =50;
	
	pos.x = click.x = 100;
	pos.y = click.y = ofGetHeight() / 2.0;
	
}

//--------------------------------------------------------------
void testApp::update(){
	myRectangle.xenoToPoint(mouseX, mouseY);
    
    ofPoint diff = click - pos;
	ofPoint change = diff / 30.0;
    
	pos += change;

}

//--------------------------------------------------------------
void testApp::draw(){
	myRectangle.draw();
    
    ofFill();
	ofSetColor(220, 220, 220);
    //ofSetSphereResolution(900); 
    ofEnableSmoothing();
    
	ofCircle(pos.x, pos.y, radius);
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	click.x = x;
	click.y = y;
}
