#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
	ofSetCircleResolution(64);
	ofSetBackgroundAuto(false);
	ofEnableBlendMode(OF_BLENDMODE_ADD);
	color = 100;

	// �w�肵��IP�A�h���X�ƃ|�[�g�ԍ��ŃT�[�o�[�ɐڑ�
	sender.setup(HOST, PORT);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw() {
	ofSetColor(ofRandom(mouseX) / 2, ofRandom(mouseY) / 2, ofRandom(1, 255) * 3, 70);
	ofDrawCircle(mouseX, mouseY, ofRandom(5, 8));
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	// OSCMessage�̏���
	ofxOscMessage m;

	// OSC�A�h���X�̎w��
	m.setAddress("/mouse/position");
	
	// OSC�����Ƃ��Č��݂̃}�E�X�̍��W(x, y)�𑗐M
	m.addIntArg(x);
	m.addIntArg(y);

	// OSCMessage�𑗐M
	sender.sendMessage(m);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	ofxOscMessage m;
	m.setAddress("/mouse/button");
	m.addIntArg(1);
	sender.sendMessage(m);

	ofSetColor(ofRandom(mouseX) / 2, ofRandom(mouseY) / 2, ofRandom(1, 255) * 3, 95);
	ofDrawCircle(mouseX, mouseY, ofRandom(30, 40));
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	ofxOscMessage m;
	m.setAddress("/mouse/button");
	m.addIntArg(0);
	sender.sendMessage(m);

	ofSetColor(ofRandom(mouseX) / 2, ofRandom(mouseY) / 2, ofRandom(1, 255) * 3, 95);
	ofDrawCircle(mouseX, mouseY, ofRandom(30, 40));
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
