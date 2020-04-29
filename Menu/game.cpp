#include "SFML/Graphics.hpp"
#include "GameState.h"
#include "game.h"

// Constructor
Game::Game()
{
	window.create(sf::VideoMode(600, 500), "Dodger");

	window.setFramerateLimit(144);
}

// Pass in GameState pointer and add to the vector variable
void Game::pushGameState(GameState* state)
{
	states.push_back(state);
}

// Deletes last element in vector
void Game::popGameState()
{
	states.back();

	delete states.back();

	states.pop_back();
}

// Destructor
Game::~Game()
{
	while (!states.empty())
		popGameState();
}

// Returns current state of the game (menu, game screen, etc) basically whatever we want to put on the menu
GameState* Game::currState()
{
	if (states.empty())
		return nullptr;
	else
		return states.back();
}

void Game::gameLoop()
{
	// Measures elapsed time in the game
	sf::Clock clock;

	while (window.isOpen())
	{

		// For controlling framerate ----------- (Still learning what we need this for)
		sf::Time elapsed = clock.restart();
		double dt = elapsed.asSeconds();

		// Exception handling
		if (currState() == nullptr)
			continue;

		// Retrieves user input for currGameState
		currState()->handleInput();

		// Update if needed
		currState()->update(dt);

		// Clear the window
		window.clear();

		// Draw in current game state
		currState()->draw(dt);

		// Displays window
		window.display();
	}
}