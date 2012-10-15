#include "testApp.h"

#define NUM_CIRCLES 1000
float circleX[NUM_CIRCLES];
float circleY[NUM_CIRCLES];
float circleRadius[NUM_CIRCLES];

float r[NUM_CIRCLES];
float g[NUM_CIRCLES];
float b[NUM_CIRCLES];

float vx[NUM_CIRCLES];
float vy[NUM_CIRCLES];


//array for lots 0 is first number


//--------------------------------------------------------------
void testApp::setup(){
    mySound.loadSound("fly.mp3");
    mySound.play();

    
	ofSetFrameRate(12);
	
	for(int i = 0; i<NUM_CIRCLES; i++)
	{
	
			circleX[i] = ofRandom(0, ofGetWidth());



	circleY[i] = ofRandom(0, ofGetHeight());
	
	circleRadius[i] = ofRandom(10,100);

	
		
		r[i] = ofRandom(200,120);
		g[i] = ofRandom(200,150);
		b[i] = ofRandom(200,210);	
	
		vx[i] = ofRandom(-5,5);
		vy[i] = ofRandom(-3,3);
		
	}
	
}


//--------------------------------------------------------------
void testApp::update(){
    ofSoundUpdate();
    
	for(int i = 0; i<NUM_CIRCLES; i++)
	{
		circleX[i] +=vx[i];
		circleY[i] += vy[i];
		
		if(circleX[i] > ofGetWidth())
		{
			vx[i] *= -1;
		}
		if(circleX[i] <0)
		{
			vx[i] *= -1;
	
		}
	if(circleY[i] > ofGetHeight())
	{
		   vy[i] *= -1;
		
	}
	   if(circleY[i] <0)
	   {
		   vy[i] *=-1;
	   }

	}
}	
	
	

//--------------------------------------------------------------
void testApp::draw(){
	
ofColor(239,197,215);(ofRandom(0,100), ofRandom(0,104), ofRandom(200,255), ofRandom(0,102));

	
	for(int i = 0; i<NUM_CIRCLES; i++)
	{
		ofCircle(circleX[i], circleY[i], circleRadius[i]);
		ofSetColor(r[i], g[i], b[i]);    //random color
		
	

	}
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

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

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