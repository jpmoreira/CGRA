//
//  File.cpp
//  CGRA-1
//
//  Created by José Pedro Moreira on 07/04/14.
//  Copyright (c) 2014 José Pedro Moreira. All rights reserved.
//

#include "myClock.h"


#if defined(WIN32) || defined(_WIN32) || defined(__WIN32)

#define PATH_CLOCK_TEXTURE "C:\\Users\\Daniel\\Documents\\Visual Studio 2012\\Projects\\CGRA__DEV\\Debug\\clock.png"
#else

#define PATH_CLOCK_TEXTURE "table.png"

#endif


float amb[3]={0.2,0.2,0.2};
float dif[3]={0.6,0.6,0.6};
float spec[3]={0.8,0.8,0.8};
float shininess=40.0f;


myClock::myClock():clockBody(new myCylinder(1,12)){
    
    CGFappearance *topApp=new CGFappearance(amb, dif, spec, shininess);
    CGFappearance *sideApp=new CGFappearance(amb, dif, spec, shininess);
    topApp->setTexture(PATH_CLOCK_TEXTURE);
    clockBody->setTextures(topApp, sideApp);
    clockBody->enableClamp(0, 0);

}

void myClock::draw(){
    
	glScaled(1,-1, 0.1);
	glRotated(90, 1, 0, 0);
    this->clockBody->draw(1);

}