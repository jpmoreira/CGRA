//
//  mySemySphere.cpp
//  CGRA-1
//
//  Created by José Pedro Moreira on 26/03/14.
//  Copyright (c) 2014 José Pedro Moreira. All rights reserved.
//

#include "mySemiSphere.h"
#include "coordinateSystems.h"


mySemiSphere::mySemiSphere(int stackNr,int slicesNr):slices(slicesNr),stacks(stackNr){
}

void mySemiSphere::draw(bool bothSides){
    
    
    
    glBegin(GL_QUADS);
    
    for (int i=0; i<stacks; i++) {//dont draw last one since las one should be composed of triangles
        this->drawRing(i,false);
        if (bothSides) this->drawRing(i,true);
    }
    
    glEnd();
    
    
    
}


void mySemiSphere::drawRing(int stackNr,bool inverted){
    
    //TODO: Implement it
    
    SphericalPoint pt1;
    SphericalPoint pt2;
    SphericalPoint pt3;
    SphericalPoint pt4;
    
    CartesianPoint _pt1;
    CartesianPoint _pt2;
    CartesianPoint _pt3;
    CartesianPoint _pt4;
    
    pt1.r=1.0;
    pt2.r=1.0;
    pt3.r=1.0;
    pt4.r=1.0;
    
    
    
    pt1.phy=90-90.0/stacks*(stackNr+1);
    pt4.phy=90-90.0/stacks*(stackNr+1);
    pt2.phy=90-90.0/stacks*stackNr;
    pt3.phy=90-90.0/stacks*stackNr;
    
    
    
    
    for (int i=0; i<slices; i++) {
        
        pt1.rho=-180./slices+360./slices*i;
        pt2.rho=-180./slices+360./slices*i;
        pt3.rho=180./slices+360./slices*i;
        pt4.rho=180./slices+360./slices*i;

        _pt1=sphericalToCartesian(&pt1);
        _pt2=sphericalToCartesian(&pt2);
        _pt3=sphericalToCartesian(&pt3);
        _pt4=sphericalToCartesian(&pt4);
        
        
        if (inverted) {
            glNormal3d(-1*_pt1.x,-1*_pt1.y, -1*_pt1.z);
            glVertex3d(_pt1.x, _pt1.y, _pt1.z);
            
            glNormal3d(-1*_pt2.x, -1*_pt2.y, -1*_pt2.z);
            glVertex3d(_pt2.x, _pt2.y, _pt2.z);
            
            glNormal3d(-1*_pt3.x, -1*_pt3.y, -1*_pt3.z);
            glVertex3d(_pt3.x, _pt3.y, _pt3.z);
            
            glNormal3d(-1*_pt4.x,-1*_pt4.y,-1*_pt4.z);
            glVertex3d(_pt4.x, _pt4.y, _pt4.z);
        }
        else{
            glNormal3d(_pt1.x, _pt1.y, _pt1.z);
            glVertex3d(_pt1.x, _pt1.y, _pt1.z);
            
            glNormal3d(_pt2.x, _pt2.y, _pt2.z);
            glVertex3d(_pt2.x, _pt2.y, _pt2.z);
            
            glNormal3d(_pt3.x, _pt3.y, _pt3.z);
            glVertex3d(_pt3.x, _pt3.y, _pt3.z);
            
            glNormal3d(_pt4.x, _pt4.y, _pt4.z);
            glVertex3d(_pt4.x, _pt4.y, _pt4.z);
        }
        
        
        
        
        
    }
    
}