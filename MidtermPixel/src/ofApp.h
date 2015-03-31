#pragma once

#include "ofMain.h"


#include "Particle.h"
class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    
    void createParticle();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    ofImage img;
     ofImage img1;
    
    vector<Particle> particles;
		
};
