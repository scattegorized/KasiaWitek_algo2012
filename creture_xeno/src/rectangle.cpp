#include "rectangle.h"


//------------------------------------------------------------------
rectangle::rectangle(){
	catchUpSpeed = 0.03f;
}

//------------------------------------------------------------------
void rectangle::draw() {
	    
    ofPushMatrix();     
    
    ofTranslate(pos.x, pos.y);
    
    ofSetColor(232, 21, 136);
	ofFill();
	ofBeginShape();
	ofVertex(90, 21);
	ofVertex(130, 341);
	ofVertex(140, 14);
	ofVertex(470, 460);
	ofVertex(180, 95);
	ofVertex(318, 180);
	ofVertex(210, 300);
	ofVertex(190, 444);
	ofVertex(419, 108);
	ofVertex(160, 460);
	ofVertex(319, 390);
	ofVertex(120, 210);
	ofVertex(210, 214);
	ofVertex(180, 215);
	ofVertex(186, 111);
	ofVertex(415, 310);
	ofVertex(313, 413);
	ofVertex(68, 13);
	ofVertex(378, 111);
	ofVertex(354, 110);
	ofVertex(347, 115);
	ofVertex(100, 113);
	ofVertex(330, 511);
	ofVertex(374, 388);
	ofVertex(69, 89);
	ofVertex(60, 127);
	ofVertex(30, 127);
	ofVertex(233, 124);
	ofVertex(178, 333);
	ofVertex(350, 231);
	ofVertex(48, 126);
	ofVertex(280, 234);
	ofVertex(90, 109);
	ofEndShape();
    
    ofSetColor(	0,191,255);
	ofFill();
	ofBeginShape();
    
	ofCircle(70, 3, 52);
	ofCircle(15, 3, 52);
    ofEndShape();
    
    ofSetColor(0,255,127);
	ofFill();
	ofBeginShape();
    
	ofCircle(70, 3, 22);
	ofCircle(15, 3, 22);
    ofEndShape();
    
    ofSetColor(230,255,127);
	ofFill();
	ofBeginShape();
    
	ofCircle(70, 3, 11);
	ofCircle(15, 3, 11);
    ofEndShape();
    
    
    
    
    
	ofPopMatrix();
    
    

}

//------------------------------------------------------------------
void rectangle::xenoToPoint(float catchX, float catchY){
	pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x; 
	pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y; 
}
