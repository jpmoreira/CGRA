//
//  myRobot.cpp
//  CGRA-1
//
//  Created by José Pedro Moreira on 28/04/14.
//  Copyright (c) 2014 José Pedro Moreira. All rights reserved.
//

#include "myRobot.h"




void myRobot::draw(){

    glBegin(GL_TRIANGLES);
    
    glVertex3d(0.5, 0.3, 0);
    glVertex3d(-0.5, 0.3, 0);
    glVertex3d(0, 0.3, 2);
    
    
    glEnd();


}

myRobot::myRobot(int stackNr):stacks(stackNr){

}