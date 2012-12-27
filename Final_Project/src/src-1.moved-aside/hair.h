//
//  hair.h
//  emptyExample
//
//  Created by kasia witek on 12/26/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>


@protocol hair
#include "background.h"


class Hair {
public:
	
	ofImage bgPic;
	
    int behavior;
    ofPoint position;
    //ofColor color; 
    float radius;
	float xSpeed, ySpeed;
	float xAngle, yAngle;
    //float pitch;
	float volume;
    float amp;
	
	ofVec2f pos,vel,acc,oldpos;
    float angle;
    ofColor color;
    int age;
	
    
    void setup()
    {
		
		bgPic.loadImage("hair.png");
        //position.x = ofRandom(ofGetWidth()-250, ofGetWidth()-70);
        //position.y = ofRandom(470, 520);
		
		position.x = ofRandom(ofGetWidth()-500, ofGetWidth()-300);
        position.y = ofRandom(ofGetHeight(), ofGetHeight());
		
        /*color.r = 35;
		 color.g = 90;
		 color.b = 160;
		 color.a = 255;*/
		
		color.r = 255;
		color.g = 255;
		color.b = 255;
		color.a = 50;
		
        radius = 8;
        behavior = 1; // fall down
    }
    
    void update(int theNote, myLine* theLines, float currentRadius) 
    {
		
		//xSpeed = ofRandom(-3.0, 1.0);
		xSpeed = ofRandom(-3.0, 1.0);
		//ySpeed = ofRandom(3.5, 8.5);
		ySpeed = ofRandom(1, 3);
		//xAngle += 0.8;
		xAngle += 3.9;
		yAngle += 0.2;
		
		if(behavior==1)
        {
			//position.x += xSpeed + ofMap(sin(xAngle),-PI,PI, -6, 6);
			position.x += xSpeed + ofMap(sin(xAngle),-PI,PI, -9, 9);
			position.y -= ySpeed + ofMap(cos(yAngle),-PI,PI, -9, 9);
			//-3,3
        }
        if(behavior==2)
        {
            //position.x -= 10;
			position.x -= 16;
        }
        
        for(int i=0; i<16; i++)
        {
			
			if (position.y < theLines[0].min_y) {
				if (color.a > 0) {
					color.a -= 3;
				}else {
					color.a = 3;
				}
			}
			
			if(theNote == theLines[i].id && position.y > theLines[i].min_y && position.y < theLines[i].max_y)
			{
				position.y = theLines[i].min_y;
				behavior = 2; // move left
				
				radius = currentRadius;
				
				if (theNote == 1) {
					color.r = 249;
					color.g = 29;
					color.b = 220;
					color.a = 60;
				}
				
				if (theNote == 2) {
					color.r = 29;
					color.g = 249;
					color.b = 117;
					color.a = 40;
				}
				
				if (theNote == 3) {
					color.r = 7;
					color.g = 252;
					color.b = 219;
					color.a = 40;
				}
				
				if (theNote == 4) {
					color.r = 252;
					color.g = 7;
					color.b = 40;
					color.a = 40;
				}
				
				if (theNote == 5) {
					color.r = 227;
					color.g = 252;
					color.b = 7;
					color.a = 40;
				}
				
				if (theNote == 6) {
					color.r = 0;
					color.g = 0;
					color.b = 0;
					color.a = 60;
				}				
			}
			
			if(theNote != theLines[i].id && position.y > theLines[i].min_y && position.y < theLines[i].max_y)
			{
				behavior = 1; 
			}
			
        }
        
    }
    
    void draw() 
    {
        ofSetColor(color.r, color.g, color.b, color.a);
        //ofCircle(position.x, position.y, radius);  
		bgPic.draw(position.x, position.y, radius);
    }
	
};




#endif


@end
