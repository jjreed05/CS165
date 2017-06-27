/*************************************************************
* File: lander.h
* Author: Jason Reed
*
* Description: Contains the definition of the velocity class.
*
*************************************************************/

#ifndef VELOCITY_H
#define VELOCITY_H

class Velocity
{
	// The private variables
private:
	float dx;
	float dy;

	// The public variables
public:
	// Default constructor
	Velocity()
	{
		dx = 0;
		dy = 0;
	}
	// Non-Default constructor
	Velocity(float dx, float dy)
	{
		this->dx = dx;
		this->dy = dy;
	}
	
	// Getters
	float getDx() const;
	float getDy() const;

	// Setters
	void setDx(float dx);
	void setDy(float dy);
};

#endif /* VELOCITY_H */