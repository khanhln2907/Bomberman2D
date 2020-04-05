#include "../Include/Bomb.h"
#include "../Include/main.h"
#include "../Include/Map.h"

using std::cout;
using std::endl;

#define G 9.81

Bomb::Bomb(sf::Vector2f bombPosition, double length)
{
	//this->LoadImage("bullet.png");
	this->setPosition(bombPosition.x, bombPosition.y);

	this->position = new sf::Vector2f;
	this->length = new double(length);

	*this->position = bombPosition;
	this->explodedTime = new double(3.0); // Second
	this->deleteTime = new double(3.5);
	this->timer = new sf::Clock;
	this->timer->restart();
}

Bomb::~Bomb()
{
	delete this->position;
	delete this->deleteTime;
	delete this->explodedTime;
	delete this->timer;
	delete this->length;
}

bool Bomb::update(sf::RenderWindow* window)
{	
	sf::Time curTime = this->timer->getElapsedTime();
	if (curTime.asSeconds() >= (float)*this->deleteTime) {
		this->~Bomb();
		return EXPLODED;
	}
	else if (curTime.asSeconds() >= (float)*this->explodedTime) { // Explode Bomd and Draw
		sf::RectangleShape rectangleRow(sf::Vector2f((2 * *this->length + 1) * SIZE_BLOCK, SIZE_BLOCK));
		sf::RectangleShape rectangleCol(sf::Vector2f(SIZE_BOMB, (2 * *this->length + 1) * SIZE_BLOCK));
		rectangleRow.setFillColor(sf::Color::Yellow);
		rectangleCol.setFillColor(sf::Color::Yellow);

		rectangleRow.setPosition(this->position->x - *this->length * SIZE_BLOCK, this->position->y);
		rectangleCol.setPosition(this->position->x, this->position->y - *this->length * SIZE_BLOCK);

		window->draw(rectangleRow);
		window->draw(rectangleCol);
		return 0;
	}
	else { // Draw Normal Bomb
		sf::RectangleShape rectangle(sf::Vector2f(SIZE_BOMB, SIZE_BOMB));
		rectangle.setFillColor(sf::Color::Yellow);
		rectangle.setPosition(*this->position);
		window->draw(rectangle);
		return 0;
	}
}

void Bomb::explode(sf::RenderWindow* window)
{

}

