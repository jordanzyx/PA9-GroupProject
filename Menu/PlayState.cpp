#include <iostream>
#include "PlayState.h"
#include "MenuState.h"
#include "GameState.h"

#include <SFML/Graphics.hpp>

// Draw screen
void PlayState::draw(const double dt)
{
	sf::RectangleShape rectangle;
	
	rectangle.setPosition(sf::Vector2f(100, 100));
	rectangle.setSize(sf::Vector2f(100, 100));
	rectangle.setFillColor(sf::Color::Green);

	game->window.draw(rectangle);
}

// Not used right now
// For updating screen
void PlayState::update(const double dt)
{

}

void PlayState::handleInput()
{
	sf::Event event;

	while (this->game->window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			this->game->window.close();
			break;
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape)
			{
				pauseGame();
			}
			break;
		}
	}
}
// If escape is pressed pause the game (can change the key)
			// Close window
PlayState::PlayState(Game* game)
{
	this->game = game;
}

// Empty for now
// Pause game
void PlayState::pauseGame()
{

}