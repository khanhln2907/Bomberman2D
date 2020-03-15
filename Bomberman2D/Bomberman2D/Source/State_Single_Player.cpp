#include "../Include/State_Single_Player.h"
#include "../Include/State_Main_Menu.h"
#include "..//Include/main.h"
#include <iostream>
using std::cout;
using std::endl;


void State_Single_Player::Initialize(sf::RenderWindow* window)
{
	this->playerIndex = -1;
	this->keyPress = false;
	this->keyRelease = true;

	// Init Font and Text
	this->font = new sf::Font();
	this->font->loadFromFile("Resource/Fonts/font.ttf");

	this->textSinglePlayer = new sf::Text("Playing", *this->font, 128U);
	this->textSinglePlayer->setOrigin(this->textSinglePlayer->getGlobalBounds().width / 2, this->textSinglePlayer->getGlobalBounds().height / 2);
	this->textSinglePlayer->setPosition(window->getSize().x / 2, window->getSize().y / 2);
	
	// Memory for object;
	this->playerPtr = new Player* [20];
	
}
void State_Single_Player::UpdateGame(sf::RenderWindow* window)
{
	// Creat Object when left mouse is pressed;
	if (this->checkMousePressed(sf::Mouse::Button::Left) && this->playerIndex < 20) {
		this->playerIndex += 1;
		float posMouseX = sf::Mouse::getPosition(*window).x;
		float posMouseY = sf::Mouse::getPosition(*window).y;

		this->playerPtr[this->playerIndex] = new Player;
		this->playerPtr[this->playerIndex]->LoadImage("ball.png");
		this->playerPtr[this->playerIndex]->setPosition(posMouseX, posMouseY);

		cout << "Real Mouse X Y " << this->playerPtr[this->playerIndex]->getPosition().x << " " << this->playerPtr[this->playerIndex]->getPosition().y << endl;
		cout << "Pos Mouse X Y " << posMouseX << " " << posMouseY << endl;

		
		// Set up new object
		this->playerPtr[this->playerIndex]->velocity->y = 0;
	}

	if (this->playerIndex >= 0)
	{
		for (int i = 0; i <= this->playerIndex; i++) {
			// Action of object here
			/*this->playerPtr[i]->velocity->y = this->playerPtr[i]->velocity->y + dt * G;
			if (this->playerPtr[i]->getPosition().y + this->playerPtr[i]->getGlobalBounds().height >= SCREEN_HEIGHT)
				this->playerPtr[i]->velocity->y = this->playerPtr[i]->velocity->y * -1 + 0.05;
		
			if (this->playerPtr[i]->getPosition().y + this->playerPtr[i]->getGlobalBounds().height > SCREEN_HEIGHT+1) {
				this->playerPtr[i]->setPosition(this->playerPtr[i]->getPosition().x, SCREEN_HEIGHT - this->playerPtr[i]->getGlobalBounds().height);
				this->playerPtr[i]->velocity->y = 0;
			}*/

			this->playerPtr[i]->move(0, this->playerPtr[i]->velocity->y);
		}
	}
	
	
	// Movement Logic


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
	for (int i = 0; i <= this->playerIndex; i++) {
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
