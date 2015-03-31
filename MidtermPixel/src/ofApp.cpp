#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    img.loadImage("merge1.jpg");
    
    ofSetBackgroundAuto(false);
    ofSetFrameRate(30);
    ofEnableAlphaBlending();
    ofBackground(0);

}

//--------------------------------------------------------------
void ofApp::update(){

    
    ofSetWindowTitle(ofToString(ofGetFrameRate(),0));
    for (int i=0; i<particles.size(); i++) {
        particles[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(255);
    
    if (ofGetMousePressed()) {
        img.draw(0,0);
    }
    
    for (int i=0; i<particles.size(); i++) {
        Particle &p = particles[i];
        //p.color = img.getColor(p.pos.x,p.pos.y);
        p.draw();
    }
    
    for (int i=0; i<100; i++) {
        createParticle();
    }
    
    while (particles.size()>1000) {
        particles.erase(particles.begin());
    }

}


void ofApp::createParticle() {
    Particle p;
    p.setup();
    p.pos.set(ofRandomWidth(), ofRandomHeight());
    p.color = img.getColor(p.pos.x,p.pos.y);
  
    particles.push_back(p);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
