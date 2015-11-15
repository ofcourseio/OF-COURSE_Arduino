#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    setupArd	= false;
    ard.connect("/dev/tty.usbmodem1421", 57600);
    ofAddListener(ard.EInitialized, this, &ofApp::setupArduino);
    
}

//--------------------------------------------------------------
void ofApp::update(){

    updateArduino();
}

void ofApp::setupArduino(const int & version){
    
    ofRemoveListener(ard.EInitialized, this, &ofApp::setupArduino);
    setupArd = true;
    cout<<"Arduino ok"<<endl;
    
    ard.sendDigitalPinMode(9, ARD_HIGH);
    ard.sendDigitalPinMode(6, ARD_PWM);
    ard.sendAnalogPinReporting(0, ARD_ANALOG);
    ard.sendAnalogPinReporting(1, ARD_ANALOG);
}

void ofApp::updateArduino(){
    ard.update();
    
    if (setupArd) {
        int val = ofMap(ard.getAnalog(0), 0, 1023, 0, 255);
        ard.sendPwm(6, val);
    }
}
void ofApp::digitalPinChanged(const int & pinNum){
    
    
}

void ofApp::analogPinChanged(const int & pinNum){
    
    if (pinNum == 0) {
        
        
    }
}


//--------------------------------------------------------------
void ofApp::draw(){

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
