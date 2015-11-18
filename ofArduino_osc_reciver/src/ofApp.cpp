//连接led到D6, D9号


#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){


    ard.connect("/dev/tty.usbmodem1411", 57600);
    ofAddListener( ard.EInitialized, this, &ofApp::arduinoSetup);
    isArdSetup = false;
    
    receiver.setup(12345); //输入串口数字
    
    x = ofGetWidth()/2;
    y = ofGetHeight()/2;
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    arduinoUpdate();
    
    while (receiver.hasWaitingMessages()) {
        ofxOscMessage m;
        receiver.getNextMessage(m);
        
        if (m.getAddress() == "/3/xy") { //输入数据地址
            x = m.getArgAsFloat(0); //获得第一组浮点数据
            y = m.getArgAsFloat(1); //获得第二组浮点数据
        }
        
        if (m.getAddress() == "/3/toggle1") { //输入数据地址
            ledToggle = m.getArgAsFloat(0); //获得第一组浮点数据
        }
        
    }

    
}

//--------------------------------------------------------------
void ofApp::arduinoSetup(const int &version){
    
    ofRemoveListener(ard.EInitialized, this, &ofApp::arduinoSetup);
    isArdSetup = true;
    
    ard.sendDigitalPinMode(9, ARD_OUTPUT);
    ard.sendDigitalPinMode(6, ARD_PWM);
    
    ard.sendDigital(9, ARD_HIGH);

    
    ofAddListener(ard.EDigitalPinChanged, this, &ofApp::digitalPinChanged);
    ofAddListener(ard.EAnalogPinChanged, this, &ofApp::analogpinChanged);
}

//--------------------------------------------------------------
void ofApp::arduinoUpdate(){
    
    ard.update();
    
    if (isArdSetup) {
        ofPoint touchPos(x,y);
        ofPoint endPos(1.0, 1.0);
        float dis = touchPos.distance(endPos);

        ard.sendPwm(6, ofMap(dis, 0, 1.4, 0, 255, true));
        
        if (ledToggle == 1.0) {
            ard.sendDigital(9, ARD_HIGH);
        }else if(ledToggle == 0.0){
            ard.sendDigital(9, ARD_LOW);
        }
    }
}

//--------------------------------------------------------------
void ofApp::digitalPinChanged(const int &numPin){

}

//--------------------------------------------------------------
void ofApp::analogpinChanged(const int &numPin){

}

//--------------------------------------------------------------
void ofApp::draw(){

    if (ledToggle) {
        ofSetColor(0, 255, 220);

    }else{
        ofSetColor(255, 0, 220);

    }
    ofDrawCircle(x*ofGetWidth(), y*ofGetHeight(), 50);
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
