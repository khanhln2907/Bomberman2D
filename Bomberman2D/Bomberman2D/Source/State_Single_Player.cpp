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
	this->mouseRightPrev = false;
	this->mouseLeftPrev = false;


	// Init Font and Text
	this->font = new sf::Font();
	this->font->loadFromFile("Resource/Fonts/font.ttf");

	this->textSinglePlayer = new sf::Text("Playing", *this->font, 30U);
	//this->textSinglePlayer->setOrigin(this->textSinglePlayer->getGlobalBounds().width / 2, this->textSinglePlayer->getGlobalBounds().height / 2);
	this->textSinglePlayer->setPosition(0, 0);
	
	// Memory for object;
	this->tank = new Player;
	this->target = new Object * [20];
	
}
void State_Single_Player::UpdateGame(sf::RenderWindow* window)
{
	this->tank->updateAim(); // Pointing to target
	
	if (this->checkMousePressed(MOUSE_RIGHT)) { // Fire Bullet if Button Is Pressed
		this->tank->fireBullet();
	}
	
	this->tank->updateBullet(window); // Update Tank Position and Bullet, tank can not move until now

	// Creat Object when left mouse is pressed;
	if (this->checkMousePressed(MOUSE_LEFT) && this->playerIndex < 20) {
		this->playerIndex += 1;
		float posMouseX = sf::Mouse::getPosition(*window).x;
		float posMouseY = sf::Mouse::getPosition(*window).y;

		this->target[this->playerIndex] = new Object;
		this->target[this->playerIndex]->LoadImage("ball.png");
		this->target[this->playerIndex]->setPosition(posMouseX, posMouseY);

		cout << "Real Mouse X Y " << this->target[this->playerIndex]->getPosition().x << " " << this->target[this->playerIndex]->getPosition().y << endl;
		cout << "Pos Mouse X Y " << posMouseX << " " << posMouseY << endl;

		
		// Set up new object
		this->target[this->playerIndex]->velocity->y = 0;
	}

	if (this->playerIndex >= 0)
	{
		for (int i = 0; i <= this->playerIndex; i++) {
			// Action of object here
			this->target[i]->velocity->y = this->target[i]->velocity->y + dt * G;
			if (this->target[i]->getPosition().y + this->target[i]->getGlobalBounds().height >= SCREEN_HEIGHT)
				this->target[i]->velocity->y = this->target[i]->velocity->y * -1 + 0.05;
		
			if (this->target[i]->getPosition().y + this->target[i]->getGlobalBounds().height > SCREEN_HEIGHT+1) {
				this->target[i]->setPosition(this->target[i]->getPosition().x, SCREEN_HEIGHT - this->target[i]->getGlobalBounds().height);
				this->target[i]->velocity->y = 0;
			}

			this->target[i]->move(0, this->target[i]->velocity->y);
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
	window->clear(sf::Color::White);
	window->draw(*this->textSinglePlayer);
	window->draw(*this->tank);
	tank->drawPlayer(window);
	//window->draw(*this->player);
	for (int i = 0; i <= this->playerIndex; i++) {
		window->draw(*this->target[i]);
	}
}
void State_Single_Player::Destroy(sf::RenderWindow* window)
{
	delete this->font;
	delete this->textSinglePlayer;
	delete this->tank;
	//elete this->player;
	for (int i = 0; i < this->playerIndex; i++) {
		delete this->target[i];
	}
	cout << "State Destroyed" << endl;
}

bool State_Single_Player::checkMousePressed(sf::Mouse::Button key)
{
	switch (key) {
	case MOUSE_LEFT:
		if (sf::Mouse::isButtonPressed(MOUSE_LEFT)) {
			this->mouseLeftPrev = true;
			return false;
		}
		else {
			if (this->mouseLeftPrev == true) {
				this->mouseLeftPrev = false;
				return true;
			}
			else {
				this->mouseLeftPrev = false;
				return false;
			}
		}
		break;
	case MOUSE_RIGHT:
		if (sf::Mouse::isButtonPressed(MOUSE_RIGHT)) {
			this->mouseRightPrev = true;
			return false;
		}
		else {
			if (this->mouseRightPrev == true) {
				this->mouseRightPrev = false;
				return true;
			}
			else {
				this->mouseRightPrev = false;
				return false;
			}
		}
		break;
	default:
		return false;
		break;
	}
	
}