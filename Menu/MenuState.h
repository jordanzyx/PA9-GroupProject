#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "SFML/Graphics.hpp"
#include "GameState.h"

class MenuState : public GameState
{
public:
	// Constructor
	MenuState(Game* game);

	virtual void draw(const double dt); // Draw to screen
	virtual void update(const double dt); // Update screen
	virtual void handleInput(); // Handles input

private: 
	// View if we want it
	sf::View view;

	// Loads game and changes game state to play game state
	void loadGame();
};

#endif // !MENUSTATE_H
