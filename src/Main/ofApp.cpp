#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofBackground(0, 0, 0);
    this->fullScreenWidth = ofGetScreenWidth();
    this->fullScreenHeight = ofGetScreenHeight();
    this->adjustGameScreen();
    this->setTextBox();
    this->showTextBox = true;

    this->updateDim();

    // introMovie.load("videos/redIntro.mp4");
    // introMovie.play();
}

void ofApp::setTextBox() {
    std::string introText1 = "Hello world!My name is Eduardo, I will be your host for Pokemon Red.Do you have any questions?";
    std::string introText2 = "abcdefabcdeabffcd.";
    this->dummyTextBox = new  Text(DEFAULT_TEXT_SPEED, 0, introText1);
}

//--------------------------------------------------------------
void ofApp::update(){

    this->adjustGameScreen();

    this->updateDim();
    // introMovie.update();

    this->dummyTextBox->tick();

}

//--------------------------------------------------------------
void ofApp::draw(){

    this->drawScreen();

    if (showTextBox) {
        this->dummyTextBox->render();
        // this->dummyTextBox->save();  // Too slow
    }

    // introMovie.draw(0, 0, 480, 320);

}

void ofApp::drawScreen() {

    ofSetColor(255, 255, 255);
    ofDrawRectangle(this->screenStartX, this->screenStartY, this->screenWidth, this->screenHeight);

}

void ofApp::adjustGameScreen() {


    double curWidth = static_cast<double>(ofGetWindowWidth());
    double curHeight = static_cast<double>(ofGetWindowHeight());
    double newHeight, newWidth;
    
    if (curWidth / curHeight > 1.5) {
        newWidth = curWidth;
        newHeight = curWidth * (ORIGINAL_HEIGHT / ORIGINAL_WIDTH);
        if (newHeight > curHeight) {
            newHeight = curHeight;
            newWidth = newHeight * (ORIGINAL_WIDTH / ORIGINAL_HEIGHT);
        } 
    }
    else {
        newHeight = curHeight;
        newWidth = curHeight * (ORIGINAL_WIDTH / ORIGINAL_HEIGHT);
        if (newWidth > curWidth) {
            newWidth = curWidth;
            newHeight = newWidth * (ORIGINAL_HEIGHT / ORIGINAL_WIDTH);
        }
    }

    this->screenWidth = newWidth;
    this->screenHeight = newHeight;
    this->screenStartX = (curWidth - newWidth) / 2.0;
    this->screenStartY = (curHeight - newHeight) / 2.0;

}

//--------------------------------------------------------------
void ofApp::updateDim(){

    // Get current screen dimensions
    double xPixMult = this->screenWidth / ORIGINAL_WIDTH;
    double yPixMult = this->screenHeight / ORIGINAL_HEIGHT;

    this->dummyTextBox->scaleDims(this->screenStartX, this->screenStartY, xPixMult, yPixMult);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if  (key == 'a') {
        this->dummyTextBox->toggleNextLine();
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
