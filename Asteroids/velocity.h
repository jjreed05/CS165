#ifndef VELOCITY_H
#define VELOCITY_H


// Put your velocity class here, or overwrite this file with your own
// velocity class from the previous project
class Velocity
{
	// The private variables
protected:
	float dx;
	float dy;

	// The public variables
public:
	// Default constructor
	Velocity()
	{
		dx = 0;
		dy = 0;
	}
	// Non-Default constructor
	Velocity(float dx, float dy)
	{
		this->dx = dx;
		this->dy = dy;
	}

	// Getters
	float getDx() const;
	float getDy() const;

	// Setters
	void setDx(float dx);
	void setDy(float dy);
};

#endif /* velocity_h */
