#pragma once
#include "../Include/State_Handler.h"
#include "Player.h"

#define G 9.81
#define M 0.2
#define dt 0.0001

class State_Single_Player : public State
{
public:
	void Initialize(sf::RenderWindow* window);
	void UpdateGame(sf::RenderWindow* window);
	void UpdateScreen(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);

private:
	// logic
	int playerIndex;
	bool keyPress, keyRelease;
	bool checkMousePressed(sf::Mouse::Button key);


	sf::Font* font;
	sf::Text* textSinglePlayer;
	//Player* player;
	Player** playerPtr;
	
	//Player playerPtr[10];
};

