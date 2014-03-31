//
//  myLamp.h
//  CGRA-1
//
//  Created by José Pedro Moreira on 26/03/14.
//  Copyright (c) 2014 José Pedro Moreira. All rights reserved.
//

#ifndef __CGRA_1__myLamp__
#define __CGRA_1__myLamp__

#include <iostream>
#include <CGFlight.h>
#include "mySemiSphere.h"

#endif /* defined(__CGRA_1__myLamp__) */


class myLamp: public CGFlight {
    int stacks,slices;
    mySemiSphere sphere;
    
public:
    void draw();
    myLamp(int stacks,int slices,unsigned int lightid, float* pos);
};