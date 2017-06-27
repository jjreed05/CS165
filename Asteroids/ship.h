#ifndef ship_h
#define ship_h

#define SHIP_SIZE 10

#define ROTATE_AMOUNT 6
#define THRUST_AMOUNT 0.5

#include "flyingObject.h"
#include <cmath>

// Put your Ship class here
class Ship : public FlyingObject
{
	bool thrust;

public:
	Ship()
	{
		thrust = false;
		isAlive1 = true;
	}
	
	// Setters
	void setThrust(bool thrust);
	void applyThrust();
	void setNegativeRotation();
	void setPositiveRotation();
	void kill();
	
	// Draws the ship and shield
	void draw();
};

#endif /* ship_h */
