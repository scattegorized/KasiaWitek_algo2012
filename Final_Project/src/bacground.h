//
//  bacground.h
//  emptyExample
//
//  Created by kasia witek on 12/26/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>


@protocol bacground


class myBackground {
public:
	
    int id;
    ofColor color;
    float min_y; 
    float max_y; 	
    
    void draw() {
        //ofSetColor(color.r, color.g, color.b, color.a);
        //ofLine(0, min_y, ofGetWidth(), min_y);
    }
    
};




@end
