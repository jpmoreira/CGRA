//
//  myRobot.h
//  CGRA-1
//
//  Created by José Pedro Moreira on 28/04/14.
//  Copyright (c) 2014 José Pedro Moreira. All rights reserved.
//

#ifndef __CGRA_1__myRobot__
#define __CGRA_1__myRobot__

#define _USE_MATH_DEFINES

#include <iostream>
#include "CGFobject.h"

class CGFappearance;


class myRobot: public CGFobject {
    
    int stacks;
	int appearence;
    double *xx;
    double *zz;
    double *yy;
    double *xx_normal;
    double *zz_normal;
    CGFappearance *robotAppearance;
	CGFappearance *robotAppearance2;
	CGFappearance *robotAppearance3;

    bool wireFrameMode;
    
    
	double translate_coords[3];
	double xz_rotate_degree;
	double start_point[3];
    void populateArrays();
    void drawFace(int faceNr);
public:
    void draw();
    myRobot(int stacksNr);
	void moveForward();
	void moveBackward();
	void rotateLeft();
	void rotateRight();
    void switchTexture(int nr);
    static std::string nameForTexture(int nr);
    void setWireframeMode(bool enabled);
	void changeWireframe();
};

#endif /* defined(__CGRA_1__myRobot__) */


