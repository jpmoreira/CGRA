#ifndef __CGRA_1__myClockHand__
#define __CGRA_1__myClockHand__

#include <CGFobject.h>
#include <CGFappearance.h>
#include <iostream>

#define RECT_HEIGHT 0.7
#define ARROW_HEIGHT 0.3

class myClockHand: public CGFobject {
		float angle;
public:
	void setAngle(float degrees);
	void draw();
	float getAngle();
	myClockHand();
	myClockHand(float angle);
};


#endif /* defined(__CGRA_1__File__) */
