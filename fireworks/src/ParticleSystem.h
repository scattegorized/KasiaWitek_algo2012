//
//  ParticleSystem.h
//  emptyExample
//
//  Created by kasia witek on 10/7/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef emptyExample_ParticleSystem_h
#define emptyExample_ParticleSystem_h

#include "ofMain.h"
#include "particle.h"

class ParticleSystem {
public:
	ParticleSystem();
	
	void applyForce(ofPoint force);
	void applyRandomForce();
	void update();
	void draw();
	void addParticle(float x, float y, int r, int g, int b);
	bool dead();
	
	vector<Particle> particles;
	ofPoint origin;
	int r, g, b;
};




#endif
