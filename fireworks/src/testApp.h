#pragma once

#include "ofMain.h"
#include "Particle.h"
#include "ParticleSystem.h"

class testApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
	
    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void makePixicles();
	
    //ofImage img;
    ofImage bg;
    int numPix;
    unsigned char* pix;
	
    ParticleSystem p;
};



