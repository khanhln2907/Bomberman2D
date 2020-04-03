#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Entity : public sf::Sprite {
public:
	Entity();

	// Action of all characters
	void LoadImage(sf::String filename);
	virtual void updateMove(); 
	bool CheckCollision(Entity* entity);
	
	~Entity();

	sf::Vector2f* velocity;
private:
	sf::Texture* imgHanlder;
	double dt = 0.01;

protected:
	
};