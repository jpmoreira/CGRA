#pragma once

#include "CGFobject.h"
#include "CGFappearance.h"
class Plane
{
public:
	Plane(void);
	Plane(int);
	~Plane(void);
	void draw();
	void draw(CGFappearance *appearence);
private:
	int _numDivisions; // Number of triangles that constitute rows/columns
};



