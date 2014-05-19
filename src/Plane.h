#pragma once

#include "CGFobject.h"
class Plane
{
    double dx,dy;
    double repX,repY;
    double offsetX,offsetY;
    bool clamp;

public:
	Plane();
	Plane(int numDivs);
    
    void enableCentered(double d_y,double d_x);
    void enableRepeat(double repeatsY,double repeatsX);
    void addOffset(double offY,double offX);
	~Plane(void);
	void draw();
    
    
private:
	int _numDivisions; // Number of triangles that constitute rows/columns
    
    double sTexCord(double x);
    double tTexCord(double z);
};



