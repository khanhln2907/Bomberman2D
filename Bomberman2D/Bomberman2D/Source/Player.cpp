#include "../Include/Player.h"
#include "..//Include/main.h"
#include<iostream>

using std::cout;
using std::endl;

Player::Player()
{
	// Init
	this->LoadImage("rocket.png");
	this->setScale(sf::Vector2f(0.25, 0.25));
	this->position.x = 50;
	this->position.y = 800;

	// Aiming
	this->aimAngle = 0;
	this->aimPower = 0.5;
	this->aim = new sf::RectangleShape;
	this->aim->setSize(sf::Vector2f(100, 2));
	//this->aim->setOrigin(0, this->aim->getGlobalBounds().height / 2);
	this->aim->setFillColor(sf::Color::Red);
	this->aim->setPosition(this->position.x + this->getGlobalBounds().width, this->position.y + 30);

	// Bullet Management
	this->bullet = new Bullet * [this->maxBullet];
}

Player::~Player()
{
	delete this->aim;
	delete this->bullet;
}

void Player::updateAim()
{
	double direction = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) - sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);
	double power = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) - sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left);
	
	this->aim->rotate(-1 * direction * this->rotateSpeedDeg);
	this->aimAngle = this->aimAngle + direction * this->rotateSpeedRad;

	this->aimPower = this->aimPower + power * this->powerIncrement;
	if (this->aimPower < 100) this->aimPower = 100;
	if (this->aimPower > 300) this->aimPower = 300;

	//std::cout << "Angle in rad: " << this->aimAngle << std::endl;
	//std::cout << "Power : " << this->aimPower << std::endl;
}

void Player::fireBullet()
{
	if (this->currentAmountBullet <= this->maxBullet) {
		this->bullet[this->currentAmountBullet] = new Bullet(sf::Vector2f(this->position.x + this->getGlobalBounds().width, this->position.y + 30), this->aimAngle, this->aimPower);
		this->currentAmountBullet += 1;
	}
	// std::cout << "Bullet Fired" << std::endl;
}

void Player::updateBullet()
{
	for (int i = 0; i < this->currentAmountBullet; i++) {
		this->bullet[i]->updateMove();
	}
}

void Player::drawPlayer(sf::RenderWindow* window)
{
	this->setPosition(this->position.x, this->position.y);
	window->draw(*this->aim);
	for (int i = 0; i < this->currentAmountBullet; i++) {
		window->draw(*this->bullet[i]);
	}
}


