#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"


class testApp : public ofSimpleApp{
	

	

    public:
        void setup();
        void update();
        void draw();
        
        float w,h;
        
    ofVideoGrabber vid;
};
    
#endif
