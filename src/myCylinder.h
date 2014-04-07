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

#define CENTERED_NORMALS 0
#define VERTEX_NORMALS 1

class myCylinder: public CGFobject {
    int stacks,slices;
    void drawRing(int stackNr);
	void drawRingVertex(int stackNr);
    bool clamp;
    double repX,repY;
    double dx,dy;
    
    double sTexCord(double x);
    double tTexCord(double z);

public:
    void enableClamp(double offsetY,double offsetX);
    void enableRepeat(double repeatsY,double repeatsX);
    void draw(int opt);
    myCylinder(int stacksNr,int slicesNr);
};