
#include "Particle.h"

void Particle::setup() {
    pos.x = ofRandomWidth();
    pos.y = ofRandomHeight();
    vel.x = 2*ofRandomf();
    vel.y = 2*ofRandomf();
    
    
    
    angle = ofRandomf()*TWO_PI;
    age = 0;
}

void Particle::resetForces() {
    acc *= 0;
}

void Particle::applyForce(ofVec2f force) {
    acc += force;
}

void Particle::applyDampingForce(float damping) {
    acc -= vel.getNormalized() * damping;
}

void Particle::update() {
    angle += ofSignedNoise(pos.x, pos.y)*TWO_PI;
    vel.rotate(angle);
    oldPos = pos+ofRandom((ofGetMouseX()/100)*(ofGetMouseY()/100));
    
    //pos += vel;
    age++;
    vel += acc;
    pos += vel;
    
}

void Particle::draw() {
    ofSetColor(ofRandom(1, 255));

    ofLine(oldPos,pos);
  
    
  //glLineWidth(ofRandom(255));
   
}
