//
//  myRobot.cpp
//  CGRA-1
//
//  Created by José Pedro Moreira on 28/04/14.
//  Copyright (c) 2014 José Pedro Moreira. All rights reserved.
//

#include "myRobot.h"
#include <math.h>
#include "coordinateSystems.h"


#pragma mark - Drawing Methods

void myRobot::draw(){
    
    
    
    glPushMatrix();
    
    glTranslated(translate_coords[0], 0 , translate_coords[2]);
	glRotated(xz_rotate_degree, 0, 1, 0);
    
    drawFace();
    
    glRotated(90, 0, 1, 0);
    drawFace();
    
    glRotated(90, 0, 1, 0);
    drawFace();
    
    glRotated(90, 0, 1, 0);
    drawFace();
    
    glPopMatrix();
    
}

void myRobot::drawFace(){
    
    glBegin(GL_QUADS);
    
    for (int line=0; line<stacks; line++) {
        for (int square=0; square<=3; square++) {
            
            int index1=line*5+square;
            int index2=line*5+square+1;
            int index3=(line+1)*5+square+1;
            int index4=(line+1)*5+square;
            
            glNormal3d(xx_normal[index1], 0, zz_normal[index1]);
            glVertex3d(xx[index1], yy[line], zz[index1]);
            
            //printf("x=%f y=%f z=%f\n",xx[index1], yy[line], zz[index1]);
            
            glNormal3d(xx_normal[index2], 0, zz_normal[index2]);
            glVertex3d(xx[index2], yy[line], zz[index2]);
            
            //printf("x=%f y=%f z=%f\n",xx[index2], yy[line], zz[index2]);
            
            glNormal3d(xx_normal[index3], 0, zz_normal[index3]);
            glVertex3d(xx[index3], yy[line+1], zz[index3]);
            
            //printf("x=%f y=%f z=%f\n",xx[index3], yy[line+1], zz[index3]);
            
            glNormal3d(xx_normal[index4], 0, zz_normal[index4]);
            glVertex3d(xx[index4], yy[line+1], zz[index4]);
            
            //printf("x=%f y=%f z=%f\n",xx[index4], yy[line+1], zz[index4]);
            
            
        }
    }

    
    glEnd();
    
    
}


#pragma mark - Constructors
myRobot::myRobot(int stackNr):
stacks(stackNr),
xx(new double[(stackNr+1)*5]),
zz(new double[(stackNr+1)*5]),
zz_normal(new double[(stackNr+1)*5]),
xx_normal(new double[(stackNr+1)*5]),
yy(new double[stackNr+1])
{
    
   
    
    populateArrays();

    
    
}

#pragma mark - Helper Methods


void myRobot::populateArrays(){
    
    for (int h=0; h<=stacks; h++) {//for each height
        yy[h]=1.0/stacks*h;
        //printf(" yy= %f",yy[h]);
        for (int i=0; i<5; i++) {
            
            double angle=90.0/4.0*i-45.0;
            double zOnBase=0.5;
            double xOnBase=tan(angle * M_PI / 180.0)/2;
            
            
            
            
            CylindricalPoint pt;
            pt.y=1.0;
            pt.r=0.25;
            pt.rho=-45.0+90/4.0*i;
            double zOnTop=cylindricalToCartesian(&pt).z;
            double xOnTop=cylindricalToCartesian(&pt).x;
            
            pt.r=1.0;
            pt.y=0;
            double zNormalOnTop=cylindricalToCartesian(&pt).z;
            double xNormalOnTop=cylindricalToCartesian(&pt).x;
            
            
            
            
            zz[h*5+i]=zOnBase+(zOnTop-zOnBase)*yy[h];
            xx[h*5+i]=xOnBase+(xOnTop-xOnBase)*yy[h];
            
            
            zz_normal[h*5+i]=1+(zNormalOnTop-1)*yy[h];
            xx_normal[h*5+i]=xNormalOnTop*yy[h];
            
            double norm=sqrt(zz_normal[h*5+i]*zz_normal[h*5+i]+xx_normal[h*5+i]*xx_normal[h*5+i]);
            
            zz_normal[h*5+i]/=norm;
            xx_normal[h*5+i]/=norm;
            
            
        }
        
    }
}



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