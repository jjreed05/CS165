#ifndef rocks_h
#define rocks_h

#define BIG_ROCK_SIZE 16
#define MEDIUM_ROCK_SIZE 8
#define SMALL_ROCK_SIZE 4

#define BIG_ROCK_SPIN 2
#define MEDIUM_ROCK_SPIN 5
#define SMALL_ROCK_SPIN 10

#include "flyingObject.h"

// Define the following classes here:
//   Rock
//   BigRock
//   MediumRock
//   SmallRock

/*********************************************
* Class: Rock
* Description: The base class for the rocks
*********************************************/
class Rock : public FlyingObject
{
protected:
	int radius;
	int rotation;
public:
	void advance();
	void kill();
	int virtual hit();
	void virtual draw();
};

/*********************************************
* Class: BigRock
* Description: Class for the large asteroids
*********************************************/
class BigRock : public Rock
{
public:
	BigRock(Point & startPosition, Velocity & startVelocity);

	int hit();
	void draw();
};

/*********************************************
* Class: MediumRock
* Description: Class for the medium asteroids
*********************************************/
class MediumRock : public Rock
{
public:
	MediumRock(Point & startPosition, Velocity & startVelocity);
	int hit();
	void draw();
};

/*********************************************
* Class: SmallRock
* Description: Class for the small asteroids
*********************************************/
class SmallRock : public Rock
{
public:
	SmallRock(Point & startPosition, Velocity & startVelocity);
	int hit();
	void draw();
};


#endif /* rocks_h */
