#include "MyClockHand.h"


myClockHand::myClockHand():angle(0){}

void myClockHand::draw(){

	glPushMatrix();

	glRotated(- angle, 0, 0, 1); 

	glBegin(GL_QUADS);
		glNormal3d(0, 0, 1);
		glVertex3d(-0.3, -0.5, 0);
		glVertex3d(0.3, -0.5, 0);
		glVertex3d(0.3, 0.2, 0);
		glVertex3d(-0.3, 0.2, 0);
	glEnd();

	glBegin(GL_TRIANGLES);
		glNormal3d(0, 0, 1);
		glVertex3d(-0.5, 0.2, 0);
		glVertex3d(0.5, 0.2, 0);
		glVertex3d(0, 0.5, 0);
	glEnd();
	glPopMatrix();
}