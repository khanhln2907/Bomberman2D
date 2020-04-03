#include "../Include/Player.h"
#include "..//Include/main.h"
#include<iostream>

using std::cout;
using std::endl;

Player::Player()
{
	// Init
	this->LoadImage("rocket.png");
	this->setScale(sf::Vector2f(0.5, 0.5));
	this->position.x = 50;
	this->position.y = 600;

	// Aiming
	this->aimAngle = 0;
	this->aimPower = 0;
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
	this->aim->rotate(-1 * direction * this->rotateSpeed);
	this->aimAngle = this->aimAngle + direction * this->rotateSpeed;
	//std::cout << "Angle: " << this->aimAngle << std::endl;
}

void Player::fireBullet()
{
	if (this->currentAmountBullet <= this->maxBullet) {
		this->bullet[this->currentAmountBullet] = new Bullet(sf::Vector2f(this->position.x + this->getGlobalBounds().width, this->position.y + 30), this->aimAngle, this->aimPower);
		this->currentAmountBullet += 1;
	}
	std::cout << "Bullet Fired" << std::endl;
}

void Player::updatePosition()
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


