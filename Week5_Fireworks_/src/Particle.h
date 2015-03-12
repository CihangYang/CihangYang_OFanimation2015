//
//  Particle.h
//  Week5_Fireworks_
//
//  Created by yangcihang on 3/10/15.
//
//

#pragma once

#include "ofMain.h"

class Particle {
public:
    
    
    Particle(ofVec2f _pos);
    
    void setup();
    
    void resetForces();
    void applyForce(ofVec2f force);
    
    void update();
    void draw();
    
    
    ofVec2f pos, vel, acc;
    float lifespan;
    float rad;
    
};
