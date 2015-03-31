//
//  Particle.h
//  MidtermPixel
//
//  Created by yangcihang on 3/17/15.
//
//


#include "ofMain.h"

class Particle {
public:
    
    void setup();
    void draw();
    void update();
    
    ofVec2f pos,vel,acc,oldpos;
    float angle;
    ofColor color;
    int age;
};