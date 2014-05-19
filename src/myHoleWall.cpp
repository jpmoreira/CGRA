//
//  myHoleWall.cpp
//  CGRA-1
//
//  Created by José Pedro Moreira on 12/05/14.
//  Copyright (c) 2014 José Pedro Moreira. All rights reserved.
//

#include "myHoleWall.h"
#define sidePart (1/3.)//part of the plane occupied by the left part
#define topPart (1/3.)//part of the plane occupied by the top part

myHoleWall::myHoleWall(int n):
left(Plane(n)),
right(Plane(n)),
top(Plane(n)),
down(Plane(n))
{

}

void myHoleWall::draw(){

    glPushMatrix();
    
    glScaled(1, 10, 10);
    glRotated(-90, 0, 0, 1);
    
    glPushMatrix();
    glTranslated(0, 0, sidePart+sidePart/2);
    glScaled(1, 1, sidePart);
    
    left.draw();
    glPopMatrix();
    
    glPushMatrix();
    glTranslated(0, 0, -sidePart-sidePart/2);
    glScaled(1, 1, sidePart);
    right.draw();
    glPopMatrix();
    
    glPushMatrix();
    glTranslated(-topPart, 0, 0);
    glScaled(topPart, 1, 1);

    top.draw();
    glPopMatrix();
    
    glPushMatrix();
    glTranslated(topPart, 0, 0);
    glScaled(topPart, 1, 1);
    
    down.draw();
    glPopMatrix();
    
    
    glPopMatrix();

}