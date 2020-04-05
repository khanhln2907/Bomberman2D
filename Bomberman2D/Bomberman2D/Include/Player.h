#pragma once
#include "Entity.h"
#include "Bomb.h"

#define NO_MOVE 0
#define MOVE_VERTICAL 1
#define MOVE_HORIZON 2

// For Bomb Placement
#define BOMB_OFFSET 20
#define MOVE_LEFT 1
#define MOVE_RIGHT -1
#define MOVE_UP 1
#define MOVE_DOWN -1


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
	bool moveVer; // These are used for accurate bombplacement
	bool moveHor;

	int maxBomb = 5;
	sf::Vector2f position;

	std::vector<Bomb*> bombVector;
};