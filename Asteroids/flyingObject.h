#ifndef flyingObject_h
#define flyingObject_h

#include "point.h"
#include "velocity.h"
#include "uiDraw.h"


// Put your FlyingObject class here
class FlyingObject
{
	// Accessible through all inherited classes
protected:
	Point point;
	Velocity velocity;
	bool isAlive1;
	int angle;

public:
	// Default Constructor
	FlyingObject()
	{
		angle = 0;
		isAlive1 = true;
	}
	// Getters
	Point getPoint();
	Velocity getVelocity();
	bool isAlive();
	int getAngle();
	// Setters
	void setPoint(Point point);
	void setVelocity(Velocity velocity);

	virtual void advance();
};




#endif /* flyingObject_h */
