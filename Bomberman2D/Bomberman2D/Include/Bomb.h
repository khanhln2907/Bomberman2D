#pragma once
#include "Entity.h"

#define SIZE_BOMB 50
#define EXPLODED 1

class Bomb : public Entity
{
public:
	Bomb(sf::Vector2f firePosition, double length);
	~Bomb();
	bool update(sf::RenderWindow* window); // return 1 if deleted
	void explode(sf::RenderWindow* window);

private:
	double* length; // Unit : Amount of block
	double* explodedTime;
	double* deleteTime;
	//double* timer = new double;

	sf::Clock* timer;
	sf::Vector2f* position;
};

