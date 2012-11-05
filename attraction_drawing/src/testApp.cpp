#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
	ofSetVerticalSync(true);

    ofBackground(0, 0, 0);
    //ofEnableBlendMode(OF_BLENDMODE_ADD);
        
       
	

	ofSetFrameRate(60);
  
	
	
	for (int i = 0; i < 300; i++){
		particle myParticle;
		myParticle.setInitialCondition(ofRandom(0,300),ofRandom(0,500),0,0);
		
		myParticle.damping = ofRandom(0.01, 0.05);
		particles.push_back(myParticle);
	}
	
}

//--------------------------------------------------------------
void testApp::update(){
    
    
    
	for (int i = 0; i < particles.size(); i++){
		particles[i].resetForce();
		
		
		particles[i].addAttractionForce(mouseX, mouseY, 300, 0.1);
	particles[i].addRepulsionForce(mouseX, mouseY, 60, 0.03);
		
		
		particles[i].addCounterClockwiseForce(mouseX, mouseY, 1000, 0.01);
		particles[i].addClockwiseForce(mouseX, mouseY, 200, 0.01);
		

		particles[i].addDampingForce();
		particles[i].update();
	}

}

//--------------------------------------------------------------
void testApp::draw(){
    
    a.draw();


    

	
	for (int i = 0; i < particles.size(); i++){
		particles[i].draw();
	}

}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){ 
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    a.rollover(x, y);	
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    a.drag(x, y);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    a.clicked(x, y);

}

//--------------------------------------------------------------
void testApp::mouseReleased(){
    a.stopDragging();
}
