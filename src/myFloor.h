//
//  myFloor.h
//  CGRA-1
//
//  Created by José Pedro Moreira on 23/02/14.
//  Copyright (c) 2014 José Pedro Moreira. All rights reserved.
//

#ifndef __CGRA_1__myFloor__
#define __CGRA_1__myFloor__

#include "myUnitCube.h"

class myFloor: public myUnitCube {
    double width,depth,thickness;
    
public:
    void draw();
    myFloor(double width,double depth, double thickness);
};

#endif /* defined(__CGRA_1__myFloor__) */
