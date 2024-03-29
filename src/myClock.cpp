//
//  File.cpp
//  CGRA-1
//
//  Created by José Pedro Moreira on 07/04/14.
//  Copyright (c) 2014 José Pedro Moreira. All rights reserved.
//

#include "myClock.h"


#if defined(WIN32) || defined(_WIN32) || defined(__WIN32)

#define PATH_CLOCK_TEXTURE "C:\\Users\\Daniel\\Documents\\Visual Studio 2012\\Projects\\CGRA__DEV\\Debug\\clock.png"
#else

#define PATH_CLOCK_TEXTURE "clock.png"

#endif


float amb[3]={0.2,0.2,0.2};
float dif[3]={0.6,0.6,0.6};
float spec[3]={0.3,0.3,0.3};
float shininess=40.0f;


float myClock::hoursToAngle(float hour){
	return 30.0 * hour;
}


float myClock::minsToAngle(float mins){
	return 6.0 * mins;
} 


float myClock::secsToAngle(float secs){
	return 6.0 * secs;
} 

void myClock::updateStopped(){
	stopped = !stopped;
}

myClock::myClock():clockBody(new myCylinder(1,12)),hour_hand(new myClockHand(HOUR_HAND_HEIGHT, HOUR_HAND_WIDTH)),
	min_hand(new myClockHand(MIN_HAND_HEIGHT, MIN_HAND_WIDTH)),sec_hand(new myClockHand(SEC_HAND_HEIGHT, SEC_HAND_WIDTH))
	, time(0), stopped(false){

		CGFappearance *topApp=new CGFappearance(amb, dif, spec, shininess);
		CGFappearance *sideApp=new CGFappearance(amb, dif, spec, shininess);
		topApp->setTexture(PATH_CLOCK_TEXTURE);
		clockBody->setTextures(topApp, sideApp);
		clockBody->enableClamp(0, 0);

		this->hour_hand->setAngle(hoursToAngle(3));
		this->min_hand->setAngle(minsToAngle(30));
		this->sec_hand->setAngle(secsToAngle(45));
}

void myClock::draw(){

	glPushMatrix();
	drawHands();
	glScaled(1, 1, 0.1);
	glRotated(90, 1, 0, 0);
	this->clockBody->draw(1);
	glPopMatrix();
}

void myClock::drawHands(){
	glPushMatrix();
	glTranslated(0, 0, 0.1);
	this->hour_hand->draw();
	this->min_hand->draw();
	this->sec_hand->draw();
	glPopMatrix();
}

void myClock::update( unsigned long milisec){
	
	float tmp;
	float degrees;
	if(time!=0 && !stopped)
	{
		tmp= (milisec - time) * 0.001;

		degrees = this->sec_hand->getAngle();
		this->sec_hand->setAngle(degrees + DEGREES_PER_SEC*tmp);

		degrees = this->min_hand->getAngle();
		this->min_hand->setAngle(degrees + DEGREES_PER_MIN*tmp);

		degrees = this->hour_hand->getAngle();
		this->hour_hand->setAngle(degrees + DEGREES_PER_MIN*tmp/60.0);
	}

	this->time = milisec;
}