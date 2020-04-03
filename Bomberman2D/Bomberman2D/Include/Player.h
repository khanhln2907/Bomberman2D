#include "Entity.h"
#include "SFML/Graphics.hpp"
#include "Bullet.h"


class Player : public Entity {
public:
	Player();
	~Player();
	
	void updateAim();
	void fireBullet();
	void updatePosition();
	void drawPlayer(sf::RenderWindow* window);


private:
	double aimAngle;
	double aimPower = 0.1;
	double rotateSpeed = 0.05; // Degree;

	int maxBullet = 3;
	int currentAmountBullet = 0;
	sf::Vector2f position;

	Bullet** bullet;
	sf::RectangleShape* aim;
};