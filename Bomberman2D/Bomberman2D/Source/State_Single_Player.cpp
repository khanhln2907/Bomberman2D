#include "../Include/State_Single_Player.h"
#include "../Include/State_Main_Menu.h"
#include"../Include/main.h"
#include "../Include/Map.h"
#include <string.h>

using std::cout;
using std::endl;
using std::string;
extern const char mapLevel1[MAP_HEIGHT][MAP_WIDTH];

void State_Single_Player::Initialize(sf::RenderWindow* window)
{
	this->playerIndex = -1;
	this->mouseRightPrev = false;
	this->mouseLeftPrev = false;
	this->level = 1;

	// Init Font and Text
	this->font = new sf::Font();
	this->font->loadFromFile("Resource/Fonts/font.ttf");

	char textBuffer[100];
	sprintf_s(textBuffer, "Level %d", this->level);
	this->textSinglePlayer = new sf::Text(textBuffer, *this->font, 30U);
	//this->textSinglePlayer->setOrigin(this->textSinglePlayer->getGlobalBounds().width / 2, this->textSinglePlayer->getGlobalBounds().height / 2);
	this->textSinglePlayer->setFillColor(sf::Color::White);
	this->textSinglePlayer->setPosition(10, 10);
	
	// Memory for object;
	this->map = new Entity();
	this->map->LoadImage("Map.jpg");
	this->map->setScale(MAP_WIDTH_SCALE, MAP_HEIGHT_SCALE);
	this->map->setPosition(MAP_OFFSET_X, MAP_OFFSET_Y);
	
	this->player = new Player;
	this->target = new Object * [20];
	
}
void State_Single_Player::UpdateGame(sf::RenderWindow* window)
{
	//this->player->updateAim(); // Pointing to target
	
	//if (this->checkMousePressed(MOUSE_RIGHT)) { // Fire Bullet if Button Is Pressed
	//	this->player->placeBomb();
	//}
	
	this->player->updateMove();
	this->player->updateBomb(window); // Update Tank Position and Bullet, tank can not move until now

	// Creat Object when left mouse is pressed;
	if (this->checkMousePressed(MOUSE_LEFT) && this->playerIndex < 20) {
		this->playerIndex += 1;
		float posMouseX = sf::Mouse::getPosition(*window).x;
		float posMouseY = sf::Mouse::getPosition(*window).y;

		this->target[this->playerIndex] = new Object;
		this->target[this->playerIndex]->LoadImage("ball.png");
		this->target[this->playerIndex]->setPosition(posMouseX, posMouseY);

		//cout << "Real Mouse X Y " << this->target[this->playerIndex]->getPosition().x << " " << this->target[this->playerIndex]->getPosition().y << endl;
		//cout << "Pos Mouse X Y " << posMouseX << " " << posMouseY << endl;

		
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
	window->clear(sf::Color::Black);
	this->DrawMap(window);
	//window->draw(*this->map);
	window->draw(*this->textSinglePlayer);
	//window->draw(*this->tank);
	this->player->updateScreen(window);
	//window->draw(*this->player);
	for (int i = 0; i <= this->playerIndex; i++) {
		window->draw(*this->target[i]);
	}
}
void State_Single_Player::DrawMap(sf::RenderWindow* window)
{
	for (int i = 0; i < MAP_WIDTH; i++) {
		for (int j = 0; j < MAP_HEIGHT; j++) {
			if (mapLevel1[j][i] == '|') {
				sf::RectangleShape rectangle(sf::Vector2f(SIZE_BLOCK, SIZE_BLOCK));
				rectangle.setFillColor(sf::Color::White);
				//rectangle.setOrigin(rectangle.getGlobalBounds().width / 2, rectangle.getGlobalBounds().height / 2);
				rectangle.setPosition((i) * SIZE_BLOCK + MAP_OFFSET_X, (j) * SIZE_BLOCK + MAP_OFFSET_Y);
				window->draw(rectangle);
			}
		}
	}
}
void State_Single_Player::Destroy(sf::RenderWindow* window)
{
	delete this->font;
	delete this->textSinglePlayer;
	delete this->player;
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