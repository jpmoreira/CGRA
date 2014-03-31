//
//  myUnitCube.h
//  CGRA-1
//
//  Created by José Pedro Moreira on 23/02/14.
//  Copyright (c) 2014 José Pedro Moreira. All rights reserved.
//

#ifndef __CGRA_1__myUnitCube__
#define __CGRA_1__myUnitCube__

#include <CGFobject.h>
class myUnitCube: public CGFobject {
private:
	int coords[2][8];
public:
    void draw();
	void setTextureCoords(int[2][8]);
};







#endif /* defined(__CGRA_1__myUnitCube__) */
