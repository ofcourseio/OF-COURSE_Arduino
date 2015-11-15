#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    
    bSetupArduino	= false;
    ard.connect("/dev/tty.usbmodem1421", 57600);
    ofAddListener(ard.EInitialized, this, &ofApp::setupArduino);
}

//--------------------------------------------------------------
void ofApp::update(){

    ard.update();
    
    //控制接口11上的led渐变
    if (bSetupArduino) {
        ard.sendPwm(11, (int)(128 + 128 * sin(ofGetElapsedTimef())));
    }
    
}


//--------------------------------------------------------------
void ofApp::setupArduino(const int & version) {
    
    ofRemoveListener(ard.EInitialized, this, &ofApp::setupArduino);
    bSetupArduino = true;
    
    // 输出firmware name and version to the console
    ofLogNotice() << ard.getFirmwareName();
    ofLogNotice() << "firmata v" << ard.getMajorFirmwareVersion() << "." << ard.getMinorFirmwareVersion();
    
    // A0-A5口可以做数字输入和输出口 他的对应的数字是14-19
    // 设置A0口为analog input
    ard.sendAnalogPinReporting(0, ARD_ANALOG);
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    if (bSetupArduino) {
        ofSetColor(ard.getAnalog(0), 0, 0);
        ofCircle(ofGetWidth()/2, ofGetHeight()/2, 200);
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
