//
//  ParticleSystem.cpp
//  emptyExample
//
//  Created by kasia witek on 10/7/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "particleSystem.h"


ParticleSystem::ParticleSystem() {
	origin.x = ofGetWidth()/2;
	origin.y = ofGetHeight()/2;
}

void ParticleSystem::applyForce(ofPoint force) {
	for(int i=0; i<particles.size(); i++) {
		particles[i].applyForce(force);
	}
}


void ParticleSystem::applyRandomForce() {
	for(int i=0; i<particles.size(); i++) {
		ofPoint f(ofRandom(-4, 4), ofRandom(-4, 4));
		particles[i].applyForce(f);
	}
}

void ParticleSystem::update() {
	for(int i=0; i<particles.size(); i++) {
		particles[i].update();
		if(particles[i].dead()) {
			particles.erase( particles.begin()+i );
		}
	}
}

void ParticleSystem::draw() {
	ofFill();
	for(int i=0; i<particles.size(); i++) {
		particles[i].draw();
	}
}

void ParticleSystem::addParticle(float x, float y, int r, int g, int b) {
	Particle p;
	p.r = r;
	p.g = g;
	p.b = b;
	p.loc.x = x;
	p.loc.y = y;
	p.vel = 0;
	particles.push_back( p );
}


bool ParticleSystem::dead() {
	if(particles.size() == 0) {
		return true;
	} else {
		return false;
	}
}