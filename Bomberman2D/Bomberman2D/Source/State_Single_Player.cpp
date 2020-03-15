#include "../Include/State_Single_Player.h"
#include <iostream>
using std::cout;
using std::endl;


void State_Single_Player::Initialize(sf::RenderWindow* window)
{
	this->font = new sf::Font();
	this->font->loadFromFile("Resource/Fonts/font.ttf");

	this->textSinglePlayer = new sf::Text("Playing", *this->font, 128U);
	this->textSinglePlayer->setOrigin(this->textSinglePlayer->getGlobalBounds().width / 2, this->textSinglePlayer->getGlobalBounds().height / 2);
	this->textSinglePlayer->setPosition(window->getSize().x / 2, window->getSize().y / 2);
}
void State_Single_Player::UpdateGame(sf::RenderWindow* window)
{
	;
}
void State_Single_Player::UpdateScreen(sf::RenderWindow* window)
{
	window->clear(sf::Color::Black);
	window->draw(*this->textSinglePlayer);
}
void State_Single_Player::Destroy(sf::RenderWindow* window)
{
	delete this->font;
	delete this->textSinglePlayer;
	cout << "State Destroyed" << endl;
}
