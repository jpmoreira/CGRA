//
//  Table.cpp
//  CGRA-1
//
//  Created by José Pedro Moreira on 23/02/14.
//  Copyright (c) 2014 José Pedro Moreira. All rights reserved.
//

#include "myTable.h"

#define lid_thickness 0.3
#define lid_width 5.0
#define lid_depth 3.0

#define leg_height 3.5
#define leg_width 0.3
#define leg_depth 0.3

// Coefficients for material tLid
float amb_tLid[3] = {0.2, 0.12, 0.05};
float dif_tLid[3] = {0.9, 0.4, 0.1};
float spec_tLid[3] = {0.1, 0.1, 0.1};
float shininess_tLid = 40.f;

// Coefficients for material tLeg
float amb_tLeg[3] = {0.2, 0.2, 0.2};
float dif_tLeg[3] = {0.4, 0.4, 0.4};
float spec_tLeg[3] = {0.48, 0.48, 0.48};
float shininess_tLeg = 0.4;


myTable::myTable():CGFobject(),leg(myUnitCube()),lid(myUnitCube()){
    material_tLid= new CGFappearance(amb_tLid, dif_tLid, spec_tLid, shininess_tLid);
	material_tLeg= new CGFappearance(amb_tLeg, dif_tLeg, spec_tLeg, shininess_tLeg);

    
}

void myTable::draw(){
    
    
    
    glPushMatrix();
    glTranslated(0.0, 3.5+0.3/2.0, 0.0);
    glScaled(lid_width, lid_thickness, lid_depth);
	material_tLid->apply();
    lid.draw();
    glPopMatrix();
    
    
    glPushMatrix();
    glTranslated(lid_width/2.0-leg_width/2.0, leg_height/2.0, lid_depth/2.0-leg_depth/2.0);//translate to the right front corner
    glScaled(leg_width, leg_height, leg_depth);
	material_tLeg->apply();
    leg.draw();
    glPopMatrix();
    
    glPushMatrix();
    glTranslated(lid_width/2.0-leg_width/2.0, leg_height/2.0, -(lid_depth/2.0-leg_depth/2.0));//translate to the right back corner
    glScaled(leg_width, leg_height, leg_depth);
    leg.draw();
    glPopMatrix();
    
    glPushMatrix();
    glTranslated(-(lid_width/2.0-leg_width/2.0), leg_height/2.0, -(lid_depth/2.0-leg_depth/2.0));//translate to the right back corner
    glScaled(leg_width, leg_height, leg_depth);
    leg.draw();
    glPopMatrix();
    
    glPushMatrix();
    glTranslated(-(lid_width/2.0-leg_width/2.0), leg_height/2.0, lid_depth/2.0-leg_depth/2.0);//translate to the right front corner
    glScaled(leg_width, leg_height, leg_depth);
    leg.draw();
    glPopMatrix();
    
    
}