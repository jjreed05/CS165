/*************************************************************
* File: bullet.h
* Author: Jason Reed
*
* Description: Contains the definition of the bullet class.
*
*************************************************************/

#ifndef BULLET_H
#define BULLET_H
#define BULLET_SPEED 10.0

#include "point.h"
#include "velocity.h"
#include "flyingObject.h"
#include "uiDraw.h"
#include <cmath>


class Bullet : public FlyingObject
{
	float angle;
public:
	// Default Constructor
	Bullet()
	{
		// Set the initial conditions of the bullet
		point.setX(point.getX() + 199);
		point.setY(point.getY() - 199);
		velocity = velocity;
		isAlive1 = true;
	}
	// Kills the bullet 
	void kill();
	// Advances the dot on the screen
	void advance();
	// Draws the dot
	void draw();
	// Gets the angle and initial point
	void fire(Point point, float angle);


};

#endif