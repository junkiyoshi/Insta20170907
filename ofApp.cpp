#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	ofBackground(255);
	ofSetWindowTitle("Insta");

	ofEnableDepthTest();
	//ofNoFill();

	this->light.setAreaLight(2048, 2048);
	this->light.setAmbientColor(ofFloatColor(0.0, 0.0, 0.0, 1.0));
	this->light.setDiffuseColor(ofFloatColor(1.0, 1.0, 1.0));
	this->light.setSpecularColor(ofFloatColor(1.0, 0.0, 0.0));

	this->noise_source = ofRandom(10);
	this->noise_step = 0.025;
}

//--------------------------------------------------------------
void ofApp::update(){
	this->noise_source += this->noise_step;
}

//--------------------------------------------------------------
void ofApp::draw(){

	this->cam.begin();
	ofRotateY(180);

	this->light.setPosition(this->cam.getPosition().normalize() * 2048);
	ofEnableLighting();
	this->light.enable();

	float radius = 100;
	float x, y;
	float tmp_noise_source = this->noise_source;
	float noise_value;
	ofColor body_color;
	for (int deg = 0; deg < 350; deg += 10) {
		x = radius * cos(deg * DEG_TO_RAD);
		y = radius * sin(deg * DEG_TO_RAD);

		ofPushMatrix();
		ofTranslate(x, y, 0);
		ofRotateZ(deg);
		noise_value = ofNoise(tmp_noise_source);
		if (noise_value > 0.5) {
			ofColor c;
			c.setHsb(ofMap(noise_value, 0.5, 1.0, 255, 0), 255, 255);
			ofSetColor(c);
			ofRotateY(ofMap(noise_value, 0.5, 1.0, 0, 360));
		}
		else {
			ofSetColor(128);
		}

		ofBox(15);

		ofPopMatrix();

		tmp_noise_source += this->noise_step;
	}

	this->cam.end();
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
