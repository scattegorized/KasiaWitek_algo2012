#include "testApp.h"
#include "ofMain.h"

//--------------------------------------------------------------
void testApp::setup(){

	
    
	
	ofSetVerticalSync(true);
	
	
	ofEnableAlphaBlending();
	ofBackground(30,30,30);
	
	
	
	myRectangle.pos.x = 100;
	myRectangle.pos.y = 50;
    
    
	
}

//--------------------------------------------------------------
void testApp::update(){
	myRectangle.xenoToPoint(mouseX, mouseY);
    
    

}

//--------------------------------------------------------------
void testApp::draw(){
	myRectangle.draw();
    
    ofFill();
	ofSetColor(220, 220, 220);
    ofEnableSmoothing();
    
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
	
}
