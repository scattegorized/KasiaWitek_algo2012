#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetFrameRate(30);
	ofBackground(0, 0, 0);
    
    
	img.loadImage("clay.jpg");
	
	
    numPix = img.width * img.height * 6;
	
	pix = img.getPixels();
	
	makePixicles();
}

//--------------------------------------------------------------
void testApp::makePixicles() {
	
	for(int y=0; y<img.width; y+=2)
	{
		for(int x=0; x<img.width; x+=2)
		{
			
			int i = (y * img.width + x) * 3;
			int r = pix[i + 0];
			int g = pix[i + 1];
			int b = pix[i + 2];
			
			p.addParticle(x, y, r, g, b);
		}
	}	
}

//--------------------------------------------------------------
void testApp::update(){
	p.update();
	
}

//--------------------------------------------------------------
void testApp::draw(){
	
	ofPushMatrix();
	ofTranslate(ofGetWidth()/2-img.width/2, 200, 0);
	p.draw();
	ofPopMatrix();
    
	ofDrawBitmapString("Press Any Key to See my Past expode", 500,750);


}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
	
	p.applyRandomForce();
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

//------------------------------