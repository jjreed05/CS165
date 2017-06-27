#include "rocks.h"

// Put your Rock methods here
void Rock::advance()
{
	if (point.getX() < -210)
	{
		point.setY(point.getY() + velocity.getDy());
		point.setX(210);
	}
	else if (point.getX() > 210)
	{
		point.setY(point.getY() + velocity.getDy());
		point.setX(-210);
	}
	else if (point.getY() < -210)
	{
		point.setY(210);
		point.setX(point.getX() + velocity.getDx());
	}
	else if (point.getY() > 210)
	{
		point.setY(-210);
		point.setX(point.getX() + velocity.getDx());
	}
	else
	{
		point.setY(point.getY() + velocity.getDy());
		point.setX(point.getX() + velocity.getDx());
	}


	angle += rotation;
	//if (angle >= 360)
		//angle -= 360;

}

void Rock::kill()
{
	isAlive1 = false;
}

int Rock::hit()
{
	return 0;
}

void Rock::draw()
{
	
}

BigRock::BigRock(Point & startPosition, Velocity & startVelocity)
{
	point = startPosition;
	velocity = startVelocity;
	radius = BIG_ROCK_SIZE;
	rotation = BIG_ROCK_SPIN;
	isAlive1 = true;

}

int BigRock::hit()
{
	return 1;
}

void BigRock::draw()
{
	drawLargeAsteroid(point, angle);
}

MediumRock::MediumRock(Point & startPosition, Velocity & startVelocity)
{
	point = startPosition;
	velocity = startVelocity;
	radius = MEDIUM_ROCK_SIZE;
	rotation = MEDIUM_ROCK_SPIN;
	isAlive1 = true;
}

int MediumRock::hit()
{
	return 2;
}

void MediumRock::draw()
{
	drawMediumAsteroid(point, angle);
}

SmallRock::SmallRock(Point & startPosition, Velocity & startVelocity)
{
	point = startPosition;
	velocity = startVelocity;
	radius = SMALL_ROCK_SIZE;
	rotation = SMALL_ROCK_SPIN;
	isAlive1 = true;
}

int SmallRock::hit()
{
	return 3;
}

void SmallRock::draw()
{
	drawSmallAsteroid(point, angle);
}