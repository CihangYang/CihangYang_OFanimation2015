#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(255);
    for(int i=0; i<N; i++){
        myCircle[i].setup(ofVec2f(ofRandom(0,500), ofRandom(0,500)), ofVec2f(ofGetWindowWidth(), 500));
        
    }
    pct=0;

}

//--------------------------------------------------------------
void ofApp::update(){
    pct +=0.01;
    for(int i=0; i<N; i++){
        myCircle[i].update(pct);
    }
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i= 0;i<N;i++ ){
        myCircle[i].draw();
        
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
    pct=0.0;
    for(int i=0; i<N; i++){
        myCircle[i].setNewPosition(ofVec2f(x,y));
  
    }
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
