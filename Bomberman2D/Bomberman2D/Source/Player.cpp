#include "../Include/Player.h"
#include "..//Include/main.h"
#include "../Include/Map.h"

#define PI 3.14
#define TOL 15

using std::cout;
using std::endl;
extern const char mapLevel1[MAP_HEIGHT][MAP_WIDTH];

Player::Player()
{
	// Init
	//this->LoadImage("rocket_base.jpg");
	//this->setOrigin(this->getGlobalBounds().width / 2, this->getGlobalBounds().height / 2);
	//this->setScale(sf::Vector2f(0.1, 0.1));
	this->position.x = GET_POSITON_X(1);
	this->position.y = GET_POSITON_Y(1);
	this->setPosition(this->position.x, this->position.y);

	// Movement
	this->prevMove = NO_MOVE;
}

Player::~Player()
{
	//delete this->bombVector;
}

void Player::updateMove()
{
	double directionHorizon = 0;
	double directionVertical = 0;
	double flagVertical = 0;
	double flagHorizon = 0;

	double cntBlockX = (double)(((int)(this->position.x) - MAP_OFFSET_X)) / (double)(SIZE_BLOCK);
	double cntBlockY = (double)(((int)(this->position.y) - MAP_OFFSET_Y)) / (double)(SIZE_BLOCK);

	// If object is not yet at the centre but still want to change direction, we add some tolerance here
	if (abs((int)(this->position.x) - MAP_OFFSET_X - round(cntBlockX) * SIZE_BLOCK) < TOL) {
		flagVertical = 1;
	}
	if (abs((int)(this->position.y) - MAP_OFFSET_Y - round(cntBlockY) * SIZE_BLOCK) < TOL) {
		flagHorizon = 1;
	}

	// If object in changeable are, we allow it to move
	if (flagVertical == 1) {
		if ((int)round(cntBlockX) % 2 != 0)
		directionVertical = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) - sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
	}
	if (flagHorizon == 1) {
		if ((int)round(cntBlockY) % 2 != 0)
		directionHorizon = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) - sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left);
	}

	// Correct Position if use Tolerant in Movement (not update move by this part)
	if (directionVertical && flagVertical) {
		this->position.x = (int)round(cntBlockX) * SIZE_BLOCK + MAP_OFFSET_X;
		//flagHorizon = 0;
	}
	if (directionHorizon && flagHorizon) {
		this->position.y =  (int)round(cntBlockY) * SIZE_BLOCK + MAP_OFFSET_Y;
		//flagVertical = 0;
	}

	// If player want to change both direction at the same time, we need this function to eliminate the previous movement
	if (directionHorizon && directionVertical) { // If change both at the same time
		switch (this->prevMove) {
		case MOVE_HORIZON:
			directionHorizon = 0;
			//this->prevMove = MOVE_HORIZON;
			break;
		case MOVE_VERTICAL:
			directionVertical = 0;
			//this->prevMove = MOVE_VERTICAL;
			break;
		default:
			this->prevMove = NO_MOVE;
			break;
		}
	}

	// Update Movement
	if (directionVertical) {
		this->position.y += directionVertical;
		this->prevMove = MOVE_VERTICAL;
		cout << "Move Vetical" << endl;
	}
	else if (directionHorizon) {
		this->position.x += directionHorizon;
		this->prevMove = MOVE_HORIZON;
		cout << "Move Horizon" << endl;
	}
	else {
		this->prevMove = NO_MOVE;
	}

	(this->position.x <= GET_POSITON_X(1)) ? this->position.x = GET_POSITON_X(1) : this->position.x;
	(this->position.x >= GET_POSITON_X(17)) ? this->position.x = GET_POSITON_X(17): this->position.x;

	(this->position.y <= GET_POSITON_Y(1)) ? this->position.y = GET_POSITON_Y(1) : this->position.y;
	(this->position.y >= GET_POSITON_Y(11)) ? this->position.y = GET_POSITON_Y(11) : this->position.y;

	
	//std::cout << "Angle in rad: " << this->aimAngle << std::endl;
	//std::cout << "Power : " << this->aimPower << std::endl;
}

void Player::placeBomb()
{
	/*if (this->bombVector.size() <= this->maxBullet) {
		this->bombVector.push_back(new Bullet(sf::Vector2f(this->position.x, this->position.y), this->aimAngle, this->aimPower));
	}*/
	// std::cout << "Bullet Fired" << std::endl;
}

void Player::updateBomb(sf::RenderWindow* window)
{
	for (int i = 0; i < this->bombVector.size(); i++) {
		this->bombVector[i]->updateMove(window);
		if (this->bombVector[i]->getPosition().x > window->getSize().x || this->bombVector[i]->getPosition().y > window->getSize().y 
		 || this->bombVector[i]->getPosition().x < 0 || this->bombVector[i]->getPosition().y < 0) {
			this->bombVector[i]->~Bullet();
			this->bombVector.erase(this->bombVector.begin() + i);
		}
	}
	
	//cout << "Amount of Bullet: " << this->bombVector.size() << endl;
}

void Player::updateScreen(sf::RenderWindow* window)
{
	// Draw actual player
	sf::RectangleShape rectangle(sf::Vector2f(SIZE_BLOCK, SIZE_BLOCK));
	rectangle.setFillColor(sf::Color::Cyan);
	rectangle.setPosition(this->position.x, this->position.y);
	window->draw(rectangle);
	
	// Draw bomb
	for (int i = 0; i < this->bombVector.size(); i++) {
		window->draw(*this->bombVector[i]);
	}
}


