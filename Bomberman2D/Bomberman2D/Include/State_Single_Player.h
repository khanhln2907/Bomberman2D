#pragma once
#include "../Include/State_Handler.h"
class State_Single_Player : public State
{
public:
	void Initialize(sf::RenderWindow* window);
	void UpdateGame(sf::RenderWindow* window);
	void UpdateScreen(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);

private:
	sf::Font* font;
	sf::Text* textSinglePlayer;
};

