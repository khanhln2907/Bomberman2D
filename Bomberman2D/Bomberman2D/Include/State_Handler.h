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
<<<<<<< HEAD
=======

#include<iostream>
>>>>>>> 5aa47aa6f7569a7a0915f227ca40f10d7f2af765
