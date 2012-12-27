
#ifndef _TEST_APP
#define _TEST_APP
#define NUM 1000

#include "ofMain.h"

#include "myLine.h"
#include "ofxAubioAnalyzer.h"

#include "hair.h"


class testApp : public ofSimpleApp{
	
public:
	
	void setup();
	void update();
	void draw();
	
	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	//void mouseReleased();		
	void audioReceived(float * input, int bufferSize, int nChannels); 
	
	ofImage bgPic;
	
	float* left;
	float* right;
	
	int theHair;
	ofxAubioAnalyzer AAleft;
	ofxAubioAnalyzer AAright;
	
	ofTrueTypeFont dinFont;
	
	vector<Hair> hairs;
	myLine lines[10];
	float currentRadius; 
	
	ofVideoGrabber myVideo;
	
	ofSoundStream soundStream;
	
	//
	float volume;
	float * inputBufferCopy;
	
	// arduino
	void setupArduino(const int & version);
	void updateArduino();
	
	ofArduino	ard;
	bool		bSetupArduino;		
	//
	
	bool ardButtonPressed;
    bool explosion;
	
	float loc_x[NUM]; 
    float loc_y[NUM]; 
    float speed_x[NUM]; 
    float speed_y[NUM]; 
    float radius[NUM]; 
    int red[NUM]; 
    int green[NUM];
    int blue[NUM]; 
    bool mouse_pressed; 
    float gravity;
    float friction;
	
	
};

#endif	




