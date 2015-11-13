#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ard.connect("/dev/tty.usbmodem1421", 57600);
    ofAddListener(ard.EInitialized, this, &ofApp::arduinoSetup);
    isSetupArd = false;
    
    radius = 100;
    color.set(255, 0, 220, 255);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    arduinoUpdate();
    
}
//----------arduino functions ----------------------------------------------------
void ofApp::arduinoSetup(const int & version){
    
    ofRemoveListener(ard.EInitialized, this, &ofApp::arduinoSetup);
    isSetupArd = true;
    
    //led pins
    ard.sendDigitalPinMode(9, ARD_PWM);
    ard.sendDigitalPinMode(6, ARD_PWM);
    
    //knob pins
    ard.sendAnalogPinReporting(0, ARD_ANALOG);
    ard.sendAnalogPinReporting(1, ARD_ANALOG);
    
    ofAddListener(ard.EDigitalPinChanged, this, &ofApp::digitalPinChanged);
    ofAddListener(ard.EAnalogPinChanged, this, &ofApp::analogPinChanged);
    
}

void ofApp::arduinoUpdate(){
    
    ard.update();
    if (isSetupArd) {
        int val01 = ofMap(ard.getAnalog(0), 0, 1023, 0, 255);
        int val02 = ofMap(ard.getAnalog(1), 0, 1023, 0, 255);
        
        ard.sendPwm(9, val01);
        ard.sendPwm(6, val02);
    }
}

void ofApp::digitalPinChanged(const int &pinNum){ //Digital Pin change
    
    
    
}

void ofApp::analogPinChanged(const int &pinNum){ //Analog Pin change
    
    if (pinNum == 0) {
        
        radius = ofMap(ard.getAnalog(pinNum), 0, 1023, 100, ofGetWidth()/2);
        cout<<"analog 0:  "<<ofToString(ard.getAnalog(pinNum))<<endl;
        
    }else if(pinNum == 1){
        
        color.a = ofMap(ard.getAnalog(pinNum), 0, 1023, 0, 255);
        cout<<"analog 1:  "<<ofToString(ard.getAnalog(pinNum))<<endl;

    }
    
}
//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(color);
    ofCircle(ofGetWidth()/2, ofGetHeight()/2, radius);

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
