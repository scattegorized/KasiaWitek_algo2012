//
//  particle.h
//  emptyExample
//
//  Created by kasia witek on 10/7/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef emptyExample_particle_h
#define emptyExample_particle_h

#include "ofMain.h"

class Particle {
public:
	Particle();
	
	ofPoint loc;
	ofPoint vel;
	ofPoint acc;
	float timer;
	float maxspeed;
	
	int r, g, b;
	
	void update();
	void draw();
	
	void applyForce(ofPoint force);
	bool dead();
};




#endif
