//
//  myUnitCube.cpp
//  CGRA-1
//
//  Created by José Pedro Moreira on 23/02/14.
//  Copyright (c) 2014 José Pedro Moreira. All rights reserved.
//

#include "myUnitCube.h"


void myUnitCube::draw(){

    
    glNormal3d(0, 0, 1);
    glPushMatrix();
    
    glPushMatrix();
    glTranslated(0, 0, 0.5);
    glRectd(0.5, 0.5, -0.5, -0.5);
    glPopMatrix();
    
    glPushMatrix();
    glTranslated(0.0, 0.5, 0.0);
    glRotated(-90.0, 1, 0, 0);
    glRectd(0.5, 0.5, -0.5, -0.5);
    glPopMatrix();
    
    glPushMatrix();
    glTranslated(0.0, -0.5, 0.0);
    glRotated(90.0, 1, 0, 0);
    glRectd(0.5, 0.5, -0.5, -0.5);
    glPopMatrix();
    
    glPushMatrix();
    glTranslated(0.0, 0.0, -0.5);
    glRotated(180.0, 1, 0, 0);
    glRectd(0.5, 0.5, -0.5, -0.5);
    glPopMatrix();
    
    glPushMatrix();
    glTranslated(0.5, 0.0, 0.0);
    glRotated(90.0, 0.0, 1.0, 0.0);
    glRectd(0.5, 0.5, -0.5, -0.5);
    glPopMatrix();
    
    glPushMatrix();
    glTranslated(-0.5, 0.0, 0.0);
    glRotated(-90.0, 0.0, 1.0, 0.0);
    glRectd(0.5, 0.5, -0.5, -0.5);
    glPopMatrix();
    
    glPopMatrix();

}
