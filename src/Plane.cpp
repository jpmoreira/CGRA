#include "Plane.h"
#include <GL/glu.h>


Plane::Plane(void)
{
	_numDivisions = 1;
}

Plane::Plane(int n)
{
	_numDivisions = n;
}

Plane::~Plane(void)
{
}

void Plane::draw()
{
	glPushMatrix();
	glRotatef(180.0,1,0,0);
	glTranslatef(-0.5,0.0,-0.5);
	glScalef(1.0/(double) _numDivisions, 1 ,1.0/(double) _numDivisions);
	glNormal3f(0,-1,0);

	for (int bx = 0; bx<_numDivisions; bx++)
	{
		glBegin(GL_TRIANGLE_STRIP);
		glVertex3f(bx, 0, 0);
		for (int bz = 0; bz<_numDivisions; bz++)
		{
			glVertex3f(bx + 1, 0, bz);
			glVertex3f(bx, 0, bz + 1);
		}
		glVertex3d(bx+ 1, 0, _numDivisions);

		glEnd();
	}
	glPopMatrix();

}

void Plane::draw(CGFappearance *appearence){

	glPushMatrix();
	glRotatef(180.0,1,0,0);
	glTranslatef(-0.5,0.0,-0.5);
	glScalef(1.0/(double) _numDivisions, 1 ,1.0/(double) _numDivisions);
	glNormal3f(0,-1,0);

	//appearence->setTextureWrap(GL_CLAMP, GL_CLAMP);
	appearence->apply();
	glVertex2d(0, 0);
	for (int bx = 0; bx<_numDivisions; bx++)
	{

		int bz = 0;

		glBegin(GL_TRIANGLE_STRIP);
		glTexCoord2d((1.0/_numDivisions)*bx, 0);
		glVertex3f(bx, 0, 0);


		for (; bz<_numDivisions; bz++)
		{

			glTexCoord2d((1.0/_numDivisions)*(bx+1), (1.0/_numDivisions)*bz);
			glVertex3f(bx + 1, 0, bz);


			glTexCoord2d((1.0/_numDivisions)*bx, (1.0/_numDivisions)*(bz+1));
			glVertex3f(bx, 0, bz + 1);
		}

		glTexCoord2d((1.0/_numDivisions)*(bx+1), (1.0/_numDivisions)*(bz+1));
		glVertex3d(bx+ 1, 0, _numDivisions);

		bz= 0;
		glEnd();
	}
	glPopMatrix();

}

void Plane::draw(CGFappearance *appearence, double image_height0, double image_width0){

	double width_mult, height_mult, ratio;

	if(image_height0 == image_width0){
		image_width0= image_height0=0;
		width_mult= height_mult =1;
	}
	else if(image_width0 < image_height0){
		height_mult=1;
		ratio= image_width0/ image_height0;
		width_mult= 1+ 1-ratio;
		image_width0= 0 - (1-ratio)/2;
		image_height0=0;
	}
	else{
		width_mult= 1;
		ratio = image_height0/image_width0;
		height_mult= 1+1-ratio;
		image_height0= 0- (1-ratio)/2;
		image_width0=0;
	}

	appearence->setTextureWrap(GL_CLAMP, GL_CLAMP);

	glPushMatrix();
	glRotatef(180.0,1,0,0);
	glTranslatef(-0.5,0.0,-0.5);
	glScalef(1.0/(double) _numDivisions, 1 ,1.0/(double) _numDivisions);
	glNormal3f(0,-1,0);

	//appearence->setTextureWrap(GL_CLAMP, GL_CLAMP);
	appearence->apply();
	glVertex2d(0, 0);
	for (int bx = 0; bx<_numDivisions; bx++)
	{

		int bz = 0;

		glBegin(GL_TRIANGLE_STRIP);
		glTexCoord2d(image_width0+(width_mult/_numDivisions)*bx, 0+image_height0);
	
		glVertex3f(bx, 0, 0);


		for (; bz<_numDivisions; bz++)
		{

			glTexCoord2d(image_width0+(width_mult/_numDivisions)*(bx+1), (height_mult/_numDivisions)*bz+image_height0);
			glVertex3f(bx + 1, 0, bz);


			glTexCoord2d(image_width0+(width_mult/_numDivisions)*bx, (height_mult/_numDivisions)*(bz+1)+image_height0);
			glVertex3f(bx, 0, bz + 1);
		}

		glTexCoord2d(image_width0+(width_mult/_numDivisions)*(bx+1), (height_mult/_numDivisions)*(bz+1)+image_height0);
		glVertex3d(bx+ 1, 0, _numDivisions);

		bz= 0;
		glEnd();
	}
	glPopMatrix();

}