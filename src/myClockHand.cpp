#include "MyClockHand.h"


myClockHand::myClockHand():angle(0){}

void myClockHand::draw(){

	glBegin(GL_QUADS);
	glNormal3d(0, 0, 1);
		glVertex3d(-0.4, -0.5, 0);
		glVertex3d(0.4, -0.5, 0);
		glVertex3d(0.4, 0.35, 0);
		glVertex3d(-0.4, 0.35, 0);
	glEnd();
	
	glBegin(GL_TRIANGLES);
	glNormal3d(0, 0, 1);
		glVertex3d(-0.5, 0.35, 0);
		glVertex3d(0.5, 0.35, 0);
		glVertex3d(0, 0.5, 0);
	glEnd();
}