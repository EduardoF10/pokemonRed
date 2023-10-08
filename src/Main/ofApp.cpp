#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofBackground(255, 255, 255);
    this->setTextBox();
    this->showTextBox = true;

    this->updateDim();

    // introMovie.load("videos/redIntro.mp4");
    // introMovie.play();
}

void ofApp::setTextBox() {
    this->dummyTextBox = new  Text(3, 0, "Hello world!");
}

//--------------------------------------------------------------
void ofApp::update(){

    this->updateDim();
    // introMovie.update();

}

//--------------------------------------------------------------
void ofApp::draw(){

    if (showTextBox) {
        this->dummyTextBox->render();
    }

    // introMovie.draw(0, 0, 480, 320);

}

//--------------------------------------------------------------
void ofApp::updateDim(){

    // Get current screen dimensions
    double xPixMult = ofGetWidth() / ORIGINAL_WIDTH;
    double yPixMult = ofGetHeight() / ORIGINAL_HEIGHT;

    this->dummyTextBox->scaleDims(xPixMult, yPixMult);

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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
