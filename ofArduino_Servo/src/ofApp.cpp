#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    bSetupArduino	= false;
    ard.connect("/dev/tty.usbmodem1421", 57600);
    ofAddListener(ard.EInitialized, this, &ofApp::setupArduino);
    angle = 0;
    ofBackground(30, 30, 30);
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
    
    // 输出Firmware的版本
    ofLogNotice() << ard.getFirmwareName();
    ofLogNotice() << "firmata v" << ard.getMajorFirmwareVersion() << "." << ard.getMinorFirmwareVersion();

    // D9口连接到舵机
    // 舵机只能连接到 D3, D5, D6, D9, D10, or D11
    ard.sendServoAttach(9);
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    if (bSetupArduino) {
        ofPushMatrix();
        ofTranslate(ofGetWidth()/2,ofGetHeight()/2);
        ofRotate(angle-90);
        ofSetColor(255);
        ofDrawArrow(ofPoint(0,0), ofPoint(0,-150));
        ofCircle(0, 0, 5);
        ofPopMatrix();
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case OF_KEY_RIGHT:
            // 旋转到180度
            angle = 180;
            ard.sendServo(9,  angle, false);
           
            break;
        case OF_KEY_LEFT:
            // 旋转到0度
            angle = 0;
            ard.sendServo(9, angle, false);
            break;
        default:
            break;
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
