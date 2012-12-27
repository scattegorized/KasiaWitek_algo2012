/*
 *  myLine.h
 *  emptyExample
 *
 *  Created by kasia witek on 12/26/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef emptyExample_myLine_h
#define emptyExample_myLine_h

class myLine {
public:
	
    int id;
    ofColor color;
    float min_y; // line`s sensing area in & line`s y position
    float max_y; // line`s sensing area max	
    
    void draw() {
        //ofSetColor(color.r, color.g, color.b, color.a);
        //ofLine(0, min_y, ofGetWidth(), min_y);
    }
    
};

#endif