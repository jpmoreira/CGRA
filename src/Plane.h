#pragma once

#include "CGFobject.h"
#include "CGFappearance.h"
class Plane
{
    double dx,dy;
    double repX,repY;
    bool clamp;
public:
	Plane();
	Plane(int numDivs);
    
    void enableClamp(double offsetY,double offsetX);
    void enableRepeat(double repeatsY,double repeatsX);
	~Plane(void);
	void draw();
    
    
private:
	int _numDivisions; // Number of triangles that constitute rows/columns
    
    double sTexCord(double x);
    double tTexCord(double z);
};



