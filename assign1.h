#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	ofImage m_spaceship;
	ofVec2f m_shipPos;
	ofVec2f m_targetShipPos;
	float m_shipAngle;

	ofVec2f m_sunPos;

	//planet position initialiation
	ofVec2f m_planetPos1;
	ofVec2f m_planetPos2;
	ofVec2f m_planetPos3;
	ofVec2f m_planetPos4;
	ofVec2f m_planetPos5;

	//moon position initialisations
	ofVec2f m_p2moon1;
	ofVec2f m_p2moon2;
	ofVec2f m_p4moon1;

	//planet angle initialisations
	float m_planetAng1;
	float m_planetAng2;
	float m_planetAng3;
	float m_planetAng4;
	float m_planetAng5;

	//moon angle initialisations
	float m_p2moonAng1;
	float m_p2moonAng2;
	float m_p4moonAng1;

	ofVec2f stars[60];

	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	float lerp(float start, float end, float percent);
	void drawOrbit(ofVec3f centre, float radX, float radY, int stroke);

};