
/*************************************************************
* File: flyingObject.cpp
* Author: Jason Reed
*
* Description: Contains the implementations of the
*  method bodies for the FlyingObject class.
*
*************************************************************/
#include "flyingObject.h"


// Put your FlyingObject method bodies here
/*********************************************
* Function: getPoint
* Description: Returns the value of point
*********************************************/
Point FlyingObject::getPoint()
{
	return point;
}

/*********************************************
* Function: getVelocity
* Description: Returns the value of velocity
*********************************************/
Velocity FlyingObject::getVelocity()
{
	return velocity;
}

/*********************************************
* Function: isAlive
* Description: Returns the value of isAlive1
*********************************************/
bool FlyingObject::isAlive()
{
	return isAlive1;
}

/*********************************************
* Function: getAngle
* Description: Returns the angle
*********************************************/
int FlyingObject::getAngle()
{
	return angle;
}

/*********************************************
* Function: setPoint
* Description: Sets the point to the parameter.
*********************************************/
void FlyingObject::setPoint(Point point)
{
	this->point = point;
}

/*********************************************
* Function: setVelocity
* Description: Sets velocity equal to the
* parameter
*********************************************/
void FlyingObject::setVelocity(Velocity velocity)
{
	this->velocity = velocity;
}

/*********************************************
* Function: advance
* Description: Wraps the screen and advances
* the objects.
*********************************************/
void FlyingObject::advance()
{
	// Wraps the screen from right to left
	if (point.getX() < -200)
	{
		point.setY(point.getY() + velocity.getDy());
		point.setX(199);
	}
	// Wraps the screen from left to right
	else if (point.getX() > 200)
	{
		point.setY(point.getY() + velocity.getDy());
		point.setX(-199);
	}
	// Wraps the screen from bottom to top
	else if (point.getY() < -200)
	{
		point.setY(199);
		point.setX(point.getX() + velocity.getDx());
	}
	// Wraps the screen from top to bottom
	else if (point.getY() > 200)
	{
		point.setY(-199);
		point.setX(point.getX() + velocity.getDx());
	}
	else
	{
		point.setY(point.getY() + velocity.getDy());
		point.setX(point.getX() + velocity.getDx());
	}
}
