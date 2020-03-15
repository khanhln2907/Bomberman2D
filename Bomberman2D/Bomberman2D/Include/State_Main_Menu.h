#pragma once
#include "State_Handler.h"

#define SCREEN_MAINMENU_X 1/2
#define SCREEN_MAINMENU_Y 1/4
#define TEXT_MAINMENU "Main Menu"
#define SCREEN_SINGLEPLAYER_X 1/2
#define SCREEN_SINGLEPLAYER_Y 4/8
#define TEXT_SINGLEPLAYER "Single Player"
#define SCREEN_MULTIPLEPLAYER_X 1/2
#define SCREEN_MULTIPLEPLAYER_Y 5/8
#define TEXT_MULTIPLEPLAYER "Multiple Player"
#define SCREEN_HIGHSCORE_X 1/2
#define SCREEN_HIGHSCORE_Y 6/8
#define TEXT_HIGHSCORE "High Score"
#define SCREEN_QUIT_X 1/2
#define SCREEN_QUIT_Y 7/8
#define TEXT_QUIT "Quit Game"

class Main_Menu : public State
{
public:
	void Initialize(sf::RenderWindow* window);
	void UpdateGame(sf::RenderWindow* window);
	void UpdateScreen(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);
private:
	int* selectMode;
	bool *upKey, *downKey;

	sf::Font* font;
	sf::Text* textMainMenu;
	sf::Text* textSinglePlayer;
	sf::Text* textMultiplePlayer;
	sf::Text* textHighScore;
	sf::Text* textQuit;
};



