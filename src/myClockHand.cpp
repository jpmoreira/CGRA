#include "MyClockHand.h"




// Coefficients for material
float ch_amb[3] = {0.1, 0.1, 0.1};
float ch_dif[3] = {0.2, 0.2, 0.2};
float ch_spec[3] = {0.1, 0.1, 0.1};
float ch_shininess = 40.f;



myClockHand::myClockHand():angle(0), 
half_width(0.5), 
height(1)
{
	square_half_width= (half_width * SQUARE_WIDTH_PERCENT) / 2;
	square_height= height * SQUARE_HEIGHT_PERCENT;
	material = new CGFappearance(ch_amb, ch_dif, ch_spec, ch_shininess);
}

myClockHand::myClockHand(float height, float width){
	this->height = height;
	this->half_width = width/2.0;
	square_half_width= (half_width * SQUARE_WIDTH_PERCENT) / 2.0; //square width is less than triangle
	square_height= height * SQUARE_HEIGHT_PERCENT;	//square height
	angle= 0;
	material = new CGFappearance(ch_amb, ch_dif, ch_spec, ch_shininess);
}

void myClockHand::draw(){

		
	glPushMatrix();
	material->apply();
	glRotated(-angle, 0, 0, 1); 
	glBegin(GL_QUADS);
	
	glNormal3d(0, 0, 1);
	glVertex3d(-square_half_width, 0, 0);
	glVertex3d(square_half_width, 0, 0);
	glVertex3d(square_half_width, square_height, 0);
	glVertex3d(-square_half_width, square_height, 0);
	
	glEnd();

	glBegin(GL_TRIANGLES);
	
	glNormal3d(0, 0, 1);
	glVertex3d(-half_width, square_height, 0);
	glVertex3d(half_width, square_height, 0);
	glVertex3d(0, height, 0);

	glEnd();

	glPopMatrix();
}

void myClockHand::setAngle(float degrees){

	angle = degrees;
}

float myClockHand::getAngle(){
	return this->angle;
}

