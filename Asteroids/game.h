/*********************************************************************
 * File: game.h
 * Description: Defines the game class for Asteroids
 *
 *********************************************************************/

#ifndef GAME_H
#define GAME_H

#include <vector>

#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "rocks.h"
#include "ship.h"
#include "bullet.h"

class Game
{
public:
	Game(Point tl, Point br)
	{
		// Set up the initial conditions of the game
		topLeft = tl;
		bottomRight = br;
		initialize = 0;
		thrust = false;
	}
	void handleInput(const Interface & ui);
	void advance();
	void draw(const Interface & ui);

private:
	// The objects needed
	Point topLeft;
	Point bottomRight;
	Velocity startVelocity;
	Ship ship;

	// Variables needed 
	bool thrust;
	int asteroid;
	int initialize;

	// Vectors for rocks and bullets
	std::vector<Rock*> rocks;
	std::vector<Bullet> bullets;

	// Advances the objects on the screen
	void advanceBullets();
	void advanceAsteroids();
	void advanceShip();

	// Creates the rocks
	void createRock(int count, int option,
		Point & topLeft, Velocity & startVelocity);

	// Cleans up dead objects
	void cleanUpZombies();

	// Handles collisions
	void handleCollisions();
};


#endif /* GAME_H */
