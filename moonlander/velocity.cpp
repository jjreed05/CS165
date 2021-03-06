/***********************************************************************
* Implementation File:
*    LANDER : A class representing the velocity of the lander
* Author:
*    Jason Reed
* Summary:
*    The method functions for the velocity class.
************************************************************************/

#include "velocity.h"

/***************************************
* Velocity :: getDx()
* Gets the value of dx
***************************************/
float Velocity::getDx() const
{
	return dx;
}

/***************************************
* Velocity :: getDy()
* Gets the value of dy
***************************************/
float Velocity::getDy() const
{
	return dy;
}

/***************************************
* Velocity :: setDx()
* Sets the value of dx to the parameter
***************************************/
void Velocity::setDx(float dx)
{
	this->dx = dx;
}

/***************************************
* Velocity :: setDy()
* Sets the value of dy to the parameter
***************************************/
void Velocity::setDy(float dy)
{
	this->dy = dy;
}

