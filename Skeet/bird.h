/*************************************************************
* File: bird.h
* Author: Jason Reed
*
* Description: Contains the definition of the bird class 
* along with three dervied classes (Standard, ToughBird, 
* SacredBird).
*
*************************************************************/

#ifndef BIRD_H
#define BIRD_H


#include "point.h"
#include "velocity.h"
#include "flyingObject.h"
#include "uiDraw.h"

/*********************************************
* Class: Bird
* Description: The base function for the four
* derived bird Classes.
*********************************************/
class Bird : public FlyingObject
{
public:
	void advance();
	void virtual kill();
	int virtual hit();
	void virtual draw();
};

#endif

#ifndef STANDARD_H
#define STANDARD_H

/*********************************************
* Class: Standard
* Description: The class for the Standard Bird
*********************************************/
class Standard : public Bird
{
public:
	//Default constructor
	Standard()
	{
		int i = random(-200, 200);
		point.setX(-200);
		point.setY(i);
		velocity.setDx(4);
		// If its spawns at the bottom half of the 
		// screen then set the bird to fly up and
		// vice versa
		if (i > 0)
			velocity.setDy(-1);
		else
			velocity.setDy(2);
		
		isAlive1 = true;

	}
	int hit();
	void draw();
};

#endif

#ifndef TOUGHBIRD_H
#define TOUGHBIRD_H

/*********************************************
* Class: ToughBird
* Description: The class for the ToughBird.
*********************************************/
class ToughBird : public Bird
{
	int hit1;
public:
	// Default constructor
	ToughBird()
	{
		// Keeps track of the hits
		hit1 = 3;
		// Spawns it at random points on the left
		int i = random(-200, 200);
		point.setX(-200);
		point.setY(i);
		velocity.setDx(2);
		// If its spawns at the bottom half of the 
		// screen then set the bird to fly up and
		// vice versa
		if (i > 0)
			velocity.setDy(-1);
		else
			velocity.setDy(1);
		isAlive1 = true;
		

	}
	void kill();
	int hit();
	void draw();
};

#endif

#ifndef SACREDBIRD_H
#define SACREDBIRD_H

/*********************************************
* Class: SacredBird
* Description: The class for the Sacred Bird.
*********************************************/
class SacredBird : public Bird
{
public:
	// Default constructor
	SacredBird()
	{
		int i = random(-200, 200);
		point.setX(-200);
		point.setY(i);
		velocity.setDx(4);
		// If its spawns at the bottom half of the 
		// screen then set the bird to fly up and
		// vice versa
		if (i > 0)
			velocity.setDy(-1);
		else
			velocity.setDy(1);
		isAlive1 = true;
	}
	int hit();
	void draw();
};

#endif

#ifndef SUPERTOUGH_H
#define SUPERTOUGH_H

/*********************************************
* Class: SuperTough
* Description: An extra class that I implemented.
* This class is for a Super Tough Bird.
*********************************************/
class SuperTough : public Bird
{
	int hit1;
public:
	// Default Constructor
	SuperTough()
	{
		// Keeps tracks of hits
		hit1 = 5;
		int i = random(-200, 200);
		point.setX(-200);
		point.setY(i);
		velocity.setDx(2);
		// If its spawns at the bottom half of the 
		// screen then set the bird to fly up and
		// vice versa
		if (i > 0)
			velocity.setDy(-1);
		else
			velocity.setDy(1);
		isAlive1 = true;


	}
	void kill();
	int hit();
	void draw();
};
#endif