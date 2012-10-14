#include "testApp.h"

#define NUM_CIRCLES 23
float circleX[NUM_CIRCLES];
float circleY[NUM_CIRCLES];
float circleRadius[NUM_CIRCLES];

float vx[NUM_CIRCLES];
float vy[NUM_CIRCLES];


//--------------------------------------------------------------
void testApp::setup(){
	ofBackground(0,255,206);
		ofSetFrameRate(24);
	     for(int i = 0; i<NUM_CIRCLES; i++)
	{
		
		circleX[i] = ofRandom(0, ofGetWidth());
		
		
		circleY[i] = ofRandom(0, ofGetHeight());

		circleRadius[i] = ofRandom(2,10);	//between 2 and 10
		
		vx[i] = ofRandom(-1,1);				//velocity of x 
		vy[i] = ofRandom(-1,1);
											
		
	}
		
		
	ofSetVerticalSync(true);
	ofSoundStreamSetup(2,0,this, 44100,80, 4); 
	ofSetBackgroundAuto(false);				// balls will drag (form lines of sort)
	
	frequency								= 50;
	position								=0;
	positionAdder							= (frequency /5, 44100.0) * TWO_PI;
	frequencyModulator						= 2;
	positionModulator						= 0;
	positionModulatorAdder				    =(frequencyModulator /2, 44100.0) * TWO_PI;
	
	modulator								= 0;
	sample									=0;

	
}

//--------------------------------------------------------------
void testApp::update(){
	frequency								= mouseX/5;
	positionAdder         =(frequency / 44100.0) * TWO_PI;
	frequencyModulator						= mouseY/5;
	positionModulatorAdder				    =(frequencyModulator / 44100.0) * TWO_PI;
	
	
	for(int i = 0; i<NUM_CIRCLES; i++)
	{
		ofSetColor(239,197,215);
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

	for(int i = 0; i<NUM_CIRCLES; i++)
	{
		ofCircle(circleX[i], circleY[i], circleRadius[i]);
		//ofCircle(circleX[i], circleY[i],0.2*modulator*frequency, 0.2*modulator*frequency);
		ofSetColor(66,212,179);	
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
ofCircle(mouseX,mouseY,0.1*modulator*frequency, 0.1*modulator*frequency);
 //ofSetColor(0,0,0);
		

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

//--------------------------------------------------------------
	void testApp::audioRequested 	(float * output, int bufferSize, int nChannels){
		
		for (int i = 0; i < bufferSize; i++){
			
			
			modulator	=  ofMap(sin (positionModulator), -1,1, 0,1);
			positionModulator += positionModulatorAdder;
			sample		= sin( position ) * modulator;
					position	+= positionAdder; 
				output[i * 2 + 0] = sample;	
		}
		
		while (position > TWO_PI) {
			position -= TWO_PI;	
		}
		
		while (positionModulator > TWO_PI){
			positionModulator -= TWO_PI;	
		}
	}		
		
