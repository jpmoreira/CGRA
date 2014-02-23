#ifndef TPSCENE_H
#define TPSCENE_H

#include "CGFscene.h"
#include "ExampleObject.h"
#include "myTable.h"


class myFloor;

class TPscene : public CGFscene
{
    ExampleObject obj;
    myTable table;
    myFloor* floor;
    
public:
	void init();
	void display();
    
private:
    void drawSimpleScene();
};

#endif