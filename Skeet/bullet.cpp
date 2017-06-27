/*************************************************************
* File: bullet.cpp
* Author: Jason Reed
*
* Description: Contains the implementations of the
*  method bodies for the Bullet class.
*
*************************************************************/
#include "bullet.h"
#include "uiDraw.h"
#include <cmath>

/*********************************************
* Function: kill
* Description: Returns isAlive1 as false.
*********************************************/
void Bullet::kill()
{
	isAlive1 = false;
}

/*********************************************
* Function: advance
* Description: Advances the bullet across the
* screen.
*********************************************/
void Bullet::advance()
{
	point.addX(velocity.getDx());
	point.addY(velocity.getDy());
	
}

/*********************************************
* Function: draw
* Description: Draws the bullet at a given point.
*********************************************/
void Bullet::draw()
{
	drawDot(point); 
}

/*********************************************
* Function: kill
* Description: Sets the velocity of the bullet
* when fired.
*********************************************/
void Bullet::fire(Point point, float angle)
{
	velocity.setDx(velocity.getDx() + BULLET_SPEED * (-cos(M_PI / 180.0 * angle)));
	velocity.setDy(velocity.getDy() + BULLET_SPEED * (sin(M_PI / 180.0 * angle)));
}