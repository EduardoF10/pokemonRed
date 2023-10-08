#pragma once

#include "ofMain.h"
#include "../Resources/Text.h"

class ofApp : public ofBaseApp{

	const double ORIGINAL_WIDTH = 240.0;
	const double ORIGINAL_HEIGHT = 160.0;

	private:
	
		void updateDim();
		void setTextBox();
		bool showTextBox;
		Text* dummyTextBox;


	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		double xPixMult;
		double yPixMult;
		double getPixMultX();
		double getPixMultY();
		
		ofVideoPlayer introMovie;
};
