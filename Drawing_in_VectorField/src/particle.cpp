#include "particle.h"
#include "ofMain.h"


//------------------------------------------------------------
particle::particle(){
	setInitialCondition(0,0,70,90);
	//damping = 0.15f;
    damping = 0.25f;
}

//------------------------------------------------------------
void particle::resetForce(){
   
    frc.set(0,0);
}

//------------------------------------------------------------
void particle::addForce(float x, float y){
        frc.x = frc.x + x;
    frc.y = frc.y + y;
}

//------------------------------------------------------------
void particle::addDampingForce(){
	
	
	
    frc.x = frc.x - vel.x * damping;
    frc.y = frc.y - vel.y * damping;
}

//------------------------------------------------------------
void particle::setInitialCondition(float px, float py, float vx, float vy){
    pos.set(px,py);
	vel.set(vx,vy);
}

//------------------------------------------------------------
void particle::update(){	
	vel = vel + frc;
	pos = pos + vel;
}

//------------------------------------------------------------
void particle::draw(){
    ofCircle(pos.x, pos.y, 1);
}


//------------------------------------------------------------
void particle::bounceOffWalls(){
	
	
	bool bDampedOnCollision = true;
	bool bDidICollide = false;
	

	float minx = 0;
	float miny = 0;
	float maxx = ofGetWidth();
	float maxy = ofGetHeight();
	
	if (pos.x > maxx){
		pos.x = maxx; 
		vel.x *= -3;
		bDidICollide = true;
	} else if (pos.x < minx){
		pos.x = minx; 		vel.x *= -3;
		bDidICollide = true;
	}
	
	if (pos.y > maxy){
		pos.y = maxy;		vel.y *= -1;
		bDidICollide = true;
	} else if (pos.y < miny){
		pos.y = miny; 		vel.y *= -1;
		bDidICollide = true;
	}
	
	if (bDidICollide == true && bDampedOnCollision == true){
		vel *= 0.3;
	}
	
}
