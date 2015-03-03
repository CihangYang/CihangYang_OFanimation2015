//
//  arrow.cpp
//  homework_pattern
//
//  Created by yangcihang on 2/24/15.
//
//

#include "arrow.h"



void Arrow::setup() {
    
    pos.set(0);
    
}

void Arrow::update(float _x, float _y) {
    
    ofVec2f newPos;
    newPos.set(_x, _y);
    pos = pos * 0.97 + newPos * 0.03;
    
    ofVec2f diff;
    diff = newPos - pos;
    rot = atan2(diff.y, diff.x);
    rot = ofRadToDeg(rot);
    scale=ofRandom(-1, 1);
}

void Arrow::draw() {
    
    float x1 = 0;
    float y1 = -10;
    
    float x2 = 0;
    float y2 = 10;
    
    float x3 = 30;
    float y3 = 0;
    
    ofTranslate(pos);
    ofRotate(rot,ofRandom(-1, 1),ofRandom(-1,1),ofRandom(-1, 1));
    float time = ofGetElapsedTimef();
    
        
}