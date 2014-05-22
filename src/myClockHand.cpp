#include "MyClockHand.h"




// Coefficients for material A
float ch_amb[3] = {0.2, 0.2, 0.2};
float ch_dif[3] = {0.6, 0.6, 0.6};
float ch_spec[3] = {0, 0.8, 0.8};
float ch_shininess = 120.f;


myClockHand::myClockHand():angle(0), 
half_width(0.5), 
height(1)
{
	square_half_width= (half_width * SQUARE_WIDTH_PERCENT) / 2;
	square_height= height * SQUARE_HEIGHT_PERCENT;
}

myClockHand::myClockHand(float height, float width){
	this->height = height;
	this->half_width = width/2.0;
	square_half_width= (half_width * SQUARE_WIDTH_PERCENT) / 2.0;
	square_height= height * SQUARE_HEIGHT_PERCENT;
	angle= 0;
}

void myClockHand::draw(){

	glPushMatrix();
	glRotated(-angle, 0, 0, 1); 
	glBegin(GL_QUADS);
	glNormal3d(0, 0, 1);
	glVertex3d(-square_half_width, 0, 0);
	glVertex3d(square_half_width, 0, 0);
	glVertex3d(square_half_width, square_height, 0);
	glVertex3d(-square_half_width, square_height, 0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glNormal3d(0, 0, 1);
	glVertex3d(-half_width, square_height, 0);
	glVertex3d(half_width, square_height, 0);
	glVertex3d(0, height, 0);
	glColor3f(0.5,0.1,0.8);
	glEnd();
	glPopMatrix();
}

void myClockHand::setAngle(float degrees){

	angle = (float) degrees;
}

float myClockHand::getAngle(){
	return this->angle;
}

