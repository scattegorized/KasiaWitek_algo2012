#include "testApp.h"
#include "stdio.h"


//--------------------------------------------------------------
void testApp::setup(){
	
	ofBackground(21, 234, 245);
	
	ard.connect("/dev/tty.usbmodemfd121", 57600);
	ofAddListener(ard.EInitialized, this, &testApp::setupArduino);
	
	
	bSetupArduino	= false;	    
    mouse_pressed = false; 
	gravity = 0.1; 
    friction = 0.999;
    
    
    for(int i = 0; i < NUM; i++){
        loc_x[i] = ofGetWidth() / 2; 
        loc_y[i] = ofGetHeight() / 2; 
        speed_x[i] = ofRandom(-10, 10); 
        speed_y[i] = ofRandom(-10, 10); 
        radius[i] = ofRandom(1, 10); 
        red[i] = ofRandom(0, 255);
        green[i] = ofRandom(0, 255); 
        blue[i] = ofRandom(0, 255); 
    }
    
    ardButtonPressed = false;
	
	
	
	
	 
	myVideo.initGrabber( 1324,968,true); 
	
	ofSetFrameRate(24);
	ofEnableAlphaBlending();
	ofSetCircleResolution(50);
	ofEnableSmoothing();
	
	ofSoundStreamSetup(0, 2, this, 44100, 256, 4);	
	left = new float[256];	
	right = new float[256];
	
	AAleft.setup();
    AAright.setup();
	
	//
	inputBufferCopy = new float [512 *2];
	//
	
		
	

	lines[0].min_y = 0;
    lines[0].max_y = 50;
    lines[0].id = 1;	    
	
	lines[1].min_y = 50;
    lines[1].max_y = 100;
	
    lines[1].id = 2;
	
	lines[2].min_y = 70;
    lines[2].max_y =110;
    lines[2].id = 3;
	
    lines[3].min_y = 100;
    lines[3].max_y = 140;
    lines[3].id = 4;
	
	lines[4].min_y = 110;
	lines[4].max_y =160;
	lines[4].color = ofColor(255, 255, 255, 0);
    lines[4].id = 5;
	
	
}





//--------------------------------------------------------------
void testApp::update(){
	
	myVideo.update();
    
	float amp = (AAleft.amplitude + AAright.amplitude) / 2.0;
    int numHairs = ofMap(amp, .01, .2, 0, 10, true);
	currentRadius = ofMap(amp, .01, .2, 6, 28, true);
	
    for(int i=0; i<numHairs; i++)
    {
        Hair h;
        h.setup();
        hairs.push_back( h );
        cout << "adding hair" << endl;
    }
    
    for(int i=0; i<hairs.size(); i++)
    {
		hairs[i].update(theHair, lines, currentRadius);
        
        if(hairs[i].position.y > ofGetHeight())
        {
            hairs.erase( hairs.begin() + i );
        }
    }
	
	updateArduino();
    
    for(int i = 0; i < NUM; i++){
        
        //if(mouse_pressed){
        if(ardButtonPressed){
			
            speed_x[i] = (ofGetWidth()/2- loc_x[i]) / 8.0;
            speed_y[i] = (ofGetHeight()/2 - loc_y[i]) / 8.0;
        }
        
        speed_x[i] = speed_x[i] * friction;
        speed_y[i] = speed_y[i] * friction;
        speed_y[i] = speed_y[i] + gravity;
        
        loc_x[i] = loc_x[i] + speed_x[i]; 
        loc_y[i] = loc_y[i] + speed_y[i]; 
        
        if(loc_x[i] < 0){
            loc_x[i] = 0;
            speed_x[i] = speed_x[i] * -1.0;
        }
        if(loc_x[i] > ofGetWidth()){
            loc_x[i] = ofGetWidth();
            speed_x[i] = speed_x[i] * -1.0;
        }
        if(loc_y[i] < 0){
            loc_y[i] = 0;
            speed_y[i] = speed_y[i] * -1.0;
        }
        if(loc_y[i] > ofGetHeight()){
            loc_y[i] = ofGetHeight();
            speed_y[i] = speed_y[i] * -1.0;
        }
    }
    
    int buttonState = ard.getDigital(2);
    if(buttonState == true){
        //mouse_pressed    = true; 
        ardButtonPressed   = true; 
		
    } else     if(buttonState == false){
        //mouse_pressed = false; 
        ardButtonPressed = false;
    }
	
	
	

}
//--------------------------------------------------------------
void testApp::setupArduino(const int & version) {
	
	// remove listener because we don't need it anymore
	ofRemoveListener(ard.EInitialized, this, &testApp::setupArduino);
	ard.sendDigitalPinMode(2, ARD_INPUT);	
	bSetupArduino = true;
}
//--------------------------------------------------------------
void testApp::updateArduino(){
	
	// update the arduino, get any data or messages.
	ard.update();
	
}


//--------------------------------------------------------------
void testApp::draw(){
	
	ofSetColor(255);
	//bgPic.draw(0, 0);
	myVideo.draw(0, 0);
	
	//	ofSetHexColor(0xFFFF55);
	//	dinFont.drawString( "pitch: " + ofToString((int)AAleft.pitch) + "\namplitude: " + ofToString(AAleft.amplitude,3), 50,300);
	
    for(int i=0; i<10; i++)
    {
        lines[i].draw();
    }	
	
    for(int i=0; i<hairs.size(); i++)
    {
       hairs[i].draw();
    }
	
	
	ofSetColor(0, 0, 0, 23);
    ofRect(0, 0, ofGetWidth(), ofGetHeight());
    
    for(int i = 0; i < NUM; i++){
        ofSetColor(red[i], green[i], blue[i], 127); 
        ofCircle(loc_x[i], loc_y[i], radius[i]); 
    }
	
	

}
//--------------------------------------------------------------
void testApp::audioReceived(float* input, int bufferSize, int nChannels){	
	
	
	// samples are "interleaved"
	for (int i = 0; i < bufferSize; i++){
		left[i] = input[i*2];		
		right[i] = input[i*2+1];
	}
	
	AAleft.processAudio(left, bufferSize);
    AAright.processAudio(right, bufferSize);
	
	float pitch = (AAleft.pitch + AAright.pitch) / 2.0;
	//float volume = (AAleft.volume + AAright.volume) / 2.0;
	
	
	if (pitch >= 160 && pitch < 200) {
		theHair = 6;
	}
	if (pitch >= 310 && pitch < 340) {
		theHair = 5;
	}
	if (pitch >= 280 && pitch < 310) {
		theHair = 4;
	}	
	if (pitch >= 190 && pitch < 200) {
		theHair = 3;
	} 
	if (pitch >= 240 && pitch < 250) {
		theHair = 2;
	}	
	if (pitch >= 320 && pitch < 330) {
		theHair = 1;
	}
}




//--------------------------------------------------------------
void testApp::keyPressed(int key){
	switch(key) {
        case '1':
            theHair = 1;
            break;
        case '2':
            theHair = 2;
            break;
        case '3':
            theHair = 3;
            break;
        case '4':
            theHair = 4;
            break;
        case '5':
            theHair = 5;
            break;
        case '6':
            theHair = 6;
            break;			
    }
	

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
