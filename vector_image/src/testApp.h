#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"


class testApp : public ofSimpleApp{
	

	

    public:
        void setup();
        void update();
        void draw();
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
        
        float w,h;
        
    ofVideoGrabber vid;
    
    float prevMouseX;
    float prevMouseY;
};
    
#endif
