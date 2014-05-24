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
#include "myUnitCube.h"

#define MAX_TEXTURE_NR 3
#define MIN_TEXTURE_NR 1

float robot_spec[4]={0.5,0.5,0.5,0.8};
float robot_amb[4]={0.8,0.8,0.8,0.8};
float robot_diff[4]={0.8,0.8,0.8,0.8};
float robot_shininess=40.f;


#pragma mark - Drawing Methods

void myRobot::draw(){

	GLint previousValues[2];
	glGetIntegerv(GL_POLYGON_MODE, previousValues);


	if (wireFrameMode) {
		glPolygonMode(GL_FRONT, GL_LINE);
		glPolygonMode(GL_BACK, GL_LINE);
	}
	
	switch (appearence)
	{
	case 1:
		robotAppearance->apply();
		break;
	case 2: 
		robotAppearance2->apply();
		break;
	case 3: 
		robotAppearance3->apply();
		break;
	default:
		robotAppearance->apply();
		break;
	}

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
				glTexCoord2d(xx[index1]+0.5, -zz[index1]+0.5); // 0 0
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
			//printf("1:\nxnormal=%f\n ynormal=%f\n znormal=%f\n",xx_normal[index1], 0.0, zz_normal[index1]);
			glVertex3d(xx[index1], yy[line], zz[index1]);

			//printf("x=%f y=%f z=%f\n",xx[index1], yy[line], zz[index1]);

			if (faceNr==0) {
				glTexCoord2d(xx[index2]+0.5, -zz[index2]+0.5); //1 0
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
			//printf("2:\nxnormal=%f\n ynormal=%f\n znormal=%f\n",xx_normal[index2], 0.0, zz_normal[index2]);
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
			//printf("3:\nxnormal=%f\n ynormal=%f\n znormal=%f\n",xx_normal[index3], 0.0, zz_normal[index3]);
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
			//printf("4:\nxnormal=%f\n ynormal=%f\n znormal=%f\n",xx_normal[index4], 0.0, zz_normal[index4]);
			glVertex3d(xx[index4], yy[line+1], zz[index4]);

			//printf("x=%f y=%f z=%f\n",xx[index4], yy[line+1], zz[index4]);


		}
	}


	glEnd();


}


#pragma mark - Constructors
myRobot::myRobot(int stackNr):
	stacks(stackNr),
	appearence(1),
	xx(new double[(stackNr+1)*5]),
	zz(new double[(stackNr+1)*5]),
	zz_normal(new double[(stackNr+1)*5]),
	xx_normal(new double[(stackNr+1)*5]),
	yy(new double[stackNr+1]),
	robotAppearance(new CGFappearance(robot_amb,robot_diff,robot_spec,robot_shininess)),
	robotAppearance2(new CGFappearance(robot_amb,robot_diff,robot_spec,robot_shininess)),
	robotAppearance3(new CGFappearance(robot_amb,robot_diff,robot_spec,robot_shininess)),
	//textureNr(1),
	wireFrameMode(false),
	xz_rotate_degree(0)
{

	std::cout<<myRobot::nameForTexture(1);
	robotAppearance->setTexture(myRobot::nameForTexture(1));
	robotAppearance2->setTexture(myRobot::nameForTexture(2));
	robotAppearance3->setTexture(myRobot::nameForTexture(3));
	populateArrays();
	translate_coords[0] = 8.5;
	translate_coords[1]= 0;
	translate_coords[2]= 8;
}

#pragma mark - Helper Methods


void myRobot::populateArrays(){

	for (int h=0; h<=stacks; h++) {//for each height
		yy[h]=1.0/stacks*h;
		//printf(" yy= %f",yy[h]);
		for (int i=0; i<5; i++) {

			double angle=90.0/4.0*i-45.0; //explicar
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

			//printf("populate x+z: %f\n", sqrt(zz_normal[h*5+i]*zz_normal[h*5+i]+ xx_normal[h*5+i]*xx_normal[h*5+i]));



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

	if (nr>MAX_TEXTURE_NR)
		nr=MAX_TEXTURE_NR;
	if(nr<MIN_TEXTURE_NR)
		nr=MIN_TEXTURE_NR;


	string name="robot"+to_string(nr)+".jpg";

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32)
	name="C:\\Users\\Daniel\\Documents\\Visual Studio 2012\\Projects\\CGRA__DEV\\Debug\\"+name;
#endif

	//std::cout<<"texture name: "<<name<<endl;
	return name;
}

#pragma mark - Methods for GUI

void myRobot::setWireframeMode(bool enabled){
	wireFrameMode=enabled;
}

void myRobot::switchTexture(int nr){
	appearence = nr;
}


void myRobot::changeWireframe(){
	wireFrameMode = !wireFrameMode;
}
