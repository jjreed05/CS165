/*************************************************************
* File: flyingObject.cpp
* Author: Jason Reed
*
* Description: Contains the implementations of the
*  method bodies for the FlyingObject class.
*
*************************************************************/
#include "flyingObject.h"

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
