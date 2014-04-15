#include "LightingScene.h"
#include "CGFaxis.h"
#include "CGFapplication.h"
#include "myTable.h"
#include "Plane.h"
#include "coordinateSystems.h"
#include <math.h>

float pi = acos(-1.0);
float deg2rad=pi/180.0;

#define BOARD_HEIGHT 6.0
#define BOARD_WIDTH 6.4

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32)
#define PATH_WALL_TEXTURE "C:\\Users\\Daniel\\Documents\\Visual Studio 2012\\Projects\\CGRA__DEV\\Debug\\wall.png"
#define PATH_FLOOR_TEXTURE "C:\\Users\\Daniel\\Documents\\Visual Studio 2012\\Projects\\CGRA__DEV\\Debug\\floor.png"
#define PATH_SLIDES_TEXTURE "C:\\Users\\Daniel\\Documents\\Visual Studio 2012\\Projects\\CGRA__DEV\\Debug\\slides.png"
#define PATH_BOARD_TEXTURE "C:\\Users\\Daniel\\Documents\\Visual Studio 2012\\Projects\\CGRA__DEV\\Debug\\board.png"
#define PATH_WINDOW_TEXTURE "C:\\Users\\Daniel\\Documents\\Visual Studio 2012\\Projects\\CGRA__DEV\\Debug\\window.png"
#else
#define PATH_WALL_TEXTURE "wall.png"
#define PATH_FLOOR_TEXTURE "floor.png"
#define PATH_SLIDES_TEXTURE "slides.png"
#define PATH_BOARD_TEXTURE "board.png"
#define PATH_WINDOW_TEXTURE "window.png"

#endif

// Positions for two lights
float light0_pos[4] = {4, 6.0, 1.0, 1.0};
float light1_pos[4] = {10.5, 6.0, 1.0, 1.0};

float light2_pos[4] = {-10.5, 6.0, 5.0, 1.0};
float light3_pos[4] = {4, 6.0, 5.0, 1.0};

// Global ambient light (do not confuse with ambient component of individual lights)
float globalAmbientLight[4]= {0,0,0,1};

// number of divisions
#define BOARD_A_DIVISIONS 30
#define BOARD_B_DIVISIONS 100

// Coefficients for material A
float ambA[3] = {0.2, 0.2, 0.2};
float difA[3] = {0.6, 0.6, 0.6};
float specA[3] = {0, 0.8, 0.8};
float shininessA = 120.f;

// Coefficients for material B
float ambB[3] = {0.2, 0.2, 0.2};
float difB[3] = {0.6, 0.6, 0.6};
float specB[3] = {0.8, 0.8, 0.8};
float shininessB = 40.f;

// Coefficients for material floor
float amb_wall[3] = {0.135, 0.223, 0.1575};
float dif_wall[3] = {0.54, 0.89, 0.63};
float spec_wall[3] = {0.316, 0.316, 0.316};
float shininess_wall = 0.1;

// Coefficients for material wall
float amb_floor[3] = {0.02, 0.02, 0.02};
float dif_floor[3] = {0.65, 0.59, 0.48};
float spec_floor[3] = {0.26, 0.236, 0.192};
float shininess_floor = 0.15;


float ambientNull[4]={0,0,0,1};
float yellow[4]={1,1,0,1};



void LightingScene::update(unsigned long milisec){
	this->clock->update(milisec);
}

void LightingScene::init()
{
    
    glShadeModel(GL_SMOOTH);
	// Enables lighting computations
	glEnable(GL_LIGHTING);
    
	// Sets up some lighting parameters
	// Computes lighting only using the front face normals and materials
	glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);
	
	// Define ambient light (do not confuse with ambient component of individual lights)
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalAmbientLight);
	
    
	// Declares and enables two lights, with null ambient component
    
	light0 = new CGFlight(GL_LIGHT0, light0_pos);
	light0->setAmbient(ambientNull);
	light0->setSpecular(yellow);
    
	light0->enable();
	//light0->disable();
    
	light1 = new CGFlight(GL_LIGHT1, light1_pos);
	light1->setAmbient(ambientNull);
	
	light1->enable();
	//light1->disable();
    
	light2 = new CGFlight(GL_LIGHT2, light2_pos);
	light2->setAmbient(ambientNull);
	
	light2->enable();
	//light2->disable();
    
	light2->setKc(1);
	light2->setKl(0);
	light2->setKq(0);
    
    
	light3 = new myLamp(10,10,GL_LIGHT3, light3_pos);
	light3->setAmbient(ambientNull);
	//light3->setSpecular(yellow);
    
	light3->enable();
	//light3->disable();
    
	light3->setKc(0);
	light3->setKl(0);
	light3->setKq(0.2);
	
	// Uncomment below to enable normalization of lighting normal vectors
	glEnable (GL_NORMALIZE);
    
	//Declares scene elements
	table = new myTable();
	wallLeft = new Plane();
    wallLeft->enableClamp(0.25,0.35);
    wallFront= new Plane();
    wallFront->enableRepeat(15, 15);
	boardA = new Plane(BOARD_A_DIVISIONS);
	boardB = new Plane(BOARD_B_DIVISIONS);
	
	//Declares materials
	materialA = new CGFappearance(ambA,difA,specA,shininessA);
	materialB = new CGFappearance(ambB,difB,specB,shininessB);
    materialB->setTexture(PATH_BOARD_TEXTURE);
    materialA->setTexture(PATH_SLIDES_TEXTURE);
    boardA->enableClamp(0, 0);
    boardB->enableClamp(0.15, 0);
    materialA->setTextureWrap(GL_CLAMP_TO_EDGE, GL_CLAMP_TO_EDGE);
    materialB->setTextureWrap(GL_CLAMP_TO_EDGE, GL_CLAMP_TO_EDGE);
    
	material_wallFront= new CGFappearance(amb_wall, dif_wall, spec_wall, shininess_wall);
    material_wallLeft= new CGFappearance(amb_wall, dif_wall, spec_wall, shininess_wall);
	material_floor= new CGFappearance(amb_floor, dif_floor, spec_floor, shininess_floor);
    material_floor->setTexture(PATH_FLOOR_TEXTURE);
    material_wallLeft->setTexture(PATH_WINDOW_TEXTURE);
    material_wallLeft->setTextureWrap(GL_CLAMP_TO_EDGE, GL_CLAMP_TO_EDGE);

    
    
    cilinderApp=new CGFappearance(amb_wall,dif_wall,spec_wall,shininess_wall);
    cilinderApp->setTexture(PATH_WALL_TEXTURE);
    
    cil=new myCylinder(2,12);
    cil->setTextures(cilinderApp, cilinderApp);
    cil->enableRepeat(4, 12);
    sphere=new mySemiSphere(10,10);
    cube=new myUnitCube();
    clock=new myClock();
	

	setUpdatePeriod(100);    
}

void LightingScene::display()
{
    
	// ---- BEGIN Background, camera and axis setup
	
	// Clear image and depth buffer everytime we update the scene
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    
	// Initialize Model-View matrix as identity (no transformation
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
    
	// Apply transformations corresponding to the camera position relative to the origin
	CGFscene::activeCamera->applyView();
    
	light0->draw();
	light1->draw();
	light2->draw();
	light3->draw();
	
	// Draw axis
	axis.draw();
   
	// ---- END Background, camera and axis setup
    
	// ---- BEGIN Primitive drawing section
    
     //First Table
     glPushMatrix();
     glTranslated(5,0,8);
     table->draw();
     glPopMatrix();
     
     //Second Table
     glPushMatrix();
     glTranslated(12,0,8);
     table->draw();
     glPopMatrix();
     
     //Floor
     glPushMatrix();
     glTranslated(7.5,0,7.5);
     glScaled(15,0.2,15);
     material_floor->apply();
     wallFront->draw();
     glPopMatrix();
     
     //LeftWall
     glPushMatrix();
     glTranslated(0,4,7.5);
    glRotated(90.0, 1, 0, 0);
     glRotated(-90.0,0,0,1);
     glScaled(15,0.2,8);
     material_wallLeft->apply();
     wallLeft->draw();
     glPopMatrix();
     
     //PlaneWall
     glPushMatrix();
     glTranslated(7.5,4,0);
     glRotated(90.0,1,0,0);
     glScaled(15,0.2,8);
    material_wallFront->apply();
     wallFront->draw();
     glPopMatrix();
     
     
     // Board A
     glPushMatrix();
     glTranslated(4,4,0.2);
     glScaled(BOARD_WIDTH,BOARD_HEIGHT,1);
     glRotated(90.0,1,0,0);
     materialA->apply();
     boardA->draw();
     glPopMatrix();
     
     //PlaneB
     glPushMatrix();
     glTranslated(10.5,4,0.2);
     glScaled(BOARD_WIDTH,BOARD_HEIGHT,1);
     glRotated(90.0,1,0,0);
     materialB->apply();
     boardB->draw();
     glPopMatrix();
     
    glPushMatrix();
    glTranslated(14, 4, 14);
    glScaled(1.5, 8, 1.5);
    cil->draw(1);
    
    glPopMatrix();
    
    glTranslated(0.5, 5, 3);
	glRotated(90, 0, 1, 0);
    clock->draw();
    //sphere->draw();
    
    //cube->draw();
	// ---- END Primitive drawing section
	
    
	// We have been drawing in a memory area that is not visible - the back buffer,
	// while the graphics card is showing the contents of another buffer - the front buffer
	// glutSwapBuffers() will swap pointers so that the back buffer becomes the front buffer and vice-versa
	glutSwapBuffers();
    

}

LightingScene::~LightingScene() 
{
	delete(light0);
	delete(light1);

	delete(table);
	delete(wallLeft);
    delete(wallFront);
	delete(boardA);
	delete(boardB);
	delete(materialA);
	delete(materialB);
}