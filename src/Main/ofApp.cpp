#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofBackground(0, 0, 0);
    this->fullScreenWidth = ofGetScreenWidth();
    this->fullScreenHeight = ofGetScreenHeight();
    this->adjustGameScreen();
    this->setTextBox();
    this->showTextBox = false;

    this->updateDim();

    // introMovie.load("videos/redIntro.mp4");
    // introMovie.play();
}

void ofApp::setTextBox() {
    std::string introText1 = "Hello world!My name is Eduardo, and I will be your host for Pokemon Red.Do you have any questions?";
    std::string introText2 = "abcdefabcdeabffcd.";
    std::string introText3 = "abcd efghijklmno.pqrstuvwxyz";
    this->textoBox = new Textbox(5, 0, introText1);
}

//--------------------------------------------------------------
void ofApp::update(){

    // Screen Size change
    if (ofGetWindowWidth() != this->screenWidth || ofGetWindowHeight() != this->screenHeight) {
        this->adjustGameScreen();
        this->updateDim();
    }
    // introMovie.update();

    if (showTextBox) {
        this->textoBox->tick();
    }

}

//--------------------------------------------------------------
void ofApp::draw(){

    this->drawScreen();

    if (showTextBox) {
        this->textoBox->render();
    }

    // introMovie.draw(0, 0, 480, 320);

}

//--------------------------------------------------------------
void ofApp::drawScreen() {

    ofSetColor(255, 255, 255);
    ofDrawRectangle(this->screenStartX, this->screenStartY, this->screenWidth, this->screenHeight);

}

//--------------------------------------------------------------
void ofApp::adjustGameScreen() {

    double curWidth = static_cast<double>(ofGetWindowWidth());
    double curHeight = static_cast<double>(ofGetWindowHeight());
    double newHeight, newWidth, scale;
    
    // Smallest side has priority
    if (curWidth / curHeight > 1.5) {
        scale = curHeight / ORIGINAL_HEIGHT;
        newHeight = curHeight;
        newWidth = scale * ORIGINAL_WIDTH;
    }
    else {
        scale = curWidth / ORIGINAL_WIDTH;
        newWidth = curWidth;
        newHeight = scale * ORIGINAL_HEIGHT;
    }

    this->screenWidth = newWidth;
    this->screenHeight = newHeight;
    this->screenStartX = (curWidth - newWidth) / 2.0;
    this->screenStartY = (curHeight - newHeight) / 2.0;

}

//--------------------------------------------------------------
void ofApp::updateDim(){
    double scale = this->screenWidth / ORIGINAL_WIDTH;
    this->textoBox->scaleDims(this->screenStartX, this->screenStartY, scale);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if  (key == 'a') {
        this->textoBox->toggleNextLine();
    }
    if (key == 'g') {
        this->showTextBox = true;
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
