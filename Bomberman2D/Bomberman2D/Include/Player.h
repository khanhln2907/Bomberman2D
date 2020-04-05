#pragma once
#include "Entity.h"
#include "Bomb.h"

#define NO_MOVE 0
#define MOVE_VERTICAL 1
#define MOVE_HORIZON 2

class Player : public Entity{
public:
	Player();
	~Player();
	
	void placeBomb();
	void updateMove();
	void updateBomb(sf::RenderWindow* window);
	void updateScreen(sf::RenderWindow* window);


private:
	short prevMove;

	int maxBomb = 5;
	sf::Vector2f position;

	std::vector<Bomb*> bombVector;
};