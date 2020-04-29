#pragma once

#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include "SFML/Graphics.hpp"
#include "GameState.h"

class PlayState : public GameState
{
public:

	virtual void draw(const double dt); // Text to screen
	virtual void update(const double dt); // Update screen
	virtual void handleInput(); // Handles input

	PlayState(Game* game);

private:
	void pauseGame();

};

#endif // !PLAYSTATE_H
