//
//  particle.cpp
//  art_2
//
//  Created by 小原佳 on 2013/12/19.
//
//

#include "particle.h"
Particle::Particle() {}

void Particle::init() {
    red = ofRandom(0,255);
    blue = ofRandom(0,255);
    green = ofRandom(0,255);
    alpha = ofRandom(0,100);
    pos = ofPoint(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()));
    r = 20;
    float degreeTemp = ofRandom(360);
    float rTemp = ofRandom(0, ofGetWidth()/4);
    xInit = cos(ofDegToRad(degreeTemp))*rTemp+ofGetWidth()/2;
    yInit = sin(ofDegToRad(degreeTemp))*rTemp+ofGetHeight()/2;
    xCurr = xInit;
    yCurr = yInit;
    pushForce = ofRandom(10, 300);
    recoverForce = ofRandom(10, 100);
}

void Particle::display() {
    ofPushMatrix();
ofEnableSmoothing();
    ofTranslate(xCurr, yCurr);
    ofRotate(ofDegToRad(360*ofNoise(xCurr*0.01, yCurr*0.01)));
    diam = (pushForce/recoverForce)/ofDist(xCurr, yCurr, xmouse, ymouse)*100;
    ofSetColor(red, blue, green, alpha);
    ofEllipse(0, 0, diam*2, diam*2);
    ofPopMatrix();
}

void Particle::update() {
    float x0 = xCurr;
    float y0 = yCurr;
    float a = xmouse - x0;
    float b = ymouse - y0;
    float r = pushForce/(a*a+b*b);
    float quer_fugir_x = xCurr-a*r;
    float quer_fugir_y = yCurr-b*r;
    float quer_voltar_x = (xInit-x0)/recoverForce;
    float quer_voltar_y = (yInit-y0)/recoverForce;
    xCurr = quer_fugir_x+quer_voltar_x;
    yCurr = quer_fugir_y+quer_voltar_y;
}

void Particle::reset() {
    float degreeTemp = ofRandom(360);
    float rTemp = ofRandom(10, ofGetWidth()/4);
    pushForce = ofRandom(10, 300);
    recoverForce = ofRandom(10, 100);
    xInit = cos(ofDegToRad(degreeTemp))*rTemp+ofGetWidth()/2;
    yInit = sin(ofDegToRad(degreeTemp))*rTemp+ofGetHeight()/2;
}

void Particle::setPos(ofPoint _pos){
    pos = _pos;
}

ofPoint Particle::getPos(){
    return pos;
}

void Particle::setRadius(float _r){
    r = _r;
}

float Particle::getRadius(){
    return r;
}