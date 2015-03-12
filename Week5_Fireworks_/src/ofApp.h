#pragma once

#include "ofMain.h"
#include "Particle.h"

class Particles {
public:
    Particles();                //Class constructor
    void setup();              //Start particle
    void update( float dt );   //Recalculate physics
    void draw();               //Draw particle
    
    ofPoint pos;               //Position
    ofPoint vel;               //Velocity
    float time;                //Time of living
    float lifeTime;            //Allowed lifetime
    bool live;                 //Is particle live
};

//Control parameters class
class Params {
public:
    void setup();
    ofPoint eCenter;    //Emitter center
    float eRad;         //Emitter radius
    float velRad;       //Initial velocity limit
    float lifeTime;     //Lifetime in seconds
    
    float rotate;   //Direction rotation speed in angles per second
};

extern Params param; //Declaration of a global variable

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    
    Particles p;           //Particle
    ofFbo fbo;            //Off-screen buffer for trails
    float history;        //Control parameter for trails
    float time0;

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    vector<Particle> particleList;
    ofVec2f gravity;
    

		
};
