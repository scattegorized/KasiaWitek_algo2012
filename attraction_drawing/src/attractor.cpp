//
//  File.cpp
//  attractionRepulsion
//
//  Created by kasia witek on 10/14/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "attractor.h"

//--------------------------------------------------


Attractor::Attractor(){
	bDragging = false;
	bRollover = false;
	
	loc.x = ofGetWidth()/2.0;
	loc.y = ofGetHeight()/2.0;
	dragoff = loc;
    
  
}

//------------------------------------------------

void Attractor::addForce(float x, float y){
    
    frc.x = frc.x + x;
    frc.y = frc.y + y;
}

//-------------------------------------

void Attractor::addAttractionForce( float px, float py, float radius, float strength){
	
	
	ofPoint posOfForce;
	posOfForce.set(px, py);
	

    ofPoint diff = pos - posOfForce;
	
	if (diff.length() < radius){
		float pct = 1 - (diff.length() / radius);
		diff.normalize();
		frc.x -= diff.x * pct * strength;
		frc.y -= diff.y * pct * strength;
	}
    

}

//--------------------------------------------------

void Attractor::draw(){
   ofNoFill();
 if(bDragging) ofSetColor(ofRandom(120,235));
   else if (bRollover) ofSetColor(145,234,12);
   else ofSetColor(23, 123, 234);
    ofCircle(loc.x, loc.y, 80);
   
}
//--------------------------------------------------

void Attractor::clicked(int x, int y){
	float d = ofDist(x, y, loc.x, loc.y);
    if (d < 100) {
		bDragging = true;
		dragoff.x = loc.x-x;
		dragoff.y = loc.y-y;
    }	
}
//--------------------------------------------------

void Attractor::rollover(int x, int y){
	float d = ofDist(x,y,loc.x,loc.y);
    if (d < 100) {
		bRollover = true;
    } else {
		bRollover = false;
    }
}
//------------------------------------------------

void Attractor::stopDragging(){
	bDragging = false;
}
//---------------------------------------------

void Attractor::drag(int x, int y){
	if (bDragging) {
		loc.x = x + dragoff.x;
		loc.y = y + dragoff.y;
    }
}


