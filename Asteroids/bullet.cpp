#include "bullet.h"


// Put your bullet methods here

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
* Function: daw
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
void Bullet::fire(int angle)
{
	float dy = (BULLET_SPEED * cos(M_PI / 180.0 * angle));
	float dx = (BULLET_SPEED * -sin(M_PI / 180.0 * angle));
	velocity.setDx(velocity.getDx() + dx);
	velocity.setDy(velocity.getDy() + dy);
}