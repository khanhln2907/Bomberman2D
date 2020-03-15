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
	State_Handler() {
		this->state = NULL;
		this->window = NULL;
		this->quitGame = false;
	}
	~State_Handler() {
		this->state = NULL;
		this->window = NULL;
	}

	void SetWindow(sf::RenderWindow* window) {
		this->window = window;
	}

	void SetState(State* newState) {
		if (this->state != NULL) {
			this->state->Destroy(this->window); // Destroy old state
		}
		this->state = newState;
		if (this->state != NULL) {
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
	bool quitGame;
};

extern bool quitGame;
extern State_Handler stateHandler;