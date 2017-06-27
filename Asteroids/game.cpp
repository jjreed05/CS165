/*********************************************************************
 * File: game.cpp
 * Description: Contains the implementaiton of the game class
 *  methods.
 *
 *********************************************************************/

#include "game.h"

// These are needed for the getClosestDistance function...
#include <limits>
#include <algorithm>
#include <vector>
using namespace std;


// You may find this function helpful...

/**********************************************************
 * Function: getClosestDistance
 * Description: Determine how close these two objects will
 *   get in between the frames.
 **********************************************************/
/*
float Game :: getClosestDistance(const FlyingObject &obj1, const FlyingObject &obj2) const
{
   // find the maximum distance traveled
   float dMax = max(abs(obj1.getVelocity().getDx()), abs(obj1.getVelocity().getDy()));
   dMax = max(dMax, abs(obj2.getVelocity().getDx()));
   dMax = max(dMax, abs(obj2.getVelocity().getDy()));
   dMax = max(dMax, 0.1f); // when dx and dy are 0.0. Go through the loop once.
   
   float distMin = std::numeric_limits<float>::max();
   for (float i = 0.0; i <= dMax; i++)
   {
      Point point1(obj1.getPoint().getX() + (obj1.getVelocity().getDx() * i / dMax),
                     obj1.getPoint().getY() + (obj1.getVelocity().getDy() * i / dMax));
      Point point2(obj2.getPoint().getX() + (obj2.getVelocity().getDx() * i / dMax),
                     obj2.getPoint().getY() + (obj2.getVelocity().getDy() * i / dMax));
      
      float xDiff = point1.getX() - point2.getX();
      float yDiff = point1.getY() - point2.getY();
      
      float distSquared = (xDiff * xDiff) +(yDiff * yDiff);
      
      distMin = min(distMin, distSquared);
   }
   
   return sqrt(distMin);
}
*/

/*********************************************
* Function: handleInput
* Description: Allows the user to control the
* the ship with the given inputs
*********************************************/
void Game::handleInput(const Interface & ui)
{
	// Up Key Input
	if (ui.isUp())
	{
		thrust = true;
		ship.setThrust(thrust);
		ship.applyThrust();

	}
	// Turns off the thruster if up key is not pressed
	else
	{
		thrust = false;
		ship.setThrust(thrust);
	}
	// Rotates the ship to the left
	if (ui.isLeft())
	{
		ship.setPositiveRotation();
	}
	// Rotates the ship to the right
	if (ui.isRight())
	{
		ship.setNegativeRotation();
	}
	// Fires the bullets
	if (ui.isSpace())
	{
		if (ship.isAlive())
		{
			Bullet newBullet(ship.getPoint());
			newBullet.fire(ship.getAngle());

			bullets.push_back(newBullet);
		}
	}



}

/*********************************************
* Function: advance
* Description: Advances everything on the 
* screen and gets rid of dead objects.
*********************************************/
void Game::advance()
{
	handleCollisions();
	advanceAsteroids();
	advanceShip();
	advanceBullets();
	cleanUpZombies();
}

/*********************************************
* Function: draw
* Description: Calls the ship, rock, and bullets 
* draw functions.
*********************************************/
void Game::draw(const Interface & ui)
{
	// Draw Rocks
	for (int i = 0; i < rocks.size(); i++)
	{
		rocks[i]->draw();
	}
	// Draw the Ship
	if (ship.isAlive())
	{
		ship.draw();
	}
	// Draw the Bullets
	for (int i = 0; i < bullets.size(); i++)
	{
		bullets[i].draw();
	}
}

/*********************************************
* Function: advanceBullets
* Description: Advances and or kills the bullets
* on the screen.
*********************************************/
void Game::advanceBullets()
{
	
	for (int i = 0; i < bullets.size(); i++)
	{
		// After 40 frames, kill the bullet
		if (bullets[i].frame == 40)
		{
			bullets[i].kill();
		}
		// Advance the bullets if less than 40 frames
		if (bullets[i].isAlive())
		{
			bullets[i].advance();
			bullets[i].frame++;
		}
	}
	
}

/*********************************************
* Function: advanceAsteroids
* Description: Creates the initial 5 rocks
* and calls the advance function if the rock
* is not dead.
*********************************************/
void Game::advanceAsteroids()
{
	// Creates five large asteroids
	if (initialize == 0)
	{
		createRock(5, 0, topLeft, startVelocity);
		initialize++;
	}

	// Advances the rocks
	for (int i = 0; i < rocks.size(); i++)
	{
		if (rocks[i]->isAlive())
			rocks[i]->advance();
	}
}

/*********************************************
* Function: advanceShip
* Description: If the ship is alive then this
* function advances the ship.
*********************************************/
void Game::advanceShip()
{
	if (ship.isAlive())
		ship.advance();
}

