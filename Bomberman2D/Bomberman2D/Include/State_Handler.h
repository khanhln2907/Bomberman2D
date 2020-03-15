#pragma once
#include <SFML/Graphics.hpp>

//class State : Actions inherit by each states used to perform game logic, render and manage memory

class State {
public:
	virtual void Initialize(sf::RenderWindow* window) {
		;
	}
	virtual void UpdateGame(sf::RenderWindow* window) {
		;
	}
	virtual void UpdateScreen(sf::RenderWindow* window) {
		;
	}
	virtual void Destroy(sf::RenderWindow* window) {
		;
	}

private:

};

// State Handler of State Machine

class State_Handler
{
public:
	State_Handler(sf::RenderWindow* window) {
		this->state = NULL;
		this->window = window;
	}
	~State_Handler() {
		this->state = NULL;
		this->window = NULL;
	}

	void SetState(State* newState) {
		if (this->state != NULL) {
			this->state->Destroy(this->window); // Destroy old state
			this->state = NULL;
		}
		if (this->state == NULL) {
			this->state = newState;
			this->state->Initialize(this->window); // Init new state and pass window ref
		}
	}

	void UpdateGame() {
		this->state->UpdateGame(this->window); // Pass Window pointer to each State so they can update game logic draw
		this->state->UpdateScreen(this->window);
	}

	void UpdateScreen() {
		this->window->display(); // Display everything at the end
	}

	void ExitState() {
		this->state->Destroy(this->window);
	}

private:
	sf::RenderWindow* window;
	State* state;
};

