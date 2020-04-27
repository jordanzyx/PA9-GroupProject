#include <SFML/Graphics.hpp>
#include <iostream>
#include "entities.h"
#include "dodger.h"
#include "queue.h"
#include <vector>

using namespace std;

void Rocks(vector<Rock*> *rocks, int random ,int windowX)
{
	for (int x = 0; x < random; x++)
	{
		int pos = (rand() % windowX);
		Rock *r = new Rock(0,"rock.png", pos,0);
		r->resizeSpriteScale(.2, .2);
		rocks->push_back(r);

		
	}
	
}


int main()
{
	bool left = false, right = false;
	vector<Rock*> rocks;
	sf::Texture texture;
	texture.loadFromFile("rock.png");
	int windowX = 800;
	int windowY = 600;
	// Create the main window
	sf::RenderWindow window(sf::VideoMode(windowX, windowY), "SFML window");
	// Load a sprite to display
	
	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
		return EXIT_FAILURE;
	sf::Text text("Game Over", font, 50);
	// Load a music to play
	Player p("player.png", 400, 450);
	p.resizeSpriteScale(.25, .25);
	// Play the music
	
	// Start the game loop
	
	int counter = 0;
	while (window.isOpen())
	{
		
		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Left)
				{
					left = true;
					
				}
				if (event.key.code == sf::Keyboard::Right)
				{
					right = true;
					
				}
				break;
			case sf::Event::KeyReleased:
				if (event.key.code == sf::Keyboard::Left)
				{
					left = false;

				}
				if (event.key.code == sf::Keyboard::Right)
				{
					right = false;

				}
				break;
			}
			

		}
		if (counter == 500)
		{
			Rocks(&rocks, rand()&2 ,windowX);
			counter = 0;
		}
		else
		{
			counter += 1;
		}
		if (left == true)
		{
			p.setDirection(2);
		}
		else if (right == true)
		{
			p.setDirection(3);
		}
		else
		{
			p.setDirection(1);
		}
		window.clear();

		window.draw(p.getSprite());
		p.updateSprite();
		// Clear screen
		
		for (int x = 0; x < rocks.size(); x++)
		{
			//rocks.at(x)->getSprite().setTexture();
			window.draw(rocks.at(x)->getSprite());
			rocks.at(x)->updateSprite();
			if (rocks.at(x)->getY() > windowY)
			{
				rocks.erase(rocks.begin() + x);
				p.increaseScore();
			}
			if (p.getSprite().getGlobalBounds().intersects(rocks.at(x)->getSprite().getGlobalBounds()))
			{
				window.draw(text);
				goto endOfloop;
			}
		}
		
	
		window.display();
	}
	endOfloop:
	string score = "Score " + to_string(p.getScore());
	sf::Text text2(score, font, 50);
	text2.setOrigin(50, 10);
	text2.setPosition(windowX / 2, windowY / 2);
	window.draw(text2);
	window.display();
	

	sf::Event event;
	bool cont = true;
	while (cont)
	{
		while (window.pollEvent(event))
		{
			if (sf::Event::KeyPressed)
			{
				if (sf::Event::Closed)
				{
					cont = false;
				}
				if (event.key.code == sf::Keyboard::Enter)
				{
					cont = false;
				}

			}
		}
	}

	return EXIT_SUCCESS;
}