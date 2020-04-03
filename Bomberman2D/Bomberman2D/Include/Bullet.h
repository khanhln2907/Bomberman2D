#pragma once
#include "Entity.h"
class Bullet : public Entity
{
public:
	Bullet(sf::Vector2f firePosition, double attackAngle, double velocity);
	~Bullet();
	void updateMove();


private:
	double* dt = new double;
	sf::Vector2f* position;
	double* velocity;
	sf::Vector2f* velocityXY;
	double* direction;
};

