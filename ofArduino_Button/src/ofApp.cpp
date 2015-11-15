#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofBackground(30, 30, 30);

    bSetupArduino	= false;
    ard.connect("/dev/tty.usbmodem1421", 57600);
    ofAddListener(ard.EInitialized, this, &ofApp::setupArduino);
    
    player.loadMovie("OFShowreel.mp4");
    player.play();
}

//--------------------------------------------------------------
void ofApp::update(){

    ard.update();
    player.update();
    
}

//--------------------------------------------------------------
void ofApp::setupArduino(const int & version) {
    
    ofRemoveListener(ard.EInitialized, this, &ofApp::setupArduino);
    bSetupArduino = true;
    
    // 输出Firmware的版本
    ofLogNotice() << ard.getFirmwareName();
    ofLogNotice() << "firmata v" << ard.getMajorFirmwareVersion() << "." << ard.getMinorFirmwareVersion();

    // D5设置为Input
    ard.sendDigitalPinMode(19, ARD_INPUT);
    
    //监听arduio的数字和模拟接口变化
    ofAddListener(ard.EDigitalPinChanged, this, &ofApp::digitalPinChanged);
    ofAddListener(ard.EAnalogPinChanged, this, &ofApp::analogPinChanged);
}

//--------------------------------------------------------------
void ofApp::digitalPinChanged(const int & pinNum) {
   
    //当数字接口发生变化时：
    if (pinNum == 19) {
        if (ard.getDigital(pinNum)) {
            if (player.isPaused()) {
                player.setPaused(false);
            }else{
                player.setPaused(true);
            }
        }
    }

}

//--------------------------------------------------------------
void ofApp::analogPinChanged(const int & pinNum) {
    

    //当模拟接口发生变化时：
 
 
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(255);
    player.draw(20,20);
    
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
