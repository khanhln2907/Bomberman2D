#pragma once
#include "Entity.h"
class Bullet : public Entity
{
public:
	Bullet(sf::Vector2f firePosition, double attackAngle, double velocity);
	~Bullet();
	void updateMove(sf::RenderWindow* window);


private:
	double orientationOffset = 3.14 / 4;
	double* dt = new double;
	double* velocity;
	sf::Vector2f* velocityXY;
	double* orientation;
	sf::Vector2f* position;
};

