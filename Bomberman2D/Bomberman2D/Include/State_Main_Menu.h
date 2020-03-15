#pragma once
#include "State_Handler.h"
class Main_Menu : public State
{
public:
	void Initialize(sf::RenderWindow* window);
	void UpdateGame(sf::RenderWindow* window);
	void UpdateScreen(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);
private:

};