/*********************************************
* Function: createRock
* Description: Decides which rock to create
* based on the parameters passed in.
*********************************************/
void Game::createRock(int count, int option,
	Point & topLeft, Velocity & startVelocity)
{
	// Creates the Big Asteroids on random points on the screen
	// and sets random velocities
	if (option == 0)
	{
		for (int i = 0; i < count; i++)
		{
			// Start position
			Point startPosition;
			startPosition.setX(random(topLeft.getX(), bottomRight.getX()));
			startPosition.setY(random(bottomRight.getY(), topLeft.getY()));
			// Picks a random number between -1 and 2
			int rand = random(-1, 2);
			// Picks a different number if the number is 0
			while (rand == 0)
				rand = random(-1, 2);
			// Random velocity
			startVelocity.setDy(rand);
			startVelocity.setDx(rand);

			// Pushes the new asteroid into the vector
			Rock* newAsteroid = new BigRock(startPosition, startVelocity);
			rocks.push_back(newAsteroid);
		}
	}

	// If the Big asteroid is hit, this function will create two medium asteroids
	// and one small asteroid
	if (option == 1)
	{
		// Velocity objects for the 3 asteroids
		Velocity velocity1;
		Velocity velocity2;
		Velocity velocity3;

		// Asteroid goes up
		velocity1.setDx(startVelocity.getDx());
		velocity1.setDy(startVelocity.getDy() + 1);
		// Asteroid goes down
		velocity2.setDx(startVelocity.getDx());
		velocity2.setDy(startVelocity.getDy() - 1);
		// Asteroid goes to the right
		velocity3.setDx(startVelocity.getDx() + 2);
		velocity3.setDy(startVelocity.getDy());

		// Creates the asteroid pointers and pushes the asteroids into the vector
 		Rock* newAsteroid1 = new MediumRock(topLeft, velocity1);
		rocks.push_back(newAsteroid1);

		Rock* newAsteroid2 = new MediumRock(topLeft, velocity2);
		rocks.push_back(newAsteroid2);

		Rock* newAsteroid3 = new SmallRock(topLeft, velocity3);
		rocks.push_back(newAsteroid3);
	}

	// If medium asteroid is hit, this will create two small asteroids
	if (option == 2)
	{
		// The Velocity objects for the 2 asteroids
		Velocity velocity1;
		Velocity velocity2;

		// One asteroid moves to the left
		velocity1.setDx(startVelocity.getDx() - 3);
		velocity1.setDy(startVelocity.getDy());
		// The other moves to the right
		velocity2.setDx(startVelocity.getDx() + 3);
		velocity2.setDy(startVelocity.getDy());

		// Creates the pointers and pushes the asteroid into the vector
		Rock* newAsteroid1 = new SmallRock(topLeft, velocity1);
		rocks.push_back(newAsteroid1);

		Rock* newAsteroid2 = new SmallRock(topLeft, velocity2);
		rocks.push_back(newAsteroid2);
	}



}

/*********************************************
* Function: handleCollisions
* Description: This function tells the program
* what to do when the objects collide.
*********************************************/
void Game::handleCollisions()
{
	for (int i = 0; i < bullets.size(); i++)
	{
		// check if the asteroid is at this point (in case it was hit)			
		for (int j = 0; j < rocks.size(); j++)
		{
			if (bullets[i].isAlive())
			{
				if (rocks[j]->isAlive())
				{
					// Determines if the bullets collided with the asteroids
					if (fabs(bullets[i].getPoint().getX() - rocks[j]->getPoint().getX()) < 15
						&& fabs(bullets[i].getPoint().getY() - rocks[j]->getPoint().getY()) < 15)
					{
						
						// we have a hit!
						rocks[j]->hit();

						// Creates a new point object to pass as a parameter to create the new asteroids
						Point point;
						point.setX(rocks[j]->getPoint().getX());
						point.setY(rocks[j]->getPoint().getY());

						// Creates a new velocity object to pass as a parameter to create the new asteroids
						Velocity velocity;
						velocity.setDx(rocks[j]->getVelocity().getDx());
						velocity.setDy(rocks[j]->getVelocity().getDy());

						// Rock is not alive anymore
						rocks[j]->kill();
						// Creates smaller asteroid at the point of collision
						createRock(5, rocks[j]->hit(), point, velocity);
						

						// the bullet is dead as well
						bullets[i].kill();

					}
				
				}
			}
		} // if bullet is alive

	} // for bullets

	// Determines if the ship is still alive
	for (int j = 0; j < rocks.size(); j++)
	{
		if (ship.isAlive())
		{
			if (rocks[j]->isAlive())
			{
				// Determines if the ship and the asteroids have collided
				if (fabs(ship.getPoint().getX() - rocks[j]->getPoint().getX()) < 15
					&& fabs(ship.getPoint().getY() - rocks[j]->getPoint().getY()) < 15)
				{

					// we have a hit!
					rocks[j]->hit();

					// Creates a new point object to pass as a parameter to create the new asteroids
					Point point;
					point.setX(rocks[j]->getPoint().getX());
					point.setY(rocks[j]->getPoint().getY());

					// Creates a new velocity object to pass as a parameter to create the new asteroids
					Velocity velocity;
					velocity.setDx(rocks[j]->getVelocity().getDx());
					velocity.setDy(rocks[j]->getVelocity().getDy());

					// The Asteroid is not alive
					rocks[j]->kill();
					// Creates new Asteroid in its place
					createRock(5, rocks[j]->hit(), point, velocity);


					// Determines if ship is dead
					ship.kill();

				}

			}
		}
	} // if bullet is alive
	
}

/*********************************************
* Function: cleanUpZombies
* Description: Cleans up the dead objects
*********************************************/
void Game::cleanUpZombies()
{
	// Cleans up the bullets
	vector<Bullet>::iterator bulletIt = bullets.begin();
	while (bulletIt != bullets.end())
	{
		Bullet bullet = *bulletIt;

		if (!bullet.isAlive())
		{
			// If we had a list of pointers, we would need to delete the memory here...


			// remove from list and advance
			bulletIt = bullets.erase(bulletIt);
		}
		else
		{
			bulletIt++; // advance
		}
	}

	// Cleans up the rocks
	vector<Rock*>::iterator rocksIt = rocks.begin();
	while (rocksIt != rocks.end())
	{
		Rock * rock = *rocksIt;
		if (!rock->isAlive())
		{
			// remove from list and advance
			delete *rocksIt;
			rocksIt = rocks.erase(rocksIt);
		}
		else
		{
			rocksIt++; // advance
		}
	}

}
