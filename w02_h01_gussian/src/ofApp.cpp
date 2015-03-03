#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    ofSetColor(255, 100);
    ofSetBackgroundAuto(false);
    ofEnableAlphaBlending();
}

//--------------------------------------------------------------
void ofApp::update(){
    float num=ofxGaussian();
    float sd=1234;
    float mean=ofGetWidth();
    float means=ofGetHeight();
    x=(sd*num)+mean;
    y=(sd*num)+means;
}

//--------------------------------------------------------------
void ofApp::draw(){
     ofDrawBitmapString("Move Your Mouse", 20, 33);
    ofSetColor(ofRandom(255),ofRandom(255), ofRandom(255));
    ofLine(x,sin(ofGetElapsedTimef())*800+ofGetHeight()/2, ofGetMouseX(),ofGetMouseY());
    //ofCircle(y, sin(ofGetElapsedTimef())*800+ofGetHeight()/2, 5);
    
     
}

bool haveNextNextGaussian = false;
float nextNextGaussian;

float ofApp::ofxGaussian() {
    if (haveNextNextGaussian){
        haveNextNextGaussian = false;
        return nextNextGaussian;
    }
    else {
        float v1, v2, s;
        do {
            v1 = 2 * ofRandomf() - 1;
            v2 = 2 * ofRandomf() - 1;
            s = v1 * v1 + v2 * v2;
        }
        while (s >= 1 || s == 0);
        
        float multiplier = sqrt(-2 * log(s)/s);
        nextNextGaussian = v2 * multiplier;
        haveNextNextGaussian = true;
        
        return v1 * multiplier;
    }
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
