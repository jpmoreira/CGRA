//
//  myCylinder.cpp
//  CGRA-1
//
//  Created by José Pedro Moreira on 17/03/14.
//  Copyright (c) 2014 José Pedro Moreira. All rights reserved.
//

#include "myCylinder.h"
#include "coordinateSystems.h"



double myCylinder::sTexCord(double x){
    
    
    if(this->clamp)return (x-this->dx*slices)/(slices*(1-2*this->dx));
    return x*repX/slices;
    
    
    
}
double myCylinder::tTexCord(double z){
    
    if(this->clamp)return (z-this->dy*stacks)/(stacks*(1-2*this->dy));
    return z*repY/stacks;
    
}



void myCylinder::enableClamp(double offsetY,double offsetX){
    dx=offsetX;
    dy=offsetY;
    this->clamp=true;
}


void myCylinder::enableRepeat(double repeatsY,double repeatsX){
    repX=repeatsX;
    repY=repeatsY;
    this->clamp=false;
}



myCylinder::myCylinder(int stackNr,int slicesNr):slices(slicesNr),stacks(stackNr),clamp(true){
}

void myCylinder::draw(int opt){


      topText->apply();
    glBegin(GL_TRIANGLE_FAN);
    
    glNormal3d(0, 1, 0);
    glTexCoord2d(0.5, 0.5);
    glVertex3d(0, 0.5, 0);
    
    CylindricalPoint pt;
    CartesianPoint ptCart;
    pt.y=0.5;
    pt.r=0.5;
    
  
    
    for (int i=0; i<slices+1; i++) {
        pt.rho=360./slices*(i-1/2.0);
        ptCart=cylindricalToCartesian(&pt);
        glTexCoord2d(-ptCart.x+0.5, ptCart.z+0.5);
        glVertex3d(ptCart.x, ptCart.y, ptCart.z);
        
    }
    
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    pt.y=-0.5;
    glNormal3d(0, -1, 0);
    
    for (int i=slices+1; i>=0; i--) {
        pt.rho=360./slices*(i-1/2.0);
        ptCart=cylindricalToCartesian(&pt);
        glTexCoord2d(ptCart.x+0.5, ptCart.z+0.5);
        glVertex3d(ptCart.x, ptCart.y, ptCart.z);
        
    }
    
    
    glEnd();

    sideText->apply();

	glBegin(GL_QUADS);
    
  
	if(opt == CENTERED_NORMALS)
		for (int i=0; i<stacks; i++) {
			this->drawRing(i);
		}
	else{
		for (int i=0; i<stacks; i++) {
			this->drawRingVertex(i);
		}
	}

	glEnd();



}


void myCylinder::drawRing(int stackNr){

	//printf("drawing\n");
	float stackHeight=1.0/stacks;
	CylindricalPoint cylPt1,cylPt2,cylNormal;
	cylPt1.r=0.5;
	cylPt1.y=stackNr/(double)stacks-0.5;
	cylPt2.r=0.5;
	cylPt2.y=cylPt1.y+1/(double)stacks;
	cylNormal.y=0;
	cylNormal.r=1.0;
	CartesianPoint cartPt1,cartPt2,cartNormal;


	for (int i=0; i<slices; i++) {

		cylPt1.rho=360./slices*(i-1/2.0);

		cartPt1=cylindricalToCartesian(&cylPt1);
		cylPt2.rho=360./slices*(i+1/2.0);
		cartPt2=cylindricalToCartesian(&cylPt2);
		cylNormal.rho=360./slices*i;
		cartNormal=cylindricalToCartesian(&cylNormal);

		glNormal3d(cartNormal.x, cartNormal.y, cartNormal.z);
        
        
		glVertex3d(cartPt1.x, cartPt1.y, cartPt1.z);
		glVertex3d(cartPt2.x, cartPt1.y, cartPt2.z);
		glVertex3d(cartPt2.x, cartPt2.y, cartPt2.z);
		glVertex3d(cartPt1.x, cartPt2.y, cartPt1.z);



	}

}
void myCylinder::drawRingVertex(int stackNr){

	float stackHeight=1.0/stacks;
	CylindricalPoint cylPt1,cylPt2;
	cylPt1.r=0.5;
	cylPt1.y=stackNr/(double)stacks-0.5;
	cylPt2.r=0.5;
	cylPt2.y=cylPt1.y+1/(double)stacks;
	CartesianPoint cartPt1,cartPt2 ;


	for (int i=0; i<slices; i++) {

		cylPt1.rho=360./slices*(i-1/2.0);

		cartPt1=cylindricalToCartesian(&cylPt1);
		cylPt2.rho=360./slices*(i+1/2.0);
		cartPt2=cylindricalToCartesian(&cylPt2);

		glNormal3d(cartPt1.x, cartPt1.y, cartPt1.z);
        glTexCoord2d(repX/slices*i, repY/stacks*stackNr);
		glVertex3d(cartPt1.x, cartPt1.y, cartPt1.z);

		glNormal3d(cartPt2.x, cartPt1.y, cartPt2.z);
        
        glTexCoord2d(repX/slices*(i+1), repY/stacks*stackNr);
		glVertex3d(cartPt2.x, cartPt1.y, cartPt2.z);

		glNormal3d(cartPt2.x, cartPt2.y, cartPt2.z);
        
        glTexCoord2d(repX/slices*(i+1), repY/stacks*(stackNr+1));
		glVertex3d(cartPt2.x, cartPt2.y, cartPt2.z);

		glNormal3d(cartPt1.x, cartPt2.y, cartPt1.z);
        
        glTexCoord2d(repX/slices*i, repY/stacks*(stackNr+1));
		glVertex3d(cartPt1.x, cartPt2.y, cartPt1.z);



	}

}

void myCylinder::setTextures(CGFappearance *top,CGFappearance *side){

    
    this->topText=top;
    this->sideText=side;

}