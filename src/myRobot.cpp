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
#include <CGFappearance.h>

#define maxTextNr 4

float robot_spec[4]={0.8,0.8,0.8,0.8};
float robot_amb[4]={0.8,0.8,0.8,0.8};
float robot_diff[4]={0.8,0.8,0.8,0.8};
float robot_shininess=1.f;


#pragma mark - Drawing Methods

void myRobot::draw(){
    
    GLint previousValues[2];
    glGetIntegerv(GL_POLYGON_MODE, previousValues);
    
    
    if (wireFrameMode) {
        glPolygonMode(GL_FRONT, GL_LINE);
        glPolygonMode(GL_BACK, GL_LINE);
    }
    robotAppearance->apply();
    glPushMatrix();
    
    glTranslated(translate_coords[0], 0 , translate_coords[2]);
	glRotated(xz_rotate_degree, 0, 1, 0);
    
    drawFace(0);
    
    glRotated(90, 0, 1, 0);
    drawFace(1);
    
    glRotated(90, 0, 1, 0);
    drawFace(2);
    
    glRotated(90, 0, 1, 0);
    drawFace(3);

    
    glPopMatrix();
    
    glPolygonMode(GL_FRONT, previousValues[0]);
    glPolygonMode(GL_BACK, previousValues[1]);
    
    
}

void myRobot::drawFace(int faceNr){
    
    glBegin(GL_QUADS);
    //printf("Start\n");
    int index1,index2,index3,index4;
    for (int line=0; line<stacks; line++) {
        for (int square=0; square<=3; square++) {
            
            index1=line*5+square;
            index2=line*5+square+1;
            index3=(line+1)*5+square+1;
            index4=(line+1)*5+square;
            
            if (faceNr==0) {
                glTexCoord2d(xx[index1]+0.5, -zz[index1]+0.5);
                //printf("x=%f y=%f\n",xx[index1]+0.5,zz[index1]+0.5);
            }
            else if (faceNr==1) {
                glTexCoord2d(zz[index1]+0.5, xx[index1]+0.5);
            }
            else if (faceNr==2) {
                glTexCoord2d(-xx[index1]+0.5, zz[index1]+0.5);
            }
            else{
                glTexCoord2d(-zz[index1]+0.5, -xx[index1]+0.5);
            }
            
            
            glNormal3d(xx_normal[index1], 0, zz_normal[index1]);
            glVertex3d(xx[index1], yy[line], zz[index1]);
            
            //printf("x=%f y=%f z=%f\n",xx[index1], yy[line], zz[index1]);
            
            if (faceNr==0) {
                glTexCoord2d(xx[index2]+0.5, -zz[index2]+0.5);
            }
            else if (faceNr==1) {
                glTexCoord2d(zz[index2]+0.5, xx[index2]+0.5);
            }
            else if (faceNr==2) {
                glTexCoord2d(-xx[index2]+0.5, zz[index2]+0.5);
            }
            else{
                glTexCoord2d(-zz[index2]+0.5, -xx[index2]+0.5);
            }
            glNormal3d(xx_normal[index2], 0, zz_normal[index2]);
            glVertex3d(xx[index2], yy[line], zz[index2]);
            
            //printf("x=%f y=%f z=%f\n",xx[index2], yy[line], zz[index2]);
            
            
            if (faceNr==0) {
                glTexCoord2d(xx[index3]+0.5, -zz[index3]+0.5);
            }
            else if (faceNr==1) {
                glTexCoord2d(zz[index3]+0.5, xx[index3]+0.5);
            }
            else if (faceNr==2) {
                glTexCoord2d(-xx[index3]+0.5, zz[index3]+0.5);
            }
            else{
                glTexCoord2d(-zz[index3]+0.5, -xx[index3]+0.5);
            }
            glNormal3d(xx_normal[index3], 0, zz_normal[index3]);
            glVertex3d(xx[index3], yy[line+1], zz[index3]);
            
            //printf("x=%f y=%f z=%f\n",xx[index3], yy[line+1], zz[index3]);
            
            
            if (faceNr==0) {
                glTexCoord2d(xx[index4]+0.5, -zz[index4]+0.5);
            }
            else if (faceNr==1) {
                glTexCoord2d(zz[index4]+0.5, xx[index4]+0.5);
            }
            else if (faceNr==2) {
                glTexCoord2d(-xx[index4]+0.5, zz[index4]+0.5);
            }
            else{
                glTexCoord2d(-zz[index4]+0.5, -xx[index4]+0.5);
            }
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
yy(new double[stackNr+1]),
robotAppearance(new CGFappearance(robot_amb,robot_diff,robot_spec,robot_shininess)),
textureNr(1),
wireFrameMode(false)
{
    
    std::cout<<myRobot::nameForTexture(1);
    robotAppearance->setTexture(myRobot::nameForTexture(textureNr));
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

string myRobot::nameForTexture(int nr){
    
    if (nr>maxTextNr) {
        nr=maxTextNr;
    }
    
    string name="robot"+to_string(nr)+".jpg";
    
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32)
    name="C:\\Users\\Daniel\\Documents\\Visual Studio 2012\\Projects\\CGRA__DEV\\Debug\\"+name;
#endif
    
    return name;
}

#pragma mark - Methods for GUI

void myRobot::setWireframeMode(bool enabled){
    wireFrameMode=enabled;
}

void myRobot::switchTexture(int nr){
    robotAppearance->setTexture(myRobot::nameForTexture(nr));
}

