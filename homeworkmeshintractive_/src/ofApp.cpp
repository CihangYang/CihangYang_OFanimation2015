#include "ofApp.h"

#include <iostream>
using namespace std;

//--------------------------------------------------------------
void ofApp::setup(){
    
    
        ofSetFrameRate(60);
    
   /* ofSetSmoothLighting(true);
    light.setPointLight();
    light.setDiffuseColor(ofRandom(255));
    light.setPosition(300, 300, 200);*/

    
    bool succ = true;
    
    succ = image.loadImage("image2.png");
    image.resize(200, 200);
    
    if (!succ) {
        cerr << "loading image failed ...\n";
    }

    
 
    
    
    /*float intensityThreshold = 150.0;
    int w = image.getWidth();
    int h = image.getHeight();
    for (int x=0; x<w; ++x) {
        for (int y=0; y<h; ++y) {
            ofColor c = image.getColor(x, y);
            float intensity = c.getLightness();
            if (intensity >= intensityThreshold) {
                ofVec3f pos(4*x, 4*y, 0.0);
                mesh.addVertex(pos);
                mesh.addColor(c);
            }
        }
    }*/

   
    mesh.setMode(OF_PRIMITIVE_LINES);
    
    float intensityThreshold = 40;
    int w = image.getWidth();
    int h = image.getHeight();
    for (int x=0; x<w; ++x) {
        for (int y=0; y<h; ++y) {
            ofColor c = image.getColor(x, y);
            float intensity = c.getLightness();
            if (intensity >= intensityThreshold) {
                float saturation=c.getSaturation();
                float z=ofMap(saturation, 0, 255, -100, 100);
                
                ofVec3f pos(4*x, 4*y, z);
                mesh.addVertex(pos);
                mesh.addColor(c);
                offsets.push_back(ofVec3f(ofRandom(0,100000), ofRandom(0,100000), ofRandom(0,100000)));
            }
        }
    }
    
    
    float connectionDistance = 15;
    int numVerts = mesh.getNumVertices();
    for (int a=0; a<numVerts; ++a) {
        ofVec3f verta = mesh.getVertex(a);
        for (int b=a+1; b<numVerts; ++b) {
            ofVec3f vertb = mesh.getVertex(b);
            float distance = verta.distance(vertb);
            if (distance <= connectionDistance) {
                mesh.addIndex(a);
                mesh.addIndex(b);
            }
        }
    }
    
    
    
    meshCentroid = mesh.getCentroid();
    
    // Now that we know our centroid, we need to know the polar coordinates (distance and angle)
    // of each vertex relative to that center point.
    // We've found the distance between points before, but what about the angle?
    // This is where atan2 comes in.  atan2(y, x) takes an x and y value and returns the angle relative
    //     to the origin (0,0).  If we want the angle between two points (x1, y1) and (x2, y2) then we
    //     just need to use atan2(y2-y1, x2-x1).
    for (int i=0; i<numVerts; ++i) {
        ofVec3f vert = mesh.getVertex(i);
        float distance = vert.distance(meshCentroid);
        float angle = atan2(vert.y-meshCentroid.y, vert.x-meshCentroid.x);
        distances.push_back(distance);
        angles.push_back(angle);
    }
    
    // These variables will allow us to toggle orbiting on and off
    orbiting = false;
    startOrbitTime = 0.0;
    meshCopy = mesh;        // Store a copy of the mesh, so that we can reload the original state
   
}

//--------------------------------------------------------------
void ofApp::update(){
    
    int numVerts = mesh.getNumVertices();
    for (int i=0; i<numVerts; ++i) {
        ofVec3f vert = mesh.getVertex(i);
        
        float time = ofGetElapsedTimef();
        float timeScale = 5.0;
        float displacementScale = 0.55;
        ofVec3f timeOffsets = offsets[i];
        
        
        vert.x += (ofSignedNoise(time*timeScale+timeOffsets.x)) * displacementScale;
        vert.y += (ofSignedNoise(time*timeScale+timeOffsets.y)) * displacementScale;
        vert.z += (ofSignedNoise(time*timeScale+timeOffsets.z)) * displacementScale;
        mesh.setVertex(i, vert);
        
    }
    
    
    
    if (orbiting) {
        int numVerts = mesh.getNumVertices();
        for (int i=0; i<numVerts; ++i) {
            ofVec3f vert = mesh.getVertex(i);
            float distance = distances[i];
            float angle = angles[i];
            float elapsedTime = ofGetElapsedTimef() - startOrbitTime;
            
            // Lets adjust the speed of the orbits such that things that are closer to
            // the center rotate faster than things that are more distant
            float speed = ofMap(distance, 0, 200, 1, 0.25, true);
            
            // To find the angular rotation of our vertex, we use the current time and
            // the starting angular rotation
            float rotatedAngle = elapsedTime * speed + angle;
            
            // Remember that our distances are calculated relative to the centroid of the mesh, so
            // we need to shift everything back to screen coordinates by adding the x and y of the centroid
            vert.x = distance * cos(rotatedAngle) + meshCentroid.x;
            vert.y = distance * sin(rotatedAngle) + meshCentroid.y;
            
            mesh.setVertex(i, vert);
        }
    }
    
   
    
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofDrawBitmapString("Press R to interact with the Mesh", 32, 32);
    
    cout << mesh.getNumVertices() << endl;
      ofEnableDepthTest();
    //light.draw();
    
    ofColor centerColor = ofColor(85, 78, 68);
    ofColor edgeColor(0, 0, 0);
    ofBackgroundGradient(centerColor, edgeColor, OF_GRADIENT_CIRCULAR);
    easyCam.begin();
    ofPushMatrix();
    ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2);
    
    mesh.draw();
    ofPopMatrix();
    easyCam.end();
    
    //light.enable();
    
   // ofBackground(0,0,255);
    //mesh.draw();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == 'R') {
        orbiting = !orbiting;           // This inverts the boolean
        startOrbitTime = ofGetElapsedTimef();
        mesh = meshCopy;            // This restores the mesh to its original values
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
