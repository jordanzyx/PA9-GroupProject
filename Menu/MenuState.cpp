#include "SFML/Graphics.hpp"
#include <iostream>
#include "MenuState.h"
#include "GameState.h"
#include "PlayState.h"

// Constructor
MenuState::MenuState(Game* game)
{
	// To add menu image
	menuScreen.AddResource("Background");
	menuSprite.setTexture(*(menuScreen.GetResource("Background")));

	// Temporary ------------------------------------------------------------------------------
	sf::Vector2f targetSize(800.0f, 600.0f);
	menuSprite.setScale(targetSize.x / menuSprite.getLocalBounds().width, targetSize.y / menuSprite.getLocalBounds().height);

	this->game = game;
}


// Can handle any amount of inputs
// Currently closes game and loads game
void MenuState::handleInput()
{
	sf::Event event;

	while (game->window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed: 
			game->window.close();
			break;
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape) 
				game->window.close();
		// On pressing return it loads the game (Can be changed)
			else if (event.key.code == sf::Keyboard::Return)
				loadGame();
		break;
		}
	}
}
		// Defines system event and parameters (keyboard press, etc)
		// Case for closing window
		// Change game states
		// Key can be changed to whatever we want (Currently closes the game)
		// On pressing return it loads the game (Can be changed)

// Empty for right now
// Will update the screen as needed
void MenuState::update(const double dt)
{

}

// Empty for right now
// Will draw the screen
void MenuState::draw(const double dt)
{
	game->window.draw(menuSprite);
}


// Play game state
void MenuState::loadGame()
{
	game->pushGameState(new PlayState(game));
}
