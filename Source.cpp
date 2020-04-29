#include <SFML/Graphics.hpp>
#include <iostream>
#include "entities.h"
#include "dodger.h"
#include "queue.h"
#include <vector>
#include <cmath>


//Menu
#include "Menu/game.h"
#include "Menu/MenuState.h"

using namespace std;

void Rocks(vector<Rock*> *rocks, int random ,int windowX)
{
	for (int x = 0; x < random; x++)
	{
		int pos = (rand() % windowX);
		int degree = rand() % 360;
		Rock *r = new Rock(0,"rock.png", pos,0);
		r->changeOrgin(r->getSprite().getGlobalBounds().width / 2, r->getSprite().getGlobalBounds().height / 2);
		
		//cout << r->getSprite().getGlobalBounds().width << "," << r->getSprite().getOrigin().y << " ";
		cout << r->getSprite().getOrigin().x<<","<< r->getSprite().getOrigin().y << " ";
		r->resizeSpriteScale(.2, .2);
		r->rotateSprite(degree);

		rocks->push_back(r);

		
	}
	
}


int main()
{
	//Menu
	Game game;
	game.pushGameState(new MenuState(&game));

	game.gameLoop();

	//End Menu

	bool left = false, right = false;
	vector<Rock*> rocks;
	sf::Texture texture;
	texture.loadFromFile("rock.png");
	int windowX = 800;
	int windowY = 600;
	// Create the main window
	sf::RenderWindow window(sf::VideoMode(windowX, windowY), "SFML window");
	// Load a sprite to display
	sf::Texture bkgd;
	bkgd.loadFromFile("background.png");
	sf::Sprite background(bkgd);
	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
		return EXIT_FAILURE;
	sf::Text text("Game Over", font, 50);
	// Load a music to play
	Player p("player.png", 400, 475);
	p.resizeSpriteScale(.25, .25);
	// Play the music
	
	// Start the game loop
	sf::Clock clock;
	double lastTime = 0;
	int counter = 0, counter2 = 0;
	int spawnValue = 500;
	int diff = 1;
	int fps = 0;
	double currentTime = clock.getElapsedTime().asSeconds();
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

		currentTime = clock.getElapsedTime().asSeconds();
		if (currentTime > 1.f)
		{
			fps = counter2 / (currentTime);
			clock.restart().asSeconds();
			counter2 = 0;
		}
		counter2++;
		
		sf::Text score("Score " + to_string(p.getScore()) + ", FPS " + to_string(fps), font, 25);
		if (counter >= 500)
		{
			Rocks(&rocks, rand()%(2+diff) ,windowX);
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
		window.draw(background);
		window.draw(score);
		window.draw(p.getSprite());
		p.updateSprite();
		// Clear screen


		if (p.getX() > windowX - 20)
		{
			p.adjustX(0);
		}
		else if (p.getX() < 0)
		{
			p.adjustX(windowX - 20);
		}

		diff = p.getScore() / 100;
		cout << diff << " " << endl;
		
		
		sf::FloatRect playerbounds = p.getSprite().getGlobalBounds();
		for (int x = 0; x < rocks.size(); x++)
		{
			//rocks.at(x)->getSprite().setTexture();
			window.draw(rocks.at(x)->getSprite());
			rocks.at(x)->updateSprite();
			if (rocks.at(x)->getY() > windowY)
			{
				rocks.erase(rocks.begin() + x);
				p.increaseScore();
				spawnValue--;
				break;
			}
			sf::FloatRect rockBounds = rocks.at(x)->getSprite().getGlobalBounds();
			double dx = (p.getX() + (playerbounds.width / 2)) - (rocks.at(x)->getX());
			double dy = (p.getY() + (playerbounds.height / 2)) - (rocks.at(x)->getY());
			double distance = sqrt((dx * dx) + (dy * dy));
			if (distance <= (playerbounds.width/2)+(rockBounds.width/2)-20)
			{
				/*
				sf::CircleShape newShape;
				sf::Vector2f v(rockBounds.width / 2, rockBounds.height / 2);
				newShape.setPosition(rocks.at(x)->getX(), rocks.at(x)->getY());
				newShape.setOrigin(rockBounds.width / 2, rockBounds.width / 2);
				newShape.setRadius(rockBounds.width / 2);
				*/

				rocks.at(x)->changeTex("hit.png");
				window.draw(rocks.at(x)->getSprite());
				
				//window.draw(text);
				//window.draw(newShape);
				//window.display();
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