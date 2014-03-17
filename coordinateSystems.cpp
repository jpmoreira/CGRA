//
//  coordinateSystems.cpp
//  CGRA-1
//
//  Created by José Pedro Moreira on 17/03/14.
//  Copyright (c) 2014 José Pedro Moreira. All rights reserved.
//

#include "coordinateSystems.h"
#include <math.h>



CartesianPoint cylindricalToCartesian(CylindricalPoint * cilPt){
    
    CartesianPoint pt;
    pt.x=cilPt->r*cos(cilPt->rho*M_PI/180.);
    
    return pt;
}
CylindricalPoint cartesianToCylindrical(CartesianPoint *cartPt){
    
    CylindricalPoint pt;
    return pt;
    
    
}