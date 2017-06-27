#ifndef bullet_h
#define bullet_h

#define BULLET_SPEED 5
#define BULLET_LIFE 40



// Put your Bullet class here
#include "point.h"
#include "velocity.h"
#include "flyingObject.h"
#include "ship.h"
#include "uiDraw.h"
#include <cmath>


class Bullet : public FlyingObject
{
public:
	int frame;
	// Non-Default Constructor
	Bullet(Point shipPoint)
	{
		// Set the initial conditions of the bullet
		point.setX(shipPoint.getX());
		point.setY(shipPoint.getY());
		velocity = velocity;
		isAlive1 = true;
		frame = 0;
	}
	// Kills the bullet 
	void kill();
	// Draws the dot
	void draw();
	// Gets the angle and initial point
	void fire(int angle);
	


};


#endif /* bullet_h */
