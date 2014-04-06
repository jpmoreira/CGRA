#ifndef LightingScene_H
#define LightingScene_H

#include "CGFscene.h"
#include "CGFappearance.h"
#include "myTable.h"
#include "Plane.h"
#include "myCylinder.h"
#include "myUnitCube.h"
#include "myLamp.h"

class LightingScene : public CGFscene
{
public:
	void init();
	void display();
    
	CGFlight* light0;
	CGFlight* light1;
	CGFlight* light2;
	myLamp* light3;
    
	myTable* table;
	Plane* wallLeft;
    Plane* wallFront;
	Plane* boardA;
	Plane* boardB;
	CGFappearance* materialA;
	CGFappearance* materialB;
	CGFappearance* material_floor;
	CGFappearance* material_wallFront;
    CGFappearance* material_wallLeft;
    
    
    myCylinder *cil;
    
    mySemiSphere *sphere;
    
    myUnitCube *cube;
	~LightingScene();
};

#endif