//
//  Table.h
//  CGRA
//

#ifndef __CGRA_1__Table__
#define __CGRA_1__Table__

#include <iostream>
#include "CGFappearance.h"
#include "myUnitCube.h"
class myTable: public CGFobject{
    
    myUnitCube leg;
    myUnitCube lid;
	CGFappearance* material_tLid;
	CGFappearance* material_tLeg;
	CGFappearance* tableAppearence;
    
    
public:
    void draw();
    myTable();
    
};

#endif /* defined(__CGRA_1__Table__) */
