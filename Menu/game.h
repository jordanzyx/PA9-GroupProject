#ifndef GAME_H
#define GAME_H

#include <vector>
#include "SFML/Graphics.hpp"


class GameState;

class Game
{
public:
	// Constructor/Destructor
	Game();
	~Game();

	// Push and pop functions to change the games state
	void pushGameState(GameState* state);
	void popGameState();

	// Gets current state (must be a pointer)
	GameState* currState();

	// Loop the game
	void gameLoop();

	// SFML Window
	sf::RenderWindow window;

private:
	// For different states
	std::vector<GameState*> states;

};


#endif // !GAME_H
