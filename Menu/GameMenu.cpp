#include "GameMenu.h"
#include "SFML/Graphics.hpp"

GameMenu::GameMenu(double width, double height)
{
	if (!font.loadFromFile("arial.ttf"))
	{
		cerr << "Failed to load arial.ttf" << endl;
	}

	menuText[0].setFont(font); // Sets font
	menuText[0].setFillColor(sf::Color::Red); // Sets color
	menuText[0].setString("Play Game"); // Play game to screen
	menuText[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUM_ITEMS + 1) * 1)); // Centers "Play Game" on screen

	menuText[1].setFont(font); // Sets font
	menuText[1].setFillColor(sf::Color::White); // Sets color
	menuText[1].setString("Exit Game"); // Play game to screen
	menuText[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUM_ITEMS + 1) * 2)); // Centers "Exit Game" on screen

	selectedItem = 0;
}

GameMenu::~GameMenu()
{

}

void GameMenu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_NUM_ITEMS; i++)
	{
		window.draw(menuText[i]);
	}
}

void GameMenu::MoveUp()
{
	if (selectedItem - 1 >= 0) // Checks to see if not out of bounds
	{
		menuText[selectedItem].setFillColor(sf::Color::White); // When the item is not selected (hovered over)
		selectedItem--;

		menuText[selectedItem].setFillColor(sf::Color::Red); // When the item is selected (hovered over)
	}
}

void GameMenu::MoveDown()
{
	if (selectedItem + 1 <= MAX_NUM_ITEMS) // Checks to see if not out of bounds
	{
		menuText[selectedItem].setFillColor(sf::Color::White); // When the item is not selected (hovered over)
		selectedItem++;

		menuText[selectedItem].setFillColor(sf::Color::Red); // When the item is selected (hovered over)
	}
}
