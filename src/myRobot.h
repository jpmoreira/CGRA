//
//  myRobot.h
//  CGRA-1
//
//  Created by José Pedro Moreira on 28/04/14.
//  Copyright (c) 2014 José Pedro Moreira. All rights reserved.
//

#ifndef __CGRA_1__myRobot__
#define __CGRA_1__myRobot__

#include <iostream>
#include "CGFobject.h"


class myRobot: public CGFobject {
    
    int stacks;
    double *xx;
    double *zz;
    double *yy;
    double *xx_normal;
    double *zz_normal;
    void drawFace();
    void populateArrays();
public:
    void draw();
    myRobot(int stacksNr);
	
};

#endif /* defined(__CGRA_1__myRobot__) */


