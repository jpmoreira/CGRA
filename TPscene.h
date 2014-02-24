#ifndef TPSCENE_H
#define TPSCENE_H

#include "CGFscene.h"
#include "ExampleObject.h"
#include "myTable.h"


class myFloor;
class myChair;

class TPscene : public CGFscene
{
    ExampleObject obj;

    
    myChair * chair;
    myTable * table;
    double *anglesTables;
    double *anglesChairs;
    double *dxTables;
    double *dxChairs;
    double *dzTables;
    double *dzChairs;
    
    
    
    myFloor* floor;
    
public:
	void init();
	void display();
    
private:
    void drawSimpleScene();
    void drawTableAndChairWithOffset(double x,double z,int index);
};

#endif