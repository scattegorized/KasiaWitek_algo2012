#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
    
    oneShot = false;
	pdfRendering = false;

	
	ofBackground(123,104,238);
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	ofSetBackgroundAuto(false);
		
	particle myParticle;
	myParticle.setInitialCondition(0,0,90, 21);
	particles.push_back(myParticle);
	
	myParticle.setInitialCondition(0,0,130, 341);
	particles.push_back(myParticle);
	
	myParticle.setInitialCondition(0,0,140, 14);
	particles.push_back(myParticle);
	
	myParticle.setInitialCondition(0,0,470, 460);
	particles.push_back(myParticle);
    
    myParticle.setInitialCondition(0,0,180, 95);
	particles.push_back(myParticle);
    myParticle.setInitialCondition(0,0,318, 180);
	particles.push_back(myParticle);
    myParticle.setInitialCondition(0,0,210, 300);
	particles.push_back(myParticle);
    myParticle.setInitialCondition(0,0,190, 444);
	particles.push_back(myParticle);
    myParticle.setInitialCondition(0,0,419, 108);
	particles.push_back(myParticle);
    myParticle.setInitialCondition(0,0,160, 460);
	particles.push_back(myParticle);
    


	
	spring mySpring;
		
	for (int i = 0; i < particles.size(); i++){
		
		//mySpring.distance		= 100;
        mySpring.distance		= 30;
		mySpring.springiness	= 0.2f;
		mySpring.particleA = & (particles[i  ]);
		
        mySpring.particleB = & (particles[(i+1) % particles.size()]);
		springs.push_back(mySpring);
	}
	

	mySpring.distance		= (particles[0].pos-particles[2].pos).length();
	mySpring.springiness	= 0.2f;
	mySpring.particleA = & (particles[0]);
	mySpring.particleB = & (particles[2]);
	springs.push_back(mySpring);
	
	mySpring.distance		= (particles[1].pos-particles[3].pos).length();
	mySpring.springiness	= 0.2f;
	mySpring.particleA = & (particles[1]);
	mySpring.particleB = & (particles[3]);
	springs.push_back(mySpring);
	
	
		
	
}

//--------------------------------------------------------------
void testApp::update(){

    
    for (int i = 0; i < springs.size(); i++){
		springs[i].distance		=  25 + 25 * cos(ofGetElapsedTimef()*2);
    }
    
	// on every frame 
	// we reset the forces
	// add in any forces on the particle
	// perfom damping and
	// then update
    
    
    //pdf stuff
  
	
	springs[0].distance = 100 + 20 * sin(ofGetElapsedTimef()*11);
	springs[2].distance = 100 + 20 * sin(ofGetElapsedTimef()*11 + PI);
    
    //original *8
	
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].resetForce();
	}
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].addForce(0,0.1f);
		particles[i].addRepulsionForce(mouseX, mouseY, 300, 0.8f);
	}
    //more repultion, ribbon more transparent
	
	for (int i = 0; i < springs.size(); i++){
		springs[i].update();
	}
	
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].bounceOffWalls();
		particles[i].addDampingForce();
		particles[i].update();
	}
}

//--------------------------------------------------------------
void testApp::draw(){
    
    

	ofSetColor(0,255,255);
	for (int i = 0; i < springs.size(); i++){
		springs[i].draw();
	}
	ofSetColor(20,255,25);
	for (int i = 0; i < particles.size(); i++){
		particles[i].draw();
	}
}


//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
//switch (key){
			
		/*case ' ':
			// reposition everything: 
			for (int i = 0; i < particles.size(); i++){
				particles[i].setInitialCondition(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()),0,0);
			}
			break;*/
    
    //PDF stuff:
	
if( key=='r'){
    ofEndSaveScreenAsPDF();	
    ofBeginSaveScreenAsPDF("recording-" +ofGetTimestampString()+".pdf", false);  // false 
}
	
	
}


//--------------------------------------------------------------
void testApp::keyReleased  (int key){ 
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	particles[0].pos.set(mouseX, mouseY);
	/*particles.erase(particles.begin());
	particle myParticle;
	myParticle.setInitialCondition(x,y,0,0);
	particles.push_back(myParticle);*/
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	particles[0].bFixed = true;
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
	
	particles[0].bFixed = false;
}

