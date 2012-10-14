#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate(24);
	//FFT stuff
	img.loadImage("compressed1.jpg");
	img.draw(200, 200, 200, 200);

	ofSetBackgroundAuto(false);
	
	mySound.loadSound("Sunny.mp3");
	mySound.setLoop(true);
	nBandsToGet = 1024;
	mySound.play();
	
	ofSoundStreamSetup(0,2,this, 44100, BUFFER_SIZE, 4);	
	
	left = new float[BUFFER_SIZE];
	right = new float[BUFFER_SIZE];	
	
	FFTanalyzer.setup(44100, BUFFER_SIZE/2, 2);
	
	FFTanalyzer.peakHoldTime = 15; // hold longer
	FFTanalyzer.peakDecayRate = 0.95f; // decay slower
	FFTanalyzer.linearEQIntercept = 0.9f; // reduced gain at lowest frequency
	FFTanalyzer.linearEQSlope = 0.01f; // increasing gain at higher frequencies
// end FFT stuff	
	
	
    

	source.initGrabber(1024, 768);

	int numPixels = source.getWidth() * source.getHeight() *50;
    pixels = new unsigned char[numPixels];
	
	

}

//--------------------------------------------------------------
void testApp::update(){
    
    source.grabFrame();
    pixels = source.getPixels();
	
	// FFT stuff
	
	string compressedFilename = "compressed2.jpg";
	
	
	img.saveImage(compressedFilename, quality);
	
	ofBuffer file = ofBufferFromFile(compressedFilename);
	int fileSize = file.size();
	
	char * buffer = file.getBinaryBuffer();
	
	int whichByte = (int) ofRandom(fileSize);
	
	int whichBit = ofRandom(20);
	
	char bitMask = 1 << whichBit;
	buffer[whichByte] |= bitMask;
	
	ofBufferToFile(compressedFilename, file);
	
	img.loadImage(compressedFilename);
	
//end FFT stuff	
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofPushMatrix();
    ofTranslate((ofGetWidth()/2.0)-(source.getWidth()), (ofGetHeight()/2.0));

    ofTranslate(0, -source.getHeight());
    
    // Loop through the pixels (every other pixel)
   			for(int y=0; y<source.getHeight(); y+=2)
			{
				for(int x=0; x<source.getWidth(); x+=40) 
				{
					
         
					int i = (y*source.getWidth()+x);
					int r = pixels[ i+2 ];
					int g = pixels[ i+4 ];
					int b = pixels[ i+8 ];
                
					int brightness = (r+g+b)/8.0;

					
            
            ofSetColor(r, g, b);
            ofPushMatrix();
            ofTranslate(x*2, y*2, brightness);
        
					ofRect(0,0,20,6);
					ofRect(0,0,40,20);
            ofPopMatrix();
        }
    }
    
    ofPopMatrix();
    
    
    ofSetColor(0);
    ofDrawBitmapString(ofToString(ofGetFrameRate())+"fps", 10, ofGetHeight()-20);


// FFT stuff
	float avg_power = 0.0f;	

myfft.powerSpectrum(0,(int)BUFFER_SIZE/2, left,BUFFER_SIZE,&magnitude[0],&phase[0],&power[0],&avg_power);

for (int i = 0; i < (int)(BUFFER_SIZE/2); i++){
	freq[i] = magnitude[i];
}

FFTanalyzer.calculate(freq);


for (int i = 0; i < (int)(BUFFER_SIZE/2 - 1); i++){

	ofRect(20,60+(i*40),1450,-freq[i]*2.0f);
    ofSetColor(51,255,204);
}







for (int i = 0; i < FFTanalyzer.nAverages; i++){
	//ofRect(200+(i*40),600,20,-FFTanalyzer.averages[i] * 6);
	img.draw(20+(i*100),850,40,-FFTanalyzer.averages[i] * 10);
    ofSetColor(51,200,23);
}
//
for (int i = 0; i < FFTanalyzer.nAverages; i++){

	img.draw(80+(i*100),850,40,-FFTanalyzer.averages[i] * 20);
    ofSetColor(51,255,0);
}


for (int i = 0; i < FFTanalyzer.nAverages; i++){

	img.draw(40+(i*100),850,40,-FFTanalyzer.averages[i] * 4);
}


for (int i = 0; i < FFTanalyzer.nAverages; i++){
	
	img.draw(60+(i*80),850,40,-FFTanalyzer.averages[i] * 20);
}


}



//--------------------------------------------------------------
void testApp::keyPressed(int key){
	if (key == 's' || key == 'S'){
		source.videoSettings();
	}
	
	
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
//--------------------------------------------------------------
void testApp::audioReceived 	(float * input, int bufferSize, int nChannels){	
	// samples are "interleaved"
	for (int i = 0; i < bufferSize; i++){
		left[i] = input[i*2];
		right[i] = input[i*2+1];
	}
}

