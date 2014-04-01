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
#include "CGFappearance.h"

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32)
#define PATH_TABLE_TEXTURE "C:\\Users\\Daniel\\Documents\\Visual Studio 2012\\Projects\\CGRA__DEV\\Debug\\table.png"
#else
#define PATH_TABLE_TEXTURE "table.png"
#endif
class myUnitCube: public CGFobject {
private:
	int coords[2][8];
	CGFappearance* tableAppearence;
public:
    void draw();
	void draw(CGFappearance *texture, int gl_mode);
};







#endif /* defined(__CGRA_1__myUnitCube__) */
