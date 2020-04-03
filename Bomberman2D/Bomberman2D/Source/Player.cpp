#include "../Include/Player.h"
#include "..//Include/main.h"
#include<iostream>

#define PI 3.14
using std::cout;
using std::endl;


Player::Player()
{
	// Init
	this->LoadImage("rocket_base.jpg");
	this->setScale(sf::Vector2f(0.1, 0.1));
	this->position.x = 100;
	this->position.y = 700;
	this->setPosition(this->position.x, this->position.y);
	this->setOrigin(this->getGlobalBounds().width / 2, this->getGlobalBounds().height / 2);

	// Aiming
	this->aimAngle = PI / 6;
	this->aimPower = 50;
	this->aim = new sf::RectangleShape;
	this->aim->setSize(sf::Vector2f(100, 2));
	this->aim->setOrigin(this->aim->getGlobalBounds().width / 2, this->aim->getGlobalBounds().height / 2);
	this->aim->setFillColor(sf::Color::Red);
	this->aim->setPosition(this->position.x + 30, this->position.y + 30);
}

Player::~Player()
{
	delete this->aim;
	//delete this->bulletVector;
}

void Player::updateAim()
{
	double direction = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) - sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);
	double power = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) - sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left);
	
	this->aimAngle = this->aimAngle + direction * this->rotateSpeedRad;
	if (this->aimAngle < PI / 6) this->aimAngle = PI / 6; // 30 Deg
	if (this->aimAngle > PI * 15 / 36) this->aimAngle = PI * 15 / 36;  // 75 Deg
	this->aim->setRotation(0 - (this->aimAngle) / 2 / 3.14 * 360);
	this->setRotation(90 - (this->aimAngle) / 2 / 3.14 * 360);

	this->aimPower = this->aimPower + power * this->powerIncrement;
	if (this->aimPower < 80) this->aimPower = 80;
	if (this->aimPower > 200) this->aimPower = 200;

	//std::cout << "Angle in rad: " << this->aimAngle << std::endl;
	//std::cout << "Power : " << this->aimPower << std::endl;
}

void Player::fireBullet()
{
	if (this->bulletVector.size() <= this->maxBullet) {
		this->bulletVector.push_back(new Bullet(sf::Vector2f(this->position.x, this->position.y), this->aimAngle, this->aimPower));
	}
	// std::cout << "Bullet Fired" << std::endl;
}

void Player::updateBullet(sf::RenderWindow* window)
{
	for (int i = 0; i < this->bulletVector.size(); i++) {
		this->bulletVector[i]->updateMove(window);
		if (this->bulletVector[i]->getPosition().x > window->getSize().x || this->bulletVector[i]->getPosition().y > window->getSize().y 
		 || this->bulletVector[i]->getPosition().x < 0 || this->bulletVector[i]->getPosition().y < 0) {
			this->bulletVector[i]->~Bullet();
			this->bulletVector.erase(this->bulletVector.begin() + i);
		}
	}
	
	//cout << "Amount of Bullet: " << this->bulletVector.size() << endl;
}

void Player::drawPlayer(sf::RenderWindow* window)
{
	window->draw(*this->aim);
	for (int i = 0; i < this->bulletVector.size(); i++) {
		window->draw(*this->bulletVector[i]);
	}
}


