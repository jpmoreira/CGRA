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

    
    vector<myChair *> chairs;
    vector<myTable *> tables;
    myFloor* floor;
    
public:
	void init();
	void display();
    
private:
    void drawSimpleScene();
    void drawTableAndChairWithOffset(double x,double z,myTable *table,myChair *chair);
};

#endif