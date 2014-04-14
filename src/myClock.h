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

class myClock: public CGFobject {
    
    myCylinder * clockBody;
	myClockHand * sec_hand;
	myClockHand * min_hand;
	myClockHand * hour_hand;
public:
    void draw();
    float hoursToAngle(float hour);
	float minsToAngle(float minutes);
	float secsToAngle(float seconds);

	myClock();
	
};


#endif /* defined(__CGRA_1__File__) */
