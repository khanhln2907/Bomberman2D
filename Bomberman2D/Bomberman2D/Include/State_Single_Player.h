#pragma once
#include "../Include/State_Handler.h"
#include "Object.h"
#include "Player.h"

#define G 9.81
#define M 0.2
#define dt 0.0001

#define MOUSE_RIGHT sf::Mouse::Button::Right
#define MOUSE_LEFT sf::Mouse::Button::Left

class State_Single_Player : public State
{
public:
	void Initialize(sf::RenderWindow* window);
	void UpdateGame(sf::RenderWindow* window);
	void UpdateScreen(sf::RenderWindow* window);
	void DrawMap(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);

private:
	// logic
	int playerIndex;
	bool mouseLeftPrev;
	bool mouseRightPrev;
	bool checkMousePressed(sf::Mouse::Button key);

	// Level and Map
	short level;

	sf::Font* font;
	sf::Text* textSinglePlayer;
	
	Entity* map;
	Player* player;
	Object** target;
};

