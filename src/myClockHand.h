#ifndef __CGRA_1__myClockHand__
#define __CGRA_1__myClockHand__

#include <CGFobject.h>
#include <CGFappearance.h>
#include <iostream>

#define SQUARE_HEIGHT_PERCENT 0.7
#define TRIANGLE_HEIGHT_PERCENT 0.3
#define SQUARE_WIDTH_PERCENT 0.7
class myClockHand: public CGFobject {
		float angle;
		float square_height, height;
		float half_width, square_half_width;
public:
	void setAngle(float degrees);
	void draw();
	float getAngle();
	myClockHand();
	myClockHand(float height, float width);
};


#endif /* defined(__CGRA_1__File__) */
