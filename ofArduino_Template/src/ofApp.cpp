#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ard.connect("/dev/cu.usbmodem1411", 57600);
    ofAddListener( ard.EInitialized, this, &ofApp::arduinoSetup);
    isArdSetup = false;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    arduinoUpdate();
    
}

//--------------------------------------------------------------
void ofApp::arduinoSetup(const int &version){
    
    ofRemoveListener(ard.EInitialized, this, &ofApp::arduinoSetup);
    isArdSetup = true;
    //此处写入端口设置
    ard.sendDigitalPinMode(9, ARD_INPUT);
    
    ofAddListener(ard.EDigitalPinChanged, this, &ofApp::digitalPinChanged);
    ofAddListener(ard.EAnalogPinChanged, this, &ofApp::analogpinChanged);
}

//--------------------------------------------------------------
void ofApp::arduinoUpdate(){

}

//--------------------------------------------------------------
void ofApp::digitalPinChanged(const int &numPin){
    
    if(numPin == 9){
        if (ard.getDigital(9) == ARD_HIGH) {
            cout<< "Button On" <<endl;
        }
    }

}

//--------------------------------------------------------------
void ofApp::analogpinChanged(const int &numPin){

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
