/*************************************************************
* File: bird.cpp
* Author: Jason Reed
*
* Description: Contains the implementations of the
*  method bodies for the Bird class.
*
*************************************************************/
#include "bird.h"

/*********************************************
* Function: advance
* Description: Move everything forward one
*  step in time.
*********************************************/
void Bird::advance()
{
	point.addX(velocity.getDx());
	point.addY(velocity.getDy());

}

/*********************************************
* Function: kill
* Description: Set isAlive1 to false
*********************************************/
void Bird::kill()
{
	isAlive1 = false;
}

/*********************************************
* Function: advance
* Description: Virtual function for the derived
* classes.
*********************************************/
int Bird::hit()
{
	return 0;
}

/*********************************************
* Function: draw
* Description: Pure virtual function for the
* derived classes
*********************************************/
void Bird::draw()
{
	
}

/*********************************************
* Function: hit
* Description: Returns 1 point for the Standard
* bird
*********************************************/
int Standard::hit()
{
	return 1;
}

/*********************************************
* Function: draw
* Description: Draws the standard bird.
*********************************************/
void Standard::draw()
{
	drawCircle(point, 10);
}

/*********************************************
* Function: kill
* Description: Must hit the bird 3 times
* to kill the tough bird.
*********************************************/
void ToughBird::kill()
{
	if (hit1 == 1)
		isAlive1 = false;
	else
		isAlive1 = true;
}

/*********************************************
* Function: hit
* Description: Deincriments the hit variable
* to keep track of how many times its been hit
*********************************************/
int ToughBird::hit()
{
	hit1--;
	if (hit1 == 0)
		return 3;
	else
		return 1;
}

/*********************************************
* Function: draw
* Description: Draws the tough bird.
*********************************************/
void ToughBird::draw()
{
	drawToughBird(point, 12, hit1);
}

/*********************************************
* Function: hit
* Description: Returns a value of negative 10
* if the bird is hit.
*********************************************/
int SacredBird::hit()
{
	return -10;
}

/*********************************************
* Function: draw
* Description: Draws the sacred bird
*********************************************/
void SacredBird::draw()
{
	drawSacredBird(point, 12);
}

/*********************************************
* Function: kill
* Description: Determines if the bird is dead
*********************************************/
void SuperTough::kill()
{
	if (hit1 == 1)
		isAlive1 = false;
	else
		isAlive1 = true;
}

/*********************************************
* Function: hit
* Description: Return 9 points if the bird is 
* dead
*********************************************/
int SuperTough::hit()
{
	hit1--;
	if (hit1 == 0)
		return 6;
	else
		return 0;
}

/*********************************************
* Function: draw
* Description: Draws the super tough bird
*********************************************/
void SuperTough::draw()
{
	drawLander(point);
  drawNumber(point, hit1);
}