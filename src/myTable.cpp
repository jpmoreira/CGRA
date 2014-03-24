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


myTable::myTable():CGFobject(),leg(myUnitCube()),lid(myUnitCube()){


}

void myTable::draw(){
    
    
    
    //Draw lid
    glPushMatrix();
    glTranslated(0.0, leg_height+lid_thickness/2.0, 0.0);
    glScaled(lid_width, lid_thickness, lid_depth);
    lid.draw();
    glPopMatrix();
    
    
    glPushMatrix();
    glTranslated(lid_width/2.0-leg_width/2.0, leg_height/2.0, lid_depth/2.0-leg_depth/2.0);//translate to the right front corner
    glScaled(leg_width, leg_height, leg_depth);
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