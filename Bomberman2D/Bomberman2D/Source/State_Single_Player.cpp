#include "../Include/State_Single_Player.h"
#include "../Include/State_Main_Menu.h"
#include <iostream>
using std::cout;
using std::endl;


void State_Single_Player::Initialize(sf::RenderWindow* window)
{
	this->playerIndex = 0;
	this->keyPress = false;
	this->keyRelease = true;

	// Init Font and Text
	this->font = new sf::Font();
	this->font->loadFromFile("Resource/Fonts/font.ttf");

	this->textSinglePlayer = new sf::Text("Playing", *this->font, 128U);
	this->textSinglePlayer->setOrigin(this->textSinglePlayer->getGlobalBounds().width / 2, this->textSinglePlayer->getGlobalBounds().height / 2);
	this->textSinglePlayer->setPosition(window->getSize().x / 2, window->getSize().y / 2);

	// Init Player
	/*this->playerIndex = 0;
	this->player = new Player;
	this->player->LoadImage("ball.png");
	this->player->setPosition(50, 50);*/

	//this->playerPtr = new Player * [20]; // allocate free space with size of 20 * class Player
	//this->playerPtr[0] = new Player; // allocate space for 1 new player
	//this->playerPtr[0]->LoadImage("ball.png");
	//this->playerPtr[0]->setPosition(100, 100);

	this->playerPtr = new Player* [20];
	
}
void State_Single_Player::UpdateGame(sf::RenderWindow* window)
{
	float posMouseX = sf::Mouse::getPosition(*window).x;
	float posMouseY = sf::Mouse::getPosition(*window).y;

	// Creat Object when left mouse is pressed;
	if (this->checkMousePressed(sf::Mouse::Button::Left) && this->playerIndex < 20) {
		this->playerPtr[this->playerIndex] = new Player;
		this->playerPtr[this->playerIndex]->LoadImage("ball.png");
		this->playerPtr[this->playerIndex]->setPosition(posMouseX, posMouseY);
		this->playerIndex += 1;
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
	//window->draw(*this->player);
	for (int i = 0; i < this->playerIndex; i++) {
		window->draw(*this->playerPtr[i]);
	}
}
void State_Single_Player::Destroy(sf::RenderWindow* window)
{
	delete this->font;
	delete this->textSinglePlayer;
	//elete this->player;
	for (int i = 0; i < this->playerIndex; i++) {
		delete this->playerPtr[i];
	}
	cout << "State Destroyed" << endl;
}

bool State_Single_Player::checkMousePressed(sf::Mouse::Button key)
{
	if (sf::Mouse::isButtonPressed(key)) {
		this->keyPress = true;
		this->keyRelease = false;
	}
	if (!sf::Mouse::isButtonPressed(key)) {
		this->keyRelease = true;
	}
		
	if (this->keyPress == true && this->keyRelease == true) {
		this->keyPress = false;
		return true;
	}
	else return false;
}
