//
//  myHoleWall.h
//  CGRA-1
//
//  Created by José Pedro Moreira on 12/05/14.
//  Copyright (c) 2014 José Pedro Moreira. All rights reserved.
//

#ifndef __CGRA_1__myHoleWall__
#define __CGRA_1__myHoleWall__

#include "Plane.h"
class myHoleWall: public CGFobject {
    
    
    Plane left,right,top,down;
    
public:
    void draw();
    myHoleWall(int n);
    

};


#endif /* defined(__CGRA_1__myHoleWall__) */
