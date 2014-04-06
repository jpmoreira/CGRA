#include "Plane.h"
#include <GL/glu.h>



double Plane::sTexCord(double x){
    
    
    if(this->clamp)return (x-this->dx*_numDivisions)/(_numDivisions*(1-2*this->dx));
    return x*repX/_numDivisions;
    
    
    
}
double Plane::tTexCord(double z){
    
    if(this->clamp)return (z-this->dy*_numDivisions)/(_numDivisions*(1-2*this->dy));
    return z*repY/_numDivisions;
    
}



void Plane::enableClamp(double offsetY,double offsetX){
    dx=offsetX;
    dy=offsetY;
    this->clamp=true;
}
void Plane::enableRepeat(double repeatsY,double repeatsX){
    repX=repeatsX;
    repY=repeatsY;
    this->clamp=false;
}



Plane::Plane()
{
	_numDivisions = 1;
    this->clamp=false;
    repX=1;
    repY=1;
}

Plane::Plane(int n)
{
	_numDivisions = n;
    this->clamp=false;
    repX=1;
    repX=1;
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
            glTexCoord2d(this->tTexCord(0),this->sTexCord(bx));
				glVertex3f(bx, 0, 0);
				for (int bz = 0; bz<_numDivisions; bz++)
				{
                    glTexCoord2d(this->tTexCord(bz),this->sTexCord(bx+1));
					glVertex3f(bx + 1, 0, bz);
                    glTexCoord2d(this->tTexCord(bz+1),this->sTexCord(bx) );
					glVertex3f(bx, 0, bz + 1);
				}
            
                glTexCoord2d(this->tTexCord(_numDivisions),this->sTexCord(bx+1));

				glVertex3d(bx+ 1, 0, _numDivisions);

			glEnd();
		}
	glPopMatrix();

}


