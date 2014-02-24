//
//  myChair.h
//  CGRA-1
//
//  Created by José Pedro Moreira on 23/02/14.
//  Copyright (c) 2014 José Pedro Moreira. All rights reserved.
//

#ifndef __CGRA_1__myChair__
#define __CGRA_1__myChair__

#include "myUnitCube.h"

class myChair: public CGFobject {
    myUnitCube leg;
    myUnitCube seat;
public:
    void draw();
};

#endif /* defined(__CGRA_1__myChair__) */
