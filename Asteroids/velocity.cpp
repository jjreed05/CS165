#include "velocity.h"


// Put your velocity methods here

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

