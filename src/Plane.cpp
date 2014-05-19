#include "Plane.h"
#include <GL/glu.h>



double Plane::sTexCord(double x){
    
    
    double nr;
    if(this->clamp )nr= ((x-this->dx*_numDivisions)/(_numDivisions*(1-2*this->dx)))+offsetX;
    
    
    else nr=x*repX/_numDivisions;
    
    return nr;
    
    
    
}
double Plane::tTexCord(double z){
    
    if(this->clamp )return ((z-this->dy*_numDivisions)/(_numDivisions*(1-2*this->dy)))+offsetY;
    
    
    return z*repY/_numDivisions;
    
}



void Plane::enableCentered(double d_y,double d_x){
    dx=d_x;
    dy=d_y;
    this->clamp=true;

}
void Plane::enableRepeat(double repeatsY,double repeatsX){
    repX=repeatsX;
    repY=repeatsY;
    this->clamp=false;
}

void Plane::addOffset(double offY,double offX){
    offsetX=offX;
    offsetY=offY;
    this->clamp=true;

}





Plane::Plane()
{
	_numDivisions = 1;
    this->clamp=false;
    repX=1;
    repY=1;
    this->offsetX=0;
    this->offsetY=0;
}

Plane::Plane(int n)
{
	_numDivisions = n;
    this->clamp=false;
    repX=n;
    repY=n;
    this->offsetX=0;
    this->offsetY=0;
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
            glTexCoord2d(this->sTexCord(bx),this->tTexCord(0));
				glVertex3f(bx, 0, 0);
				for (int bz = 0; bz<_numDivisions; bz++)
				{
                    glTexCoord2d(this->sTexCord(bx+1),this->tTexCord(bz));
					glVertex3f(bx + 1, 0, bz);
                    glTexCoord2d(this->sTexCord(bx),this->tTexCord(bz+1) );
					glVertex3f(bx, 0, bz + 1);
				}
            
                glTexCoord2d(this->sTexCord(bx+1),this->tTexCord(_numDivisions));

				glVertex3d(bx+ 1, 0, _numDivisions);

			glEnd();
		}
	glPopMatrix();

}


