//
//  myUnitCube.cpp
//  CGRA-1
//
//  Created by José Pedro Moreira on 23/02/14.
//  Copyright (c) 2014 José Pedro Moreira. All rights reserved.
//

#include "myUnitCube.h"


void myUnitCube::draw(){
    
    
    glBegin(GL_QUADS);

    //front face
    glNormal3d(0, 0, 1);
    glVertex3d(-0.5, 0.5, 0.5);
    glVertex3d(-0.5, -0.5, 0.5);
    glVertex3d(0.5, -0.5, 0.5);
    glVertex3d(0.5, 0.5, 0.5);
    
    
    //back face
    glNormal3d(0, 0, -1);
    glVertex3d(0.5, 0.5, -0.5);
    glVertex3d(0.5, -0.5, -0.5);
    glVertex3d(-0.5, -0.5, -0.5);
    glVertex3d(-0.5, 0.5, -0.5);
    
    //top face
    glNormal3d(0, 1, 0);
    glVertex3d(0.5, 0.5, 0.5);
    glVertex3d(0.5, 0.5, -0.5);
    glVertex3d(-0.5, 0.5, -0.5);
    glVertex3d(-0.5, 0.5, 0.5);
    
    
    //bottom face
    glNormal3d(0, -1, 0);
    glVertex3d(-0.5, -0.5, 0.5);
    glVertex3d(-0.5, -0.5, -0.5);
    glVertex3d(0.5, -0.5, -0.5);
    glVertex3d(0.5, -0.5, 0.5);
    
    //left face
    
    glNormal3d(-1, 0, 0);
    glVertex3d(-0.5, 0.5, 0.5);
    glVertex3d(-0.5, 0.5, -0.5);
    glVertex3d(-0.5, -0.5, -0.5);
    glVertex3d(-0.5, -0.5, 0.5);
    
    //right face
    
    glNormal3d(1, 0, 0);
    glVertex3d(0.5, -0.5, 0.5);
    glVertex3d(0.5, -0.5, -0.5);
    glVertex3d(0.5, 0.5, -0.5);
    glVertex3d(0.5, 0.5, 0.5);

    glEnd();
    

}




