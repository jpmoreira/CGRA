//
//  mySemySphere.h
//  CGRA-1
//
//  Created by José Pedro Moreira on 26/03/14.
//  Copyright (c) 2014 José Pedro Moreira. All rights reserved.
//

#ifndef __CGRA_1__mySemySphere__
#define __CGRA_1__mySemySphere__

#include <iostream>
#include <CGFobject.h>

#endif /* defined(__CGRA_1__mySemySphere__) */
class mySemiSphere: public CGFobject {
    int stacks,slices;
    double** xx;
    double** yy;
    double** zz;
    void drawRing(int stackNr);
    
    void drawRing_inverted(int stackNr);
    void drawTop();
    void drawTop_inverted();
    void populateArrays();
    void populateArrays(int stackNr);
public:
    void draw(bool bothSides);
    mySemiSphere(int stacksNr,int slicesNr);
};