#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "ofMain.h"

class rectangle {

	public:
	
        rectangle();
	
		void	draw();
		void	xenoToPoint(float catchX, float catchY);
	
		ofPoint		pos;
		float		catchUpSpeed;		
};

#endif 