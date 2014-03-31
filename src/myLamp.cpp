//
//  myLamp.cpp
//  CGRA-1
//
//  Created by José Pedro Moreira on 26/03/14.
//  Copyright (c) 2014 José Pedro Moreira. All rights reserved.
//

#include "myLamp.h"



myLamp::myLamp(int stacks,int slices,unsigned int lightid, float* pos):CGFlight(lightid,pos),sphere(mySemiSphere(stacks, slices)){

}

void myLamp::draw(){

    this->CGFlight::draw();
    glPushMatrix();

    glTranslated(this->position[0],this->position[1], this->position[2]);
    glScaled(0.5, 0.5, 0.5);
    this->sphere.draw(true);
    glPopMatrix();
}