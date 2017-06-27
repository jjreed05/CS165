/*************************************************************
* File: lander.h
* Author: Jason Reed
*
* Description: Contains the definition of the lander class.
*
*************************************************************/
#ifndef LANDER_H
#define LANDER_H

#include "point.h"
#include "velocity.h"
#include "uiDraw.h"
#include "uiInteract.h"


/******************************************
* Lander
* This class defines features of the lander
*******************************************/
class Lander
{
	// Private Variables
private:

	int fuel;

	bool alive;
	bool landed;
	bool thrust;
	bool bottom;
	bool left;
	bool right;

	float gravity;

	Point point;

	Velocity velocity;

public:

	// Default constructor
	Lander()
	{
		fuel = 500;
		alive = true;
		landed = false;
		thrust = false;
		// Generates a random point 
		point = Point(randomPoint(), 200);

		bottom = false;
		left = false;
		right = false;
	}

	// Class getters
	Point getPoint() const;
	Velocity getVelocity() const;

	// Booleans and numbers return types
	bool isAlive();
	bool isLanded();
	int getFuel() const;
	bool canThrust();
	float randomPoint();
	
	// Setters
	void setLanded(bool landed);
	void setAlive(bool alive);
	void setFuel(int fuel);

	// Applying functions
	void applyGravity(float gravity);
	void applyThrustLeft();
	void applyThrustRight();
	void applyThrustBottom();

	// Screen applications
	void advance();
	void draw();

};

#endif /* LANDER_H */
