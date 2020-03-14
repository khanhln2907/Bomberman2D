#pragma once
#include <SFML/Graphics.hpp>

//class State : 

class State {
public:
	virtual void Initialize() {
		;
	}
	virtual void Update() {
		;
	}


private:

};

class State_Handler
{
public:
	State_Handler();
	~State_Handler();

	void Initialize();
	void SetState();

	

private:
	sf::RenderWindow* window;
	State* state;

};

#include<iostream>

int main() {
	std::cout << "Hi";
}