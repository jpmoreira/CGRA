#ifndef LightingScene_H
#define LightingScene_H

#include "CGFscene.h"
#include "CGFappearance.h"
#include "myTable.h"
#include "Plane.h"
#include "myUnitCube.h"
#include "myLamp.h"
#include "myClock.h"

#define GL_CLAMP_TO_EDGE 0x812F

class LightingScene : public CGFscene
{
public:
	void init();
	void display();
	virtual void update(unsigned long milis);
    
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
    
    CGFappearance* cilinderApp;
    
    
    myCylinder *cil;
    myClock *clock;
	myClockHand *clock_h_ex;
    
    mySemiSphere *sphere;
    
    myUnitCube *cube;
	~LightingScene();
};

#endif