#include "../Include/Bullet.h"
#include "../Include/main.h"
#include <iostream>

using std::cout;
using std::endl;

#define G 9.81



Bullet::Bullet(sf::Vector2f firePosition, double attackAngle, double velocity)
{
	this->LoadImage("bullet.png");
	this->setScale(sf::Vector2f(0.1, 0.1));
	this->setOrigin(this->getGlobalBounds().width / 2, this->getGlobalBounds().height/ 2);
	this->setPosition(firePosition.x, firePosition.y);

	*this->dt = 0.01;
	this->position = new sf::Vector2f;
	this->direction = new double;
	this->velocity = new double;
	this->velocityXY = new sf::Vector2f;

	*this->position = firePosition;
	*this->direction = attackAngle;
	*this->velocity = velocity;
	*this->velocityXY = sf::Vector2f(*this->velocity * cos(*this->direction), -1 * *this->velocity * sin(*this->direction));
}

Bullet::~Bullet()
{
	delete this->position;
	delete this->direction;
	delete this->velocity;
	delete this->velocityXY;
	delete this->dt;
}

void Bullet::updateMove()
{	
	this->velocityXY->y +=  G * *this->dt; // vy = vy0 - gt;
	//cout << "Velocity X: " << this->velocityXY->x << endl;
	//out << "Velocity Y: " << this->velocityXY->y << endl;
	this->position->x = this->position->x + *this->dt * this->velocityXY->x; // x = x0 + dt * vx
	this->position->y = this->position->y + *this->dt * this->velocityXY->y + G * *this->dt * *this->dt / 2; // y = y0 + dt * vy - gt^2/2
	this->setPosition(*this->position);
}

