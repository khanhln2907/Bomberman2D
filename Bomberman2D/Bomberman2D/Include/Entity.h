#pragma once
#include "../Include/State_Handler.h"
#include <string>

class Entity : public sf::Sprite {
public:
	Entity();

	// Action of all characters
	void LoadImage(sf::String filename);
	virtual void updateMove(); 
	bool CheckCollision(Entity* entity);
	
	~Entity();
private:
	sf::Vector2f* velocity;
	sf::Texture* imgHanlder;
};