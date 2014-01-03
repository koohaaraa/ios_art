//
//  lineEllipse.h
//  art_4
//
//  Created by 小原佳 on 2013/12/21.
//
//

#pragma once

#include "ofMain.h"
#include "ofxiOS.h"

class Particle : public ofBaseApp {
private:
    ofPoint pos;
    float r;
    
public:
    Particle();
    void init();
    void display();
    void update();
    void reset();
    void setRadius(float r);
    float getRadius();
    void setPos(ofPoint pos);
    ofPoint getPos();
    float xCurr;
    float yCurr;
    float pushForce;
    float recoverForce;
    float xInit;
    float yInit;
    float diam;
    float xmouse;
    float ymouse;
    float xo, yo;
    
    int red;
    int blue;
    int green;
    int alpha;
};