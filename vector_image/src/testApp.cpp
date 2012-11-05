#include "testApp.h"


//--------------------------------------------------------------
#include "testApp.h"

void ofxSetColorHSB(float h, float s, float b, float a=34);
//134

//--------------------------------------------------------------
void testApp::setup(){
    w = ofGetWidth();
    h = ofGetHeight();
    vid.initGrabber(w,h,true); 
    

}


//---------------------------------------------------------------

void testApp::update(){
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
    vid.update();
    
  
   
    
  
        
    
}

//--------------------------------------------------------------

void testApp::draw(){
    

    
    ofBackground(123,255,255);
    ofSetColor(120,23,120);
    
    for (int y=0; y<h; y+=6) {
        for (int x=0; x<w; x+=6) {
            
            //get color for pixels
            int i = (y*w+x)*3;
            int r = vid.getPixels()[i+0];
            int g = vid.getPixels()[i+1];
            int b = vid.getPixels()[i+2];
            
            //calculating brightness of pixels
          
            float br = (r+b+g) / 765.0;

            
           
            ofxSetColorHSB(br*255,255,255);
            
            //calculating sine and cosine for brightness
            float co = cos(br*TWO_PI);
            float si = sin(br*TWO_PI);
            
            //draw lines based on brightness
            ofLine(x-6*co, y-6*si, x+6*co, y+6*si);
        }
    }
}

void ofxSetColorHSB(float h, float s, float b, float a) {
    if (b==0) return ofSetColor(0,0,0,a); //black
    if (s==0) return ofSetColor(b,b,b,a); //gray
    
    //h *= 6.0 / 255.0;
    h *= 6.0 / 120.0;
    s *= 1.0 / 120.0;
    
    float x = b * (1-s);
    float y = b * (1-s*(h-int(h)));
    float z = b * (1-s*(1-(h-int(h))));
    
    switch (int(h)) {
        case 0: return ofSetColor(b,z,x,a); //red
        case 1: return ofSetColor(y,b,x,a); //green
        case 2: return ofSetColor(x,b,z,a); 
        case 3: return ofSetColor(x,y,b,a); //blue
        case 4: return ofSetColor(z,x,b,a); 
        case 5: return ofSetColor(b,x,y,a); //back to red
 }



    }
//----------------------------------------------
