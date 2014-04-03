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
		if(bx == 0){
			glTexCoord2d(0, 0);
			printf("\ngltexcoord(0,0)");
		}
		glVertex3f(bx, 0, 0);


		for (; bz<_numDivisions; bz++)
		{
			if(bx == (_numDivisions-2) && bz== 0){
				glTexCoord2d(1, 0);
				printf("\ngltexcoord(1,0)");
			}
			glVertex3f(bx + 1, 0, bz);


			if(bz == (_numDivisions-2) && bx == 0){
				printf("\ngltexcoord(0,1)");
				glTexCoord2d(0, 1);
			}
			glVertex3f(bx, 0, bz + 1);
		}


		if(bx == (_numDivisions -1)){
			printf("\ngltexcoord(1,1)");
			glTexCoord2d(1, 1);
		}
		glVertex3d(bx+ 1, 0, _numDivisions);
		
		bz= 0;
		glEnd();
	}
	glPopMatrix();

}