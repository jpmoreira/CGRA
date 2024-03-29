#ifndef LightingScene_H
#define LightingScene_H

#include "CGFscene.h"
#include "CGFappearance.h"
#include "myTable.h"
#include "myUnitCube.h"
#include "myLamp.h"
#include "myClock.h"
#include "myRobot.h"
#include "myHoleWall.h"


#if defined(WIN32) || defined(_WIN32) || defined(__WIN32)
#define PATH_WALL_TEXTURE "C:\\Users\\Daniel\\Documents\\Visual Studio 2012\\Projects\\CGRA__DEV\\Debug\\wall.png"
#define PATH_FLOOR_TEXTURE "C:\\Users\\Daniel\\Documents\\Visual Studio 2012\\Projects\\CGRA__DEV\\Debug\\floor.png"
#define PATH_SLIDES_TEXTURE "C:\\Users\\Daniel\\Documents\\Visual Studio 2012\\Projects\\CGRA__DEV\\Debug\\slides.png"
#define PATH_BOARD_TEXTURE "C:\\Users\\Daniel\\Documents\\Visual Studio 2012\\Projects\\CGRA__DEV\\Debug\\board.png"
#define PATH_WINDOW_TEXTURE "C:\\Users\\Daniel\\Documents\\Visual Studio 2012\\Projects\\CGRA__DEV\\Debug\\window.png"
#define PATH_LANDSCAPE_TEXTURE "C:\\Users\\Daniel\\Documents\\Visual Studio 2012\\Projects\\CGRA__DEV\\Debug\\paisagem.jpeg"
#else
#define PATH_WALL_TEXTURE "wall.png"
#define PATH_FLOOR_TEXTURE "floor.png"
#define PATH_SLIDES_TEXTURE "slides.png"
#define PATH_BOARD_TEXTURE "board.png"
#define PATH_WINDOW_TEXTURE "window.png"

#define PATH_LANDSCAPE_TEXTURE "paisagem.jpeg"

#endif


#define GL_CLAMP_TO_EDGE 0x812F
#define CLOCK_UPDATE 1
#define LIGHT0 10
#define LIGHT1 11
#define LIGHT2 12
#define LIGHT3 13
#define ROBOT_WIREFRAME 20
#define ROBOT_TEXTURE 30

class LightingScene : public CGFscene
{
public:
	void init();
	void display();
	void changeLight(int light);
	void toggleSomething();
	virtual void update(unsigned long milis);

	CGFlight* light0;
	CGFlight* light1;
	CGFlight* light2;
	myRobot * robot;


	CGFlight* light3;

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
    
    myHoleWall *holeWall;

	GLUI_Panel* varPanel;
	int sceneVar;
	int enable_light0;
	int enable_light1;
	int enable_light2;
	int enable_light3;
	int activate_clock;
	int robot_wiframe;

	myCylinder *cil;
	myClock *clock;
	myClockHand *clock_h_ex;

	mySemiSphere *sphere;

	myUnitCube *cube;
	~LightingScene();


};

#endif