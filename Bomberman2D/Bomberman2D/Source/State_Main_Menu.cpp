#include "../Include/State_Main_Menu.h"
#include "../Include/State_Single_Player.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;

extern std::string textMainMenu;


void Main_Menu::Initialize(sf::RenderWindow* window)
{
	const std::string textMainMenu[5] = { TEXT_MAINMENU, TEXT_SINGLEPLAYER, TEXT_MULTIPLEPLAYER, TEXT_HIGHSCORE, TEXT_QUIT};
	 
	this->selectMode = new auto(0);
	*this->selectMode = STATE_SINGLE_PLAYER;
	
	this->font = new sf::Font();
	this->font->loadFromFile("Resource/Fonts/font.ttf");

	this->textMainMenu = new sf::Text(TEXT_MAINMENU, *this->font, 128U);
	this->textMainMenu->setOrigin(this->textMainMenu->getGlobalBounds().width / 2, this->textMainMenu->getGlobalBounds().height / 2);
	this->textMainMenu->setPosition(window->getSize().x * SCREEN_MAINMENU_X, window->getSize().y * SCREEN_MAINMENU_Y);

	this->textSinglePlayer = new sf::Text(textMainMenu[1], *this->font);
	this->textSinglePlayer->setOrigin(this->textSinglePlayer->getGlobalBounds().width / 2, this->textSinglePlayer->getGlobalBounds().height / 2);
	this->textSinglePlayer->setPosition(window->getSize().x * SCREEN_SINGLEPLAYER_X, window->getSize().y * SCREEN_SINGLEPLAYER_Y);
	
	this->textMultiplePlayer = new sf::Text(textMainMenu[2], *this->font);
	this->textMultiplePlayer->setOrigin(this->textMultiplePlayer->getGlobalBounds().width / 2, this->textMultiplePlayer->getGlobalBounds().height / 2);
	this->textMultiplePlayer->setPosition(window->getSize().x * SCREEN_MULTIPLEPLAYER_X, window->getSize().y * SCREEN_MULTIPLEPLAYER_Y);

	this->textHighScore = new sf::Text(textMainMenu[3], *this->font);
	this->textHighScore->setOrigin(this->textHighScore->getGlobalBounds().width / 2, this->textHighScore->getGlobalBounds().height / 2);
	this->textHighScore->setPosition(window->getSize().x * SCREEN_HIGHSCORE_X, window->getSize().y * SCREEN_HIGHSCORE_Y);

	this->textQuit = new sf::Text(textMainMenu[4], *this->font);
	this->textQuit->setOrigin(this->textQuit->getGlobalBounds().width / 2, this->textQuit->getGlobalBounds().height / 2);
	this->textQuit->setPosition(window->getSize().x * SCREEN_QUIT_X, window->getSize().y * SCREEN_QUIT_Y);
}

void Main_Menu::UpdateGame(sf::RenderWindow* window)
{
	//gamelogic

	// Check Keyboard Selection
	double holdUp = 0;
	double holdDown = 0;
	bool up = false, down = false;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
		while (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
			if (!holdUp)* this->selectMode -= 1;
			holdUp += 1;
		}
		while (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
			if (!holdDown)* this->selectMode += 1;
			holdDown += 1;
		}
		holdUp = 0;
		holdDown = 0;
	}

	if (*this->selectMode < STATE_SINGLE_PLAYER)* this->selectMode = STATE_QUIT;
	else if (*this->selectMode > STATE_QUIT)* this->selectMode = STATE_SINGLE_PLAYER;

	switch (*this->selectMode) {
	case STATE_SINGLE_PLAYER:
		this->textQuit->setFillColor(sf::Color::White);
		this->textSinglePlayer->setFillColor(sf::Color::Red);
		this->textMultiplePlayer->setFillColor(sf::Color::White);
		break;
	case STATE_MULTIPLE_PLAYER:
		this->textSinglePlayer->setFillColor(sf::Color::White);
		this->textMultiplePlayer->setFillColor(sf::Color::Cyan);
		this->textHighScore->setFillColor(sf::Color::White);
		break;
	case STATE_HIGH_SCORE:
		this->textMultiplePlayer->setFillColor(sf::Color::White);
		this->textHighScore->setFillColor(sf::Color::Yellow);
		this->textQuit->setFillColor(sf::Color::White);
		break;
	case STATE_QUIT:
		this->textHighScore->setFillColor(sf::Color::White);
		this->textQuit->setFillColor(sf::Color::Green);
		this->textSinglePlayer->setFillColor(sf::Color::White);
		break;

	}
	// End Selection

	// Change State
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return)) {
		switch(*this->selectMode)
		{
		case STATE_SINGLE_PLAYER:
			stateHandler.SetState(new State_Single_Player());
			break;
		case STATE_QUIT:
			quitGame = true;
		default :
			break;
		}
	}
}

void Main_Menu::UpdateScreen(sf::RenderWindow* window)
{
	// Clear Window Buffer before drawing
	window->clear(sf::Color::Black);

	window->draw(*this->textMainMenu);
	window->draw(*this->textSinglePlayer);
	window->draw(*this->textMultiplePlayer);
	window->draw(*this->textHighScore);
	window->draw(*this->textQuit);
}

void Main_Menu::Destroy(sf::RenderWindow* window)
{
	delete this->textMainMenu;
	delete this->textSinglePlayer;
	delete this->textMultiplePlayer;
	delete this->textHighScore;
	delete this->textQuit;

	delete this->downKey;
	delete this->upKey;
	delete this->selectMode;
	delete this->font;
}
