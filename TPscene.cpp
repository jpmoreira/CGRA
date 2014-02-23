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
    
    
    chairs=vector<myChair *>();
    tables=vector<myTable *>();
    
    
    for (int i=0; i<nrRows*nrCollumns; i++) {
        chairs.push_back(new myChair());
        tables.push_back(new myTable());
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
    this->obj=ExampleObject();
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
        
        this->drawTableAndChairWithOffset((i%nrCollumns)*floor_single_table_width, (int)(i/nrCollumns)*floor_single_table_depth,tables[i],chairs[i]);
    }

    
    glPopMatrix();
    
    
    glPushMatrix();
    glTranslated(nrCollumns*floor_single_table_width/2.0, 0, nrRows*floor_single_table_depth/2.0);
    floor->draw();
    glPopMatrix();

    
 glutSwapBuffers();

}


/**
 
 Function to draw simple scene requires in ex1,2,3,4 tp1
 
 */
void TPscene::drawSimpleScene(){
    
    glPushMatrix();
    glTranslated(0, 5, 0);
    
    obj.draw();
    
    glPopMatrix();
    
    // ---- BEGIN New Transform section
    
    
    //glRotated(30.0, 0, 1, 0);
    glScaled(2, 2, 1);
    glTranslated(5, 0, 2);
    
    
    // ---- END New Transform secction
    
    
	// ---- BEGIN Primitive drawing section
    
    // NOTE: the visible face of the polygon is determined by the order of the vertices
    
    obj.draw();


}


void TPscene::drawTableAndChairWithOffset(double x,double z,myTable *table,myChair *chair){
    
    
    glPushMatrix();
    glTranslated(x, 0, z);
    
    glPushMatrix();
    glTranslated(0.0,floor_thickness/2.0, 0.0);
    table->draw();
    glPushMatrix();
    
    glTranslated(0, 0, -2.0);
    chair->draw();
    
    glPopMatrix();
    
    glPopMatrix();
    glPopMatrix();

}
