//
//  myCylinder.h
//  CGRA-1
//
//  Created by José Pedro Moreira on 17/03/14.
//  Copyright (c) 2014 José Pedro Moreira. All rights reserved.
//

#ifndef __CGRA_1__myCylinder__
#define __CGRA_1__myCylinder__

#include <iostream>
#include <CGFobject.h>

#endif /* defined(__CGRA_1__myCylinder__) */
class myCylinder: public CGFobject {
    int stacks,slices;
    void drawRing(int stackNr);
public:
    void draw();
    myCylinder(int stacksNr,int slicesNr);
};