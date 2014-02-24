#include "TPscene.h"
#include "CGFaxis.h"
#include "CGFapplication.h"

#include <math.h>

float pi = acos(-1.0);
float deg2rad=pi/180.0;

#include "CGFappearance.h"
#include "myFloor.h"
#include "myChair.h"


#define floor_thickness 0.1
#define floor_single_table_width 8
#define floor_single_table_depth 6

#define nrRows 4
#define nrCollumns 4
CGFappearance *mat1;

void TPscene::init() 
{
    
    /*
    
    chairs=vector<myChair *>();
    tables=vector<myTable *>();
    
    */
    chair=new myChair();
    table=new myTable();
    
    
    anglesTables=(double *)malloc(nrRows*nrCollumns*sizeof(double));
    anglesChairs=(double *)malloc(nrRows*nrCollumns*sizeof(double));

    dxChairs=(double *)malloc(nrRows*nrCollumns*sizeof(double));
    dxTables=(double *)malloc(nrRows*nrCollumns*sizeof(double));
    dzChairs=(double *)malloc(nrRows*nrCollumns*sizeof(double));
    dzTables=(double *)malloc(nrRows*nrCollumns*sizeof(double));

    
     
    for (int i=0; i<nrRows*nrCollumns; i++) {
        
        anglesTables[i]=(rand()%40)-20;
        anglesChairs[i]=(rand()%40)-20;
        dxChairs[i]=(rand()%10-5.0)/10.0;
        dxTables[i]=(rand()%10-5.0)/10.0;
        dzChairs[i]=(rand()%10-5.0)/10.0;
        dzTables[i]=(rand()%10-5.0)/10.0;
    }
    
	// Enables lighting computations
	glEnable(GL_LIGHTING);

	// Sets up some lighting parameters
	glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, CGFlight::background_ambient);  // Define ambient light
	
	// Declares and enables a light
	float light0_pos[4] = {4.0, 6.0, 5.0, 1.0};
	CGFlight* light0 = new CGFlight(GL_LIGHT0, light0_pos);
	light0->enable();

	// Defines a default normal
	glNormal3f(0,0,1);
    this->floor=new myFloor(nrCollumns*floor_single_table_width,nrRows*floor_single_table_depth,floor_thickness);

}

void TPscene::display() 
{

	// ---- BEGIN Background, camera and axis setup
	
	// Clear image and depth buffer everytime we update the scene
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	// Initialize Model-View matrix as identity (no transformation
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Apply transformations corresponding to the camera position relative to the origin
	CGFscene::activeCamera->applyView();

	// Draw axis
	axis.draw();
    
    glPushMatrix();
    
    glTranslated(4, 0, 3);
    
    for (int i=0; i<nrRows*nrCollumns; i++) {
        
        this->drawTableAndChairWithOffset((i%nrCollumns)*floor_single_table_width, (int)(i/nrCollumns)*floor_single_table_depth,i);
    }

    
    glPopMatrix();
    
    
    glPushMatrix();
    glTranslated(nrCollumns*floor_single_table_width/2.0, 0, nrRows*floor_single_table_depth/2.0);
    floor->draw();
    glPopMatrix();

    
 glutSwapBuffers();

}




void TPscene::drawTableAndChairWithOffset(double x,double z,int index){
    
    
    glPushMatrix();
    glTranslated(x, 0, z);
    
    glPushMatrix();
    glTranslated(dxTables[index], floor_thickness/2.0,dzTables[index]);
    glRotated(anglesTables[index], 0, 1, 0);
    table->draw();
    glPushMatrix();
    
    glTranslated(dxChairs[index], floor_thickness/2.0, -2.0+dzChairs[index]);
    glRotated(anglesChairs[index], 0, 1, 0);
    chair->draw();
    
    glPopMatrix();
    
    glPopMatrix();
    glPopMatrix();

}
