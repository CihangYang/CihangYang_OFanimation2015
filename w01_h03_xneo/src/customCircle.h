//
//  customCircle.h
//  01_xenofollowing_
//
//  Created by yangcihang on 2/10/15.
//
//

#pragma once

#include "ofMain.h"

class customCircle{
public:
    void setup();
    void update(ofVec2f _dest);
    void draw();
    
    ofVec2f pos;
    
    ofColor circleColor;
    

};