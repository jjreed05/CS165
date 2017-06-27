#include "ship.h"

// Put your ship methods here

/*********************************************
* Function: setThrust
* Description: Sets the thrust.
*********************************************/
void Ship::setThrust(bool thrust)
{
	this->thrust = thrust;
}

/*********************************************
* Function: applyThrust
* Description: Applies the thrust to the bottom
* of the ship.
*********************************************/
void Ship::applyThrust()
{
	float dy = 0.5 * (cos(M_PI / 180.0 * angle));
	float dx = 0.5 * (-sin(M_PI / 180.0 * angle));
	velocity.setDx(velocity.getDx() + dx);
	velocity.setDy(velocity.getDy() + dy);
}

/*********************************************
* Function: setNegativeRotation
* Description: Sets the angle to the left
*********************************************/
void Ship::setNegativeRotation()
{
	angle -= ROTATE_AMOUNT;
}

/*********************************************
* Function: setPositiveRotation
* Description: Sets the angle to the right
*********************************************/
void Ship::setPositiveRotation()
{
	angle += ROTATE_AMOUNT;
}

/*********************************************
* Function: kill
* Description: The ship is not alive
*********************************************/
void Ship::kill()
{
	isAlive1 = false;
}

/*********************************************
* Function: draw
* Description: Draws the ship depending on the 
* angle and point.
*********************************************/
void Ship::draw()
{
	drawShip(point, angle, thrust);
}


