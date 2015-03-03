//
//  customCircle.cpp
//  home1_3
//
//  Created by yangcihang on 2/10/15.
//
//

#include "customCircle.h"
customCircle::customCircle(){
}

void customCircle::setup(ofVec2f _initPos, ofVec2f _finalPos){
    initPos=_initPos;
    finalPos = _finalPos;
    
}

void customCircle::update(float _pct){
    
    pct=_pct;
    currentPos=initPos*(0.5-pct)+finalPos*pct;
    
}

void customCircle::draw(){
    ofCircle(currentPos,10);
    ofSetColor(0,0,0);
}

void customCircle::setNewPosition(ofVec2f _newPos){
    
    initPos=currentPos;
    finalPos= _newPos;
    
}

