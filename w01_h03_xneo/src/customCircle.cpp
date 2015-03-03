//
//  customCircle.cpp
//  01_xenofollowing_
//
//  Created by yangcihang on 2/10/15.
//
//

#include "customCircle.h"

void customCircle::setup(){
    pos.set(0,0);
    circleColor.set(ofRandom(255), ofRandom(255), ofRandom(255));
}

void customCircle::update(ofVec2f _dest){
    ofSetColor(circleColor);
    pos=pos*0.9+ _dest*0.1;

}


void customCircle::draw(){
    ofCircle(pos, 10);

}