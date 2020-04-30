#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

using namespace std;

#define MAX_NUM_ITEMS 2 // For number of menu options

class GameMenu
{
private:
	int selectedItem; 
	sf::Font font; // For font
	sf::Text menuText[MAX_NUM_ITEMS]; // Text options on screen (Play, Exit)
public:
	// Constructor/destructor
	GameMenu(double width, double height);
	~GameMenu();
	void draw(sf::RenderWindow& window); // Draws window
	void MoveUp(); // Move up the menu
	void MoveDown(); // Move down the menu
	int pressedItem() { return selectedItem; } // Getting whatever they pressed (Play Game, Exit)
};

