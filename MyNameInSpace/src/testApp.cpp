#include "testApp.h"

bool DrawAnything;
bool DrawAnother;
bool DrawSpace1;
bool DrawSpace2;
bool DrawSpace3;


bool DrawLines;

//--------------------------------------------------------------
void testApp::setup(){
	
	
	
    ofSetVerticalSync(true);
    ofBackground(255, 255, 255, 255);
		
	
    DrawAnything = false;
	DrawAnother = false;
	DrawSpace1 = false;
	DrawLines = false;


}

//--------------------------------------------------------------
void testApp::update(){
	
		
}

//--------------------------------------------------------------
void testApp::draw(){
	
	ofNoFill();
	ofSetColor(0, 0, 0);
	
	ofDrawBitmapString("THIS IS MY NAME IN THIS SPACE", 400,750);
	 

		 
	 
	temp.draw();
	
	for(int i=0; i<lines.size(); i ++) {
		lines[i].draw();
	}
	
	if(DrawAnything)
	{
		ofBeginShape();
		
		ofVertex(200,135);
		ofVertex(15,135);
		ofVertex(165,25);
		ofVertex(105,200);
		ofVertex(50,25);
		ofEndShape();
		
		
	}
	
	
	if(DrawAnything)
	{
		ofSetColor(0, 155, 155);
	}
	
	if(DrawAnother)
	{    ofBox(900,300,120);
	}
		
	if(DrawAnother)
	{
		ofSetColor(50, 20, 100);
	}
	
	if(DrawSpace1)
	{
		ofSetColor(0,0,0);
	ofLine(72, 0, 612, 326);   // line 1
	ofLine(612, 326, 672, 198); // line 4
	ofLine(612, 326, 644, 175); // line 3
	
	ofSetLineWidth(5);
	ofLine( 446,0, 786, 294 ); //line 2
	ofLine(786, 294, 1024, 210); //line 5
	ofLine(786, 294, 1024, 294); // line 6
	ofLine(612, 326, 0, 283); // line 8
	ofLine(612, 326, 0, 588); // line 9
	ofLine(786, 294, 786, 588); //line 7
	ofLine(786, 588, 159, 768); // line 10
	ofLine(786, 588, 1024, 492); // line 11
	ofLine( 786, 588, 1024, 522); // line 12
	ofLine(397, 423, 0, 283); // line 13
	ofLine(397, 423, 426, 588); // line 14
	ofLine(426, 588, 612, 326); // line 15
		//ofDrawBitmapString(" Press c to enter another space.", ofGetWidth()/2,ofGetHeight()/2);
}
	
	if(DrawSpace2)
	{
		ofSetColor(0, 0, 0);
		ofNoFill();
		ofSetLineWidth(10);
		ofBezier(0, 80, 100, 70, 200,60, 400, 150);
		ofBezier(400, 150, 480, 100, 520, 90, 600, 150);
		ofBezier(600, 150, 750, 100, 900, 80, 1024, 50);
		//bottom
		ofBezier(400, 300, 410, 450, 50, 450, 0, 490);
		ofLine(400, 300, 400, 150);
		ofBezier(400, 300, 420, 350, 520, 370, 600, 300);
		ofBezier(600, 300, 560, 450, 780, 600, 1024, 750);
		ofLine(600, 300, 600, 150);
		
		ofSetColor(0, 0, 0);
		ofNoFill();
	}		
	
	if (DrawSpace3) {
		
		ofSetColor(0, 0, 0);
		ofLine(100,0,200,200);
		ofLine(200,200,600,200);
		ofLine(600,200,700,0);
		ofLine(600,200,600,600);
		ofLine(600,600,800,700);
		ofLine(0,700,200,600);
		ofLine(200,200,200,600);
		ofLine(200,600,600,600);

	}
	
	if (DrawLines) {
		
		ofSetBackgroundAuto(false);
		ofSetColor(0, 0, 0, 123);
		
		int y = ofRandom(0,ofGetHeight());
		int x = ofRandom(0,ofGetWidth());
		line = ofRandom(0, 50);
		ofLine(x, y, x, line);		
		
		ofSetBackgroundAuto(false);
		

		
	}	
		
				
}



//--------------------------------------------------------------
void testApp::keyPressed(int key){
	if (key=='s') {
		DrawAnother = true;
	
	}
	
	
		
	if (key=='a') {
		DrawSpace1 = false;
		DrawSpace2 = false;
		DrawSpace3 = false;
	}
	
	if (key=='b') {
		DrawSpace1 = true;
		DrawSpace2 = false;
		DrawSpace3 = false;
		DrawAnother = false;
	}
	
	if(key=='c') {
		DrawSpace2 = true;
		DrawSpace1 = false;
		DrawSpace3 = false;
		DrawAnother = false;
	}
	
	if(key=='d') {
		DrawSpace3 = true;
		DrawSpace2 = false;
		DrawSpace1 = false;
		DrawAnother = false;
	}
	
	if(key=='t') {
		DrawLines = true;
		
	}
	
	if(key =='x') {
		DrawLines = false;
	}

	}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
		
	temp.points.push_back( ofPoint(x,y));

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	
	temp.points.clear();
	

}
		
//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	
	lines.push_back(temp);
	
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}