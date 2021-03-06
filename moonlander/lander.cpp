/***********************************************************************
* Implementation File:
*    LANDER : A class representing the lander
* Author:
*    Jason Reed
* Summary:
*    The method functions for the lander function
************************************************************************/

#include "lander.h"
#include "point.h"
#include "game.h"

/***************************************
* Lander :: getPoint()
* Returns the value of the Point class
***************************************/
Point Lander::getPoint() const
{
	return point;
}

/****************************************
* Lander :: getVelocity()
* Returns the value of the Velocity class
****************************************/
Velocity Lander::getVelocity() const
{
	return velocity;
}

/****************************************
* Lander :: isAlive()
* Returns true or false if the lander 
* is alive.
****************************************/
bool Lander::isAlive()
{
	if (alive == true)
		return true;
	else
		return false;
}

/***************************************
* Lander :: isLanded()
* Returns true or false if the lander
* has landed
***************************************/
bool Lander::isLanded()
{
	if (landed == true)
		return true;
	else
		return false;
}

/***************************************
* Lander :: getFuel()
* Returns the value fuel integer
***************************************/
int Lander::getFuel() const
{
	return fuel;
}

/***************************************
* Lander :: canThrust()
* If their is fuel, then it returns true
***************************************/
bool Lander::canThrust()
{
	if (fuel == 0)
		return false;
	else
		return true;
}

/***************************************
* Lander :: randomPoint()
* Generates a random number; used for
* generating the starting point of the
* lander
***************************************/
float Lander::randomPoint()
{
	float randomPoint = random(-200, 200);
	return randomPoint;
}

/***************************************
* Lander :: setLanded()
* Sets the landed boolean variable to
* the parameter
***************************************/
void Lander::setLanded(bool landed)
{
	this->landed = landed;

}

/***************************************
* Lander :: setAlive()
* Sets the alive boolean variable to the
* parameter
***************************************/
void Lander::setAlive(bool alive)
{
	this->alive = alive;
}

/***************************************
* Lander :: setFuel()
* Sets the fuel integer to the parameter
***************************************/
void Lander::setFuel(int fuel)
{
	this->fuel = fuel;
}

/***************************************
* Lander :: applyGravity()
* Applies gravity to the value of Dy.
***************************************/
void Lander::applyGravity(float gravity)
{
	velocity.setDy(velocity.getDy() - gravity);

}

/***************************************
* Lander :: applyThrustLeft()
* Moves the lander to the right.
***************************************/
void Lander::applyThrustLeft()
{
	// Will not move if their is no fuel
	if (fuel > 0)
	{
		// Moves the lander to the right
		velocity.setDx(velocity.getDx() + 0.1);
		// Consumes fuel while thrusting
		fuel = fuel - 1;
	}
}

/***************************************
* Lander :: applyThrustRight()
* Moves the lander to the left.
***************************************/
void Lander::applyThrustRight()
{
	// Will not move if their is no fuel
	if (fuel > 0)
	{
		// Moves the lander to the left
		velocity.setDx(velocity.getDx() - 0.1);
		// Consumes fuel while thrusting
		fuel = fuel - 1;
	}
}

/***************************************
* Lander :: applyThrustBottom()
* Moves the lander to the right.
***************************************/
void Lander::applyThrustBottom()
{
	// Will not move if their is no fuel
	if (fuel > 0)
	{
		// Moves the lander up
		velocity.setDy(velocity.getDy() + 0.3);
		// Consumes fuel while thrusting
		fuel = fuel - 3;
	}
}

/***************************************
* Lander :: advance()
* Sets the points of the lander
***************************************/
void Lander::advance()
{
	if (!landed && alive)
	{
		// Sets the X and Y coordinates if it didn't land
		point.setY(point.getY() + velocity.getDy());
		point.setX(point.getX() + velocity.getDx());

	}
	
}

/***************************************
* Lander :: draw()
* Draws the needed objects of the screen
***************************************/
void Lander::draw()
{
	// Draws the lander, flames, and fuel units
	if (isAlive())
		drawLander(point);

	else
	{
		// If the lander crashes then this turns the
		// lander into a burning object
		drawSmallAsteroid(point, 30);
		drawLanderFlames(point, true, true, true);
			
	}


}