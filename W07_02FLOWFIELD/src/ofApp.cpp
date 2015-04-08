#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //ofBackground(0);
    //img.loadImage("bambi2.jpg");
    ofSetBackgroundAuto(false);
    ofNoFill();
    
    //ofSetFrameRate(30);
    ofEnableAlphaBlending();
    ofBackground(0);
    flowField.setup(ofGetWidth(), ofGetHeight(), 20.0);
    //flowField.setRandom(2.0);
    flowField.setNoise();
    
    for (int i = 0; i < 5000; i++) {
        Particle myParticle;
        myParticle.setup();
        particles.push_back(myParticle);
    }
    
    bDrawField = false;
    bDrawBackground = true;

}

//--------------------------------------------------------------
void ofApp::update(){
    
    for (int i = 0; i < particles.size(); i++){
        
        particles[i].resetForces();
        
        //get the force of the flowfield at the particle position
        ofVec2f frc = flowField.getForceAt(particles[i].pos.x, particles[i].pos.y);
        
        //apply force to the particle
        particles[i].applyForce(frc);
        particles[i].applyDampingForce(0.01);
        particles[i].update();
        
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(255, 0, 0);
    
    if(bDrawBackground) ofBackground(0);
    if (bDrawField) flowField.draw();
    
    //ofSetColor(255);
    for (int i = 0; i < particles.size(); i++){
        Particle &p = particles[i];
        p.color = img.getColor(p.pos.x,p.pos.y);
        p.draw();
        
        
    }
    
    for (int i=0; i<50; i++) {
        createParticle();
    }
    
    while (particles.size()>1000) {
        particles.erase(particles.begin());
    }
    
    
    /*for(int i=0;i<particles.size();i++){
        ofLine(particles[i].oldPos.x, particles[i].oldPos.y,particles[i+15].oldPos.x, particles[i+15].oldPos.y);
        ofLine(particles[i].pos.x, particles[i].pos.y,particles[i+15].pos.x, particles[i+15].pos.y);
        
    }*/
    
    
    
    stringstream buf;
    
    buf << "Press 'f' to toggle flowfield draw" << endl <<
    "Press 'b' to toggle background draw" << endl;
    
    ofDrawBitmapString(buf.str(), 20, 20);


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
    
    switch (key) {
        case 'f' | 'F':
            bDrawField = !bDrawField;
            break;
        case 'b' | 'B' :
            bDrawBackground = !bDrawBackground;
            break;
            
        default:
            break;
    }

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
