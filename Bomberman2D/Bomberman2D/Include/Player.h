#include "Entity.h"
#include "SFML/Graphics.hpp"
#include "Bullet.h"


class Player : public Entity {
public:
	Player();
	~Player();
	
	void updateAim();
	void fireBullet();
	void updateBullet();
	void drawPlayer(sf::RenderWindow* window);


private:
	double aimAngle;
	double aimPower = 100;
	double powerIncrement = 5;
	double rotateSpeedDeg = 0.05; // Deg;
	double rotateSpeedRad = rotateSpeedDeg * 2 * 3.14 / 360; // Deg;

	int maxBullet = 3;
	int currentAmountBullet = 0;
	sf::Vector2f position;

	Bullet** bullet;
	sf::RectangleShape* aim;
};