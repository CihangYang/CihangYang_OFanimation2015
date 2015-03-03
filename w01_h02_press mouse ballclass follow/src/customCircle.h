//
//  customCircle.h
//  home1_3
//
//  Created by yangcihang on 2/10/15.
//
//

#pragma once

#include "ofMain.h"

class customCircle {
public:
    customCircle();
    void setup(ofVec2f _initPos, ofVec2f _finalPos);
    void update(float pct);
    void draw();
    void setNewPosition(ofVec2f _newPos);
    
private:
    ofVec2f initPos, finalPos, currentPos;
    float pct;int a;
    
};

