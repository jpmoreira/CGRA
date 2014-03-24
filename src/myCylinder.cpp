//
//  myCylinder.cpp
//  CGRA-1
//
//  Created by José Pedro Moreira on 17/03/14.
//  Copyright (c) 2014 José Pedro Moreira. All rights reserved.
//

#include "myCylinder.h"
#include "coordinateSystems.h"


myCylinder::myCylinder(int stackNr,int slicesNr):slices(slicesNr),stacks(stackNr){
}

void myCylinder::draw(){

    
    
    glBegin(GL_QUADS);
    
    for (int i=0; i<stacks; i++) {
        this->drawRing(i);
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
    
    
    //printf("Y= %f stackNr= %d conta= %f\n",cylPt1.y,stackNr,stackNr/(double)stacks);
    
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