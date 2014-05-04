//
//  myFloor.cpp
//  CGRA-1
//
//  Created by José Pedro Moreira on 23/02/14.
//  Copyright (c) 2014 José Pedro Moreira. All rights reserved.
//

#include "myFloor.h"


myFloor::myFloor(double w,double d, double t):myUnitCube(),width(w),depth(d),thickness(t){}

void myFloor::draw(){
    
    glPushMatrix();
    glScaled(width,thickness,depth);
    this->myUnitCube::draw();
    glPopMatrix();

}