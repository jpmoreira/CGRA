//
//  myRobot.h
//  CGRA-1
//
//  Created by José Pedro Moreira on 28/04/14.
//  Copyright (c) 2014 José Pedro Moreira. All rights reserved.
//

#ifndef __CGRA_1__myRobot__
#define __CGRA_1__myRobot__

#define _USE_MATH_DEFINES

#include <iostream>
#include "CGFobject.h"


class myRobot: public CGFobject {
    
    int stacks;


	double translate_coords[3];

	double xz_rotate_degree;
	double start_point[3];

    public:
    myRobot(int stacksNr);
	
	void draw();
	void moveForward();
	void moveBackward();
	void rotateLeft();
	void rotateRight();	
};

#endif /* defined(__CGRA_1__myRobot__) */


