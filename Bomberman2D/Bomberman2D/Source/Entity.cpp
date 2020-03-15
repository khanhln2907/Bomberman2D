#include "..\Include\Entity.h"
#pragma once

Entity::Entity()
{
	this->velocity = new sf::Vector2f { 0,0 };
	this->imgHanlder = new sf::Texture;
}

void Entity::LoadImage(sf::String filename)
{
	this->imgHanlder->loadFromFile("Resource/Graphics/" + filename);
	this->setTexture(*this->imgHanlder);
}

void Entity::updateMove()
{
	sf::Sprite::move(this->velocity->x, this->velocity->y);
}

bool Entity::CheckCollision(Entity* Object)
{
	return this->getGlobalBounds().intersects(Object->getGlobalBounds());
}

Entity::~Entity()
{
	delete this->imgHanlder;
	delete this->velocity;
}
