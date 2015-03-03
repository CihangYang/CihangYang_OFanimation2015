//
//  arrow.h
//  homework_pattern
//
//  Created by yangcihang on 2/24/15.
//
//

#pragma once

#include "ofMain.h"

class Arrow {
public:
    
    void setup();
    void update(float _x, float _y);
    void draw();
    
    ofVec2f pos;
    float rot;
    float scale;
    
    
    
};
