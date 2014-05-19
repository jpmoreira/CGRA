//
//  myHoleWall.cpp
//  CGRA-1
//
//  Created by José Pedro Moreira on 12/05/14.
//  Copyright (c) 2014 José Pedro Moreira. All rights reserved.
//

#include "myHoleWall.h"
#include <CGFappearance.h>
#define sidePart (1.2/3.)//part of the plane occupied by the left part
#define topPart (1/4.)//part of the plane occupied by the top part


float holeWall_spec[4]={0.8,0.8,0.8,0.8};
float holeWall_amb[4]={0.8,0.8,0.8,0.8};
float holeWall_diff[4]={0.8,0.8,0.8,0.8};
float holeWall_shininess=40.f;


myHoleWall::myHoleWall(int n):
left(Plane(n)),
right(Plane(n)),
top(Plane(n)),
down(Plane(n)),
wallApp(new CGFappearance(holeWall_amb,holeWall_diff,holeWall_spec,holeWall_shininess))
{
    left.enableCentered(-0.1, 0.25);
    right.enableCentered(-0.1, 0.25);
    top.enableCentered(0.0, 0.392);
    down.enableCentered(0.0, 0.392);
    
    down.addOffset(-0.95, 0.0);
    top.addOffset(0.95, 0.0);
    left.addOffset(0, -1.46);
    right.addOffset(0, 1.46);
    
    //top.addOffset(0.0, 1.0);
    wallApp->setTexture("window.png");
    wallApp->setTextureWrap(GL_CLAMP_TO_EDGE, GL_CLAMP_TO_EDGE);

}

void myHoleWall::draw(){

    wallApp->apply();
    glPushMatrix();
   
    //glScaled(1, 10, 10);
    glRotated(90, 1, 0, 0);
    glRotated(-90, 0, 0, 1);
    
  
    
    
    glPushMatrix();
    glTranslated(0, 0, topPart/2+(1-2*topPart)/2);
    glScaled(1, 1, topPart);
    
    down.draw();
    glPopMatrix();
 
    glPushMatrix();
    glTranslated(0, 0, -(topPart/2+(1-2*topPart)/2));
    glScaled(1, 1, topPart);
    top.draw();
    glPopMatrix();
  
    glPushMatrix();
    glTranslated(-(sidePart/2+(1-2*sidePart)/2), 0, 0);
    glScaled(sidePart, 1, 1-2*topPart);

    left.draw();
    glPopMatrix();
   
    glPushMatrix();
    glTranslated(sidePart/2+(1-2*sidePart)/2, 0, 0);
    glScaled(sidePart, 1, 1-2*topPart);
    
    right.draw();
    
    glPopMatrix();
    
    
    

    
    glPopMatrix();

}