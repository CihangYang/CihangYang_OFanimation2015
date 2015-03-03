#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    shader.load( "shaderVert.c", "shaderFrag.c" );
    
    fbo.allocate( ofGetWidth(), ofGetHeight() );
    image.loadImage( "sunflower.png" );
    
    mult = 0.001;
    noisePixels.allocate(ofGetWidth(), ofGetHeight(), OF_IMAGE_COLOR);
}

//--------------------------------------------------------------
void ofApp::update(){

    for (int y = 0;y < ofGetHeight(); y++) {
        for (int x = 0; x < ofGetWidth(); x++) {
            ofFloatColor color = ofFloatColor(ofNoise(x*mult, y*mult));
            noisePixels.setColor(x, y, color);
        }
    }
    
    noiseImg.setFromPixels(noisePixels.getPixels(), noisePixels.getWidth(), noisePixels.getHeight(), OF_IMAGE_COLOR);
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    fbo.begin();		//Start drawing into buffer
    
    //Draw something here just like it is drawn on the screen
    ofSetColor(ofRandom(255),ofRandom(255),ofRandom(255));
     noiseImg.draw(0, 0);

    
   // ofBackgroundGradient( ofColor( 255 ), ofColor( 128 ) );
    ofSetColor( 255, 255, 255 );
    image.draw( 351, 221 );
    
    fbo.end();			//End drawing into buffer
    
    //2. Drawing to screen through the shader
    shader.begin();		//Enable the shader
    
    float time = ofGetElapsedTimef();
    shader.setUniform1f( "time", time );	//Passing float parameter "time" to shader
    
    //Draw fbo image
    ofSetColor( 255, 255, 255 );
    fbo.draw( 0, 0 );
    
    shader.end();		//Disable the shader

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
