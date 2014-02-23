#ifndef TPSCENE_H
#define TPSCENE_H

#include "CGFscene.h"
#include "ExampleObject.h"
#include "myUnitCube.h"

class TPscene : public CGFscene
{
    ExampleObject obj;
    myUnitCube cube;
    
public:
	void init();
	void display();
    
private:
    void drawSimpleScene();
};

#endif