#include "../Include/State_Single_Player.h"
#include "../Include/State_Main_Menu.h"
#include <iostream>
using std::cout;
using std::endl;


void State_Single_Player::Initialize(sf::RenderWindow* window)
{
	// Init Font and Text
	this->font = new sf::Font();
	this->font->loadFromFile("Resource/Fonts/font.ttf");

	this->textSinglePlayer = new sf::Text("Playing", *this->font, 128U);
	this->textSinglePlayer->setOrigin(this->textSinglePlayer->getGlobalBounds().width / 2, this->textSinglePlayer->getGlobalBounds().height / 2);
	this->textSinglePlayer->setPosition(window->getSize().x / 2, window->getSize().y / 2);

	// Init Player
	this->player = new Player;
	player->LoadImage("ball.png");
	player->setPosition(50, 50);

	Player* myPlayer = new Player[20];
	myPlayer->LoadImage("ball.png");
	player->setPosition(100, 100);

	//this->playerPtr = new Player[10];
	//this->playerPtr[0] = new Player;
	//this->playerPtr++;
	
}
void State_Single_Player::UpdateGame(sf::RenderWindow* window)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
		
		*(this->playerPtr)->LoadImage("ball.png");
	}
	if (this->playerPtr != NULL) {
		this->playerPtr->velocity->x = 0.5;
		this->playerPtr->velocity->y = 0.5;
		this->playerPtr->move(*this->playerPtr->velocity);
	}
	
	// Movement Logic
	/*player->velocity->x = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) - sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left);
	player->velocity->y = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) - sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);

	if (player->getPosition().x <= 0) player->velocity->x = 1;
	if (player->getPosition().x + player->getGlobalBounds().width >= window->getSize().x) player->velocity->x = -1;
	if (player->getPosition().y <= 0) player->velocity->y = 1;
	if (player->getPosition().y + player->getGlobalBounds().height >= window->getSize().y) player->velocity->y = -1;
*/
	// Update Player Movement
	//player->move(*player->velocity);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
		stateHandler.SetState(new Main_Menu());
	}
}
void State_Single_Player::UpdateScreen(sf::RenderWindow* window)
{
	window->clear(sf::Color::Black);
	window->draw(*this->textSinglePlayer);
	window->draw(*this->player);
}
void State_Single_Player::Destroy(sf::RenderWindow* window)
{
	delete this->font;
	delete this->textSinglePlayer;
	delete this->player;
	cout << "State Destroyed" << endl;
}
