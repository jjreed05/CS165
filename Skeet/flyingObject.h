/*************************************************************
 * File: flyingObject.h
 * Author: Jason Reed
 *
 * Description: The base class for the Bird and Bullet classes
 *
 *************************************************************/
 
 #ifndef FLYINGOBJECT_H
#define FLYINGOBJECT_H

#include "point.h"
#include "velocity.h"
#include "uiDraw.h"

class FlyingObject 
{
// Accessible through all inherited classes
protected:
	Point point;
	Velocity velocity;
	bool isAlive1;

public:
	// Bird and Bullet rely on these functions
	Point getPoint();
	Velocity getVelocity();
	bool isAlive();

	void setPoint(Point point);
	void setVelocity(Velocity velocity);
};


#endif 