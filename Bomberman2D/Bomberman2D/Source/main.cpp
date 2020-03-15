#include "../Include/main.h"
#include "../Include/State_Handler.h"
#include "../include/State_Main_Menu.h";

State_Handler stateHandler;
bool quitGame = false;

int main()
{
	// Init Setup
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Bomberman");
	stateHandler.SetWindow(&window);
	stateHandler.SetState(new Main_Menu());

	// Game Loop if window is still open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
				if (event.type == sf::Event::Closed)
				window.close();
		}

		//Update Game
		stateHandler.UpdateGame();

		//Screen Output
		stateHandler.UpdateScreen();

		if (quitGame) window.close();
	}

	//stateHandler.ExitState();

	return 0;
}