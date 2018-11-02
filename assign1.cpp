#include "assign1.h"
#include <cstdlib>

//Julianna Clarke - 101037898
//IMD 3005
//Anthony Scavarelli
//September 30, 2018

//--------------------------------------------------------------
void ofApp::setup() {
	//set up the spaceship buy loading image, setting initial angle and positions
	m_spaceship.load("spaceship.png");
	m_spaceship.setAnchorPoint(m_spaceship.getWidth() / 2, m_spaceship.getHeight() / 2);
	m_shipAngle = 0.0f;
	m_shipPos = ofVec2f(ofGetWindowWidth() / 2 + 50, ofGetWindowHeight() / 2 + 50);
	m_targetShipPos = ofVec2f(0, 0);

	m_sunPos = ofVec2f(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2);

	//planet positions
	m_planetPos1 = ofVec2f(100, 0);
	m_planetPos2 = ofVec2f(300, 0);
	m_planetPos3 = ofVec2f(400, 0);
	m_planetPos4 = ofVec2f(150, 400);
	m_planetPos5 = ofVec2f(40, 330);

	//moon positions
	m_p2moon1 = ofVec2f(50, 0);
	m_p2moon2 = ofVec2f(45, 0); 
	m_p4moon1 = ofVec2f(50, 0);

	ofSetBackgroundColor(27, 0, 27);

	for (int i = 0; i < 60; i++) {
		stars[i].x = rand() % 900;
		stars[i].y = rand() % 900;
	}
}

//--------------------------------------------------------------
void ofApp::update() {

	ofVec2f vecToMouse = ofVec2f(ofGetMouseX(), ofGetMouseY()) - m_shipPos;
	m_shipAngle = ofRadToDeg(atan2(vecToMouse.y, vecToMouse.x));

	m_shipPos.x = lerp(m_shipPos.x, m_targetShipPos.x, 0.2);
	m_shipPos.y = lerp(m_shipPos.y, m_targetShipPos.y, 0.2);


	//update planet angles for rotation
	m_planetAng1 += 0.5f;
	m_planetAng2 += -0.2f;
	m_planetAng3 += 0.9f;
	m_planetAng4 += 0.6f;
	m_planetAng5 += -0.8f;

	//update moon angles for rotation
	m_p2moonAng1 += 0.7f;
	m_p2moonAng2 += -1.0f;
	m_p4moonAng1 += 1.0f;
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofSetColor(255);

	for (int i = 0; i < 60; i++) {
		ofDrawCircle(stars[i].x, stars[i].y, 2);
	}

	//draw spaceship at position and new rotation
	ofPushMatrix();
		ofSetColor(255, 255, 255);
		ofTranslate(m_shipPos);
		ofRotate(m_shipAngle);
		ofScale(0.05, 0.05);
		m_spaceship.draw(0, 0);
	ofPopMatrix();
	
	//drawings of planets
	ofSetColor(255, 201, 0);
	ofDrawCircle(m_sunPos.x, m_sunPos.y, 30);

	ofTranslate(450, 450); //position of the sun, so that the planets are drawn in relation to the sun

	//drawings of orbits for planets
	drawOrbit(ofVec3f(0,0,0), 100.0f, 100.0f, 2);
	drawOrbit(ofVec3f(0,0,0), 300.0f, 300.0f, 2);
	drawOrbit(ofVec3f(0,0,0), 400.0f, 400.0f, 2);
	drawOrbit(ofVec3f(0,0,0), 430.0f, 430.0f, 2);
	drawOrbit(ofVec3f(0,0,0), 335.0f, 335.0f, 2);

	//planet 1
	ofPushMatrix();
		ofRotate(m_planetAng1);
		ofTranslate(m_planetPos1);
		ofSetColor(107, 89, 204);
		ofDrawCircle(0, 0, 20);
	ofPopMatrix();

	//planet 2
	ofPushMatrix();
		ofRotate(m_planetAng2);
		ofTranslate(m_planetPos2);
		ofSetColor(237, 66, 17);
		ofDrawCircle(0, 0, 20);
		drawOrbit(ofVec3f(0, 0, 0), 50.0f, 50.0f,1);
		drawOrbit(ofVec3f(0, 0, 0), 45.0f, 45.0f,1);

		//draw two moons for planet 2
		ofPushMatrix();
			ofRotate(m_p2moonAng1);
			ofTranslate(m_p2moon1);
			ofSetColor(127, 255, 212);
			ofDrawCircle(0, 0, 5);
		ofPopMatrix();
		ofPushMatrix();
			ofRotate(m_p2moonAng2);
			ofTranslate(m_p2moon2);
			ofSetColor(172, 229, 238);
			ofDrawCircle(0, 0, 5);
		ofPopMatrix();
	ofPopMatrix();

	//planet 3
	ofPushMatrix();
		ofRotate(m_planetAng3);
		ofTranslate(m_planetPos3);
		ofSetColor(0, 128, 117);
		ofDrawCircle(0, 0, 20);
	ofPopMatrix();

	//planet 4
	ofPushMatrix();
		ofRotate(m_planetAng4);
		ofTranslate(m_planetPos4);
		ofSetColor(0, 50, 120);
		ofDrawCircle(0, 0, 20);
		drawOrbit(ofVec3f(0, 0, 0), 50.0f, 50.0f,1);

		//draw the moon for planet 4
		ofPushMatrix();
			ofRotate(m_p4moonAng1);
			ofTranslate(m_p4moon1);
			ofSetColor(225, 124, 109);
			ofDrawCircle(0, 0, 5);
		ofPopMatrix();
	ofPopMatrix();

	//planet 5
	ofPushMatrix();
		ofRotate(m_planetAng5);
		ofTranslate(m_planetPos5);
		ofSetColor(255, 255, 255);
		ofDrawCircle(0, 0, 20);
	ofPopMatrix();
}


//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	m_targetShipPos.x = (float)x;
	m_targetShipPos.y = (float)y;
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
	m_targetShipPos.x = (float)x;
	m_targetShipPos.y = (float)y;
}

//--------------------------------------------------------------
float ofApp::lerp(float start, float end, float percent) {
	return(start + percent * (end - start));
}

void ofApp::drawOrbit(ofVec3f centre, float radX, float radY, int stroke) {
	ofPath circle;
	circle.setArcResolution(100);
	circle.arc(centre, radX, radY, 0.0f, 360.0f);
	circle.close();
	circle.arc(centre, radX - stroke, radY - stroke, 0.0f, 360.0f);
	circle.draw();
}

