//
//  myRobot.cpp
//  CGRA-1
//
//  Created by José Pedro Moreira on 28/04/14.
//  Copyright (c) 2014 José Pedro Moreira. All rights reserved.
//

#include "myRobot.h"

void myRobot::draw(){

	glTranslated(translate_coords[0], 0 , translate_coords[2]);
	glRotated(xz_rotate_degree, 0, 1, 0);

	glBegin(GL_TRIANGLES);

	glVertex3d(0.5, 0.3, 0);
	glVertex3d(-0.5, 0.3, 0);
	glVertex3d(0, 0.3, 2);


	glEnd();


}

myRobot::myRobot(int stackNr):stacks(stackNr){
	/*left_vertex[0] = 0.5;
	left_vertex[1] = 0.3;
	left_vertex[2] = 0.0;

	front_vertex[0] = 0.0;
	front_vertex[1] = 0.3;
	front_vertex[2] = 2.0;

	right_vertex[0] = -0.5;
	right_vertex[1] = 0.3;
	right_vertex[2] = 0.0;*/

	xz_rotate_degree = 0;

	translate_coords[0] = 0;
	translate_coords[1] = 0;
	translate_coords[2] = 0;
}

//void myRobot::drawMovement(){
//	glTranslated(translate_coords[0], 0 , translate_coords[2]);
//	glRotated(xz_rotate_degree, 0, 1, 0);
//	draw();
//
//}


void myRobot::rotateRight(){
	xz_rotate_degree++;
	if(xz_rotate_degree >= 360)
		xz_rotate_degree -= 360;
}


void myRobot::rotateLeft(){
	xz_rotate_degree--;
	if(xz_rotate_degree < 0)
		xz_rotate_degree = 360 + xz_rotate_degree;
}

void myRobot::moveForward(){
	translate_coords[0] += 0.3 * sin(xz_rotate_degree*M_PI/180.0);
	translate_coords[2] += 0.3 * cos(xz_rotate_degree*M_PI/180.0);
}


void myRobot::moveBackward(){
	translate_coords[0] -= 0.3 * sin(xz_rotate_degree*M_PI/180.0);
	translate_coords[2] -= 0.3 * cos(xz_rotate_degree*M_PI/180.0);
}