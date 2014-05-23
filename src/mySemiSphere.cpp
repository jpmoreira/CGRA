//
//  mySemySphere.cpp
//  CGRA-1
//
//  Created by José Pedro Moreira on 26/03/14.
//  Copyright (c) 2014 José Pedro Moreira. All rights reserved.
//

#include "mySemiSphere.h"
#include "coordinateSystems.h"


mySemiSphere::mySemiSphere(int stackNr,int slicesNr):
    slices(slicesNr),
    stacks(stackNr),
    xx(new double * [stackNr]),
    yy(new double * [stackNr]),
    zz(new double * [stackNr])
{
    for (int i=0; i<stackNr; i++) {//initialize arrays
        xx[i]=new double[slicesNr];
        yy[i]=new double[slicesNr];
        zz[i]=new double[slicesNr];
    }
    
    this->populateArrays();
    
    
}

void mySemiSphere::draw(bool bothSides){
    
    
        drawTop();

    
    for (int i=0; i<stacks-1; i++) {
        drawRing(i);
    }
    
    if(bothSides){
        drawTop_inverted();
        
        for (int i=0; i<stacks-1; i++) {
            drawRing_inverted(i);
        }
    
    }
    
    
    
}




void mySemiSphere::drawTop(){
    
    glBegin(GL_TRIANGLE_FAN);
    
    glNormal3d(0, 1.0, 0);
    glVertex3d(0, 1.0, 0);
    
    for (int i=slices-1; i>=0; i--) {
        glNormal3d(xx[stacks-1][i], yy[stacks-1][i], zz[stacks-1][i]);
                glVertex3d(xx[stacks-1][i], yy[stacks-1][i], zz[stacks-1][i]);
    }
    
    glNormal3d(xx[stacks-1][slices-1], yy[stacks-1][slices-1], zz[stacks-1][slices-1]);
    glVertex3d(xx[stacks-1][slices-1], yy[stacks-1][slices-1], zz[stacks-1][slices-1]);
    
    glEnd();

}


void mySemiSphere::drawTop_inverted(){
    
    glBegin(GL_TRIANGLE_FAN);
    
    glNormal3d(0, -1.0, 0);
    glVertex3d(0, 1.0, 0);
    
    for (int i=0; i<slices; i++) {
        glNormal3d(-xx[stacks-1][i], -yy[stacks-1][i], -zz[stacks-1][i]);
        glVertex3d(xx[stacks-1][i], yy[stacks-1][i], zz[stacks-1][i]);
    }
    
    glNormal3d(-xx[stacks-1][0], -yy[stacks-1][0], -zz[stacks-1][0]);
    glVertex3d(xx[stacks-1][0], yy[stacks-1][0], zz[stacks-1][0]);
    
    glEnd();
    
}


void mySemiSphere::drawRing(int stackNr){
    
    
    glBegin(GL_TRIANGLE_STRIP);
    
        glNormal3d(xx[stackNr][0], yy[stackNr][0], zz[stackNr][0]);
    glVertex3d(xx[stackNr][0], yy[stackNr][0], zz[stackNr][0]);
    
    glNormal3d(xx[stackNr+1][0], yy[stackNr+1][0], zz[stackNr+1][0]);
    glVertex3d(xx[stackNr+1][0], yy[stackNr+1][0], zz[stackNr+1][0]);
    
    for (int i=1; i<slices; i++) {
        
        glNormal3d(xx[stackNr][i], yy[stackNr][i], zz[stackNr][i]);
        glVertex3d(xx[stackNr][i], yy[stackNr][i], zz[stackNr][i]);
        
        
        glNormal3d(xx[stackNr+1][i], yy[stackNr+1][i], zz[stackNr+1][i]);
        glVertex3d(xx[stackNr+1][i], yy[stackNr+1][i], zz[stackNr+1][i]);
        
        
    }
    
    glNormal3d(xx[stackNr][0], yy[stackNr][0], zz[stackNr][0]);
    glVertex3d(xx[stackNr][0], yy[stackNr][0], zz[stackNr][0]);
    
    glNormal3d(xx[stackNr+1][0], yy[stackNr+1][0], zz[stackNr+1][0]);
    glVertex3d(xx[stackNr+1][0], yy[stackNr+1][0], zz[stackNr+1][0]);
    
    glEnd();
}

void mySemiSphere::drawRing_inverted(int stackNr){
    
    
    glBegin(GL_TRIANGLE_STRIP);
    
    
    
    
    glNormal3d(-xx[stackNr][0], -yy[stackNr][0], -zz[stackNr][0]);
    glVertex3d(xx[stackNr][0], yy[stackNr][0], zz[stackNr][0]);
    
    glNormal3d(-xx[stackNr+1][0], -yy[stackNr+1][0], -zz[stackNr+1][0]);
    glVertex3d(xx[stackNr+1][0], yy[stackNr+1][0], zz[stackNr+1][0]);
    
    
    for (int i=slices-1; i>0; i--) {
        
        glNormal3d(-xx[stackNr][i], -yy[stackNr][i], -zz[stackNr][i]);
        glVertex3d(xx[stackNr][i], yy[stackNr][i], zz[stackNr][i]);
        
        glNormal3d(-xx[stackNr+1][i], -yy[stackNr+1][i], -zz[stackNr+1][i]);
        glVertex3d(xx[stackNr+1][i], yy[stackNr+1][i], zz[stackNr+1][i]);
        
        
        
        
        
    }
    
    glNormal3d(-xx[stackNr][0], -yy[stackNr][0], -zz[stackNr][0]);
    glVertex3d(xx[stackNr][0], yy[stackNr][0], zz[stackNr][0]);
    
    glNormal3d(-xx[stackNr+1][0], -yy[stackNr+1][0], -zz[stackNr+1][0]);
    glVertex3d(xx[stackNr+1][0], yy[stackNr+1][0], zz[stackNr+1][0]);
    
    
    

    
    
    
    glEnd();
}


void mySemiSphere::populateArrays(){
    
    for (int i=0; i<stacks; i++) {
        this->populateArrays(i);
    }

}
void mySemiSphere::populateArrays(int stackNr){

    SphericalPoint pt;
    CartesianPoint cart_pt;
    pt.r=1.0;//all points have 0.5 radius
    pt.rho=0;
    pt.phy=90*(1-stackNr/(double)stacks);
    for (int i=0; i<slices; i++) {
        pt.rho-=360/(double)slices;
        cart_pt=sphericalToCartesian(&pt);
        xx[stackNr][i]=cart_pt.x;
        yy[stackNr][i]=cart_pt.y;
        zz[stackNr][i]=cart_pt.z;
        
        
    }
    
    
}