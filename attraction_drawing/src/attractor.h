//
//  Header.h
//  attractionRepulsion
//
//  Created by kasia witek on 10/14/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef attractionRepulsion_Header_h
#define attractionRepulsion_Header_h

#include "ofMain.h"
#include "particle.h"

class Attractor {
public:
	Attractor();
	
	void resetForce();
    void addForce(float x, float y);
    void addDampingForce();
    void setInitialCondition(float px, float py, float vx, float vy);
    void update();

	void draw();
	void clicked(int x, int y);
	void rollover(int x, int y);
	void stopDragging();
	void drag(int x, int y);
    
    void addAttractionForce( float px, float py, float radius, float strength);
	
	
	bool bDragging; 
	bool bRollover; 
	float damping;
    
    ofPoint loc;
    ofPoint dragoff; 
    ofPoint pos;
    ofPoint vel;
    ofPoint frc;};



#endif
