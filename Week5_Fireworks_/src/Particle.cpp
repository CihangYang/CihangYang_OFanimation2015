//
//  Particle.cpp
//  Week5_Fireworks_
//
//  Created by yangcihang on 3/10/15.
//
//

#include "Particle.h"

Particle::Particle(ofVec2f _pos) {
    pos.set(_pos);
    
    vel.x = ofRandom(-2, 2);
    vel.y = ofRandom(-1, -9);
    lifespan = 255;
}

void Particle::setup() {
}

void Particle::resetForces() {
    acc *= 0;
}

void Particle::applyForce(ofVec2f force) {
    acc += force;
}

void Particle::update() {
    vel += acc;
    pos += vel;
    
    if (lifespan > 0) lifespan -= 3.0;
    
}

void Particle::draw() {
    ofSetColor(lifespan);
    ofCircle(pos, 2);
}
