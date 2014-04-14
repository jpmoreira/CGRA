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

#define PATH_CLOCK_TEXTURE "table.png"

#endif


float amb[3]={0.2,0.2,0.2};
float dif[3]={0.6,0.6,0.6};
float spec[3]={0.8,0.8,0.8};
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

myClock::myClock():clockBody(new myCylinder(1,12)),hour_hand(new myClockHand()),min_hand(new myClockHand())
,sec_hand(new myClockHand()){

	CGFappearance *topApp=new CGFappearance(amb, dif, spec, shininess);
	CGFappearance *sideApp=new CGFappearance(amb, dif, spec, shininess);
	myClockHand *hour_hand= new myClockHand();
	myClockHand *min_hand= new myClockHand();
	myClockHand *sec_hand= new myClockHand();
	topApp->setTexture(PATH_CLOCK_TEXTURE);
	clockBody->setTextures(topApp, sideApp);
	clockBody->enableClamp(0, 0);

	this->hour_hand->setAngle(hoursToAngle(3));
	this->min_hand->setAngle(minsToAngle(30));
	this->sec_hand->setAngle(secsToAngle(45));


	//hour_hand->setAngle(90);
	//min_hand->setAngle(180);
	//sec_hand->setAngle(270);

}

void myClock::draw(){

	this->hour_hand->draw();
	this->min_hand->draw(); 
	this->sec_hand->draw();
	glScaled(1,-1, 0.1);
	glRotated(90, 1, 0, 0);
	this->clockBody->draw(1);
}