//
//  File.h
//  CGRA-1
//
//  Created by José Pedro Moreira on 07/04/14.
//  Copyright (c) 2014 José Pedro Moreira. All rights reserved.
//

#ifndef __CGRA_1__File__
#define __CGRA_1__File__

#include <iostream>
#include "myCylinder.h"

class myClock: public CGFobject {
    
    
    myCylinder * clockBody;
public:
    void draw();
    myClock();
};


#endif /* defined(__CGRA_1__File__) */
