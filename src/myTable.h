//
//  Table.h
//  CGRA-1
//
//  Created by José Pedro Moreira on 23/02/14.
//  Copyright (c) 2014 José Pedro Moreira. All rights reserved.
//

#ifndef __CGRA_1__Table__
#define __CGRA_1__Table__

#include <iostream>
#include "myUnitCube.h"
class myTable: public CGFobject{

    myUnitCube leg;
    myUnitCube lid;

    
public:
    void draw();
    myTable();

};

#endif /* defined(__CGRA_1__Table__) */
