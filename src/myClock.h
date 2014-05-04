//
//  File.h
//  CGRA-1
//
//  Created by José Pedro Moreira on 07/04/14.
//  Copyright (c) 2014 José Pedro Moreira. All rights reserved.
//

#ifndef __CGRA_1__File__
#define __CGRA_1__File__

#include <iostream>
#include "myCylinder.h"
#include "myClockHand.h"


#define SEC_HAND_WIDTH 0.05
#define SEC_HAND_HEIGHT 0.4
#define MIN_HAND_WIDTH 0.075
#define MIN_HAND_HEIGHT 0.3
#define HOUR_HAND_WIDTH 0.1
#define HOUR_HAND_HEIGHT 0.2

#define DEGREES_PER_SEC 6
#define DEGREES_PER_MIN 0.1

class myClock: public CGFobject {
    
    myCylinder * clockBody;
	myClockHand * sec_hand;
	myClockHand * min_hand;
	myClockHand * hour_hand;
	unsigned long time;
public:
    void draw();
	void drawHands();
	void update(unsigned long milisec);
    float hoursToAngle(float hour);
	float minsToAngle(float minutes);
	float secsToAngle(float seconds);

	myClock();
	
};


#endif /* defined(__CGRA_1__File__) */
