//
//  myChair.cpp
//  CGRA-1
//
//  Created by José Pedro Moreira on 23/02/14.
//  Copyright (c) 2014 José Pedro Moreira. All rights reserved.
//

#include "myChair.h"


#define leg_height 1.9
#define leg_depth 0.2
#define leg_width 0.2

#define seat_width 1.4
#define seat_depth 1.4
#define seat_thickness 0.1

#define back_width 1.4
#define back_height 1.8
#define back_depth 0.1

#define back_vertical_lath_width 0.3


#define nrVerticalLaths 3

#define back_horisontal_lath_height 0.1




void myChair::draw(){
    
    
    
    
    glPushMatrix();
    glTranslated(0, leg_height+seat_thickness/2.0, 0);
    glScaled(seat_width, seat_thickness, seat_depth);
    seat.draw();
    glPopMatrix();
    
    
    //draw front right leg
    glPushMatrix();
    glTranslated(seat_width/2.0-leg_width/2.0, leg_height/2.0, seat_depth/2.0-leg_depth/2.0);
    glScaled(leg_width, leg_height, leg_depth);
    leg.draw();
    glPopMatrix();
    
    //draw back right leg
    glPushMatrix();
    glTranslated(seat_width/2.0-leg_width/2.0, leg_height/2.0, -(seat_depth/2.0-leg_depth/2.0));
    glScaled(leg_width, leg_height, leg_depth);
    leg.draw();
    glPopMatrix();
    
    //draw back left leg
    glPushMatrix();
    glTranslated(-(seat_width/2.0-leg_width/2.0), leg_height/2.0, -(seat_depth/2.0-leg_depth/2.0));
    glScaled(leg_width, leg_height, leg_depth);
    leg.draw();
    glPopMatrix();
    
    //draw front left leg
    glPushMatrix();
    glTranslated(-(seat_width/2.0-leg_width/2.0), leg_height/2.0, seat_depth/2.0-leg_depth/2.0);
    glScaled(leg_width, leg_height, leg_depth);
    leg.draw();
    glPopMatrix();
    
    
    //draw vert. lath on the right
    glPushMatrix();
    glTranslated(seat_width/2.0-back_vertical_lath_width/2.0,leg_height+seat_thickness+(back_height-back_horisontal_lath_height)/2.0,-seat_depth/2.0+back_depth/2.0);
    glScaled(back_vertical_lath_width, back_height-back_horisontal_lath_height, back_depth);
    leg.draw();
    glPopMatrix();
    
    
    //draw vert. lath on the left
    glPushMatrix();
    glTranslated(-(seat_width/2.0-back_vertical_lath_width/2.0),leg_height+seat_thickness+(back_height-back_horisontal_lath_height)/2.0,-seat_depth/2.0+back_depth/2.0);
    glScaled(back_vertical_lath_width, back_height-back_horisontal_lath_height, back_depth);
    leg.draw();
    glPopMatrix();
    
    //draw vert. lath on center
    glPushMatrix();
    glTranslated(0,leg_height+seat_thickness+(back_height-back_horisontal_lath_height)/2.0,-seat_depth/2.0+back_depth/2.0);
    glScaled(back_vertical_lath_width, back_height-back_horisontal_lath_height, back_depth);
    leg.draw();
    glPopMatrix();
    
    //draw horizontal. lath
    glPushMatrix();
    glTranslated(0,leg_height+seat_thickness+back_height-back_horisontal_lath_height/2.0,-seat_depth/2.0+back_depth/2.0);
    glScaled(back_width, back_horisontal_lath_height, back_depth);
    leg.draw();
    glPopMatrix();
    

}
