#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){	
    ofEnableSmoothing();
    ofBackground(0);
    for (int i=0;i<total;i++) {
        particles[i].init();
    }
}

//--------------------------------------------------------------
void testApp::update(){
    ofBackground(0);
    for (int i=0;i<total;i++) {
        particles[i].update();
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(0);
    for (int i=0;i<total;i++) {
        particles[i].display();
    }

}

//--------------------------------------------------------------
void testApp::exit(){

}

//--------------------------------------------------------------
void testApp::touchDown(ofTouchEventArgs & touch){
    for (int i=0;i<total;i++) {
        particles[i].xmouse = touch.x;
        particles[i].ymouse = touch.y;
    }
}

//--------------------------------------------------------------
void testApp::touchMoved(ofTouchEventArgs & touch){
    for (int i=0;i<total;i++) {
        particles[i].xmouse = touch.x;
        particles[i].ymouse = touch.y;
    }
}

//--------------------------------------------------------------
void testApp::touchUp(ofTouchEventArgs & touch){

}

//--------------------------------------------------------------
void testApp::touchDoubleTap(ofTouchEventArgs & touch){
    for (int i=0;i<total;i++) {
        particles[i].reset();
    }
}

//--------------------------------------------------------------
void testApp::touchCancelled(ofTouchEventArgs & touch){
    
}

//--------------------------------------------------------------
void testApp::lostFocus(){

}

//--------------------------------------------------------------
void testApp::gotFocus(){

}

//--------------------------------------------------------------
void testApp::gotMemoryWarning(){

}

//--------------------------------------------------------------
void testApp::deviceOrientationChanged(int newOrientation){

}

