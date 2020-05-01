#include <SFML/Graphics.hpp>
#include "Menu/GameMenu.h"
#include "entities.h"
#include "GameLogic.h"
#include "tests.h"
#include <iostream>

using namespace std;

int main()
{

    sf::RenderWindow window(sf::VideoMode(800, 600), "Dodger");
	sf::Image icon;
	icon.loadFromFile("Assets/player1.png");
	window.setIcon(icon.getSize().x,icon.getSize().y ,icon.getPixelsPtr());
    GameMenu menuText(window.getSize().x, window.getSize().y);

	sf::Font font;
	font.loadFromFile("Assets/arial.ttf");
	sf::Clock clock;

    sf::Texture texture;
	sf::Texture menu;
	menu.loadFromFile("Assets/FallingRocks.png");
    texture.loadFromFile("Assets/background.png");
    sf::Sprite background(menu);
	sf::Text GameOver("GameOver",font ,50);
	GameOver.setOrigin(GameOver.getGlobalBounds().width / 2, GameOver.getGlobalBounds().height / 2);
	GameOver.setPosition(400, 300);
	bool menuState = true;
	bool newGame = false;
	bool collition = false;
	GameLogic* logic = new GameLogic(&window, 800, 600, texture);

	//Tests
	Tests test;
	cout << test.testAdjustX() << " Adjust Y " << test.testAdjustY() << " Loading Assets " << test.testLoadingAssets() << " test set origin <<" << test.testSetOrigin() << endl;


	//End Tests


	window.setFramerateLimit(256);
    while (window.isOpen())
    {
		if (newGame)
		{
			logic = new GameLogic(&window, 800, 600, texture);
			newGame = false;
		}
        sf::Event event;
        while (window.pollEvent(event))
        {
			logic->GetPlayerInput(event);
            switch (event.type)
            {
			case sf::Event::Closed:
				window.close();
				break;
            case sf::Event::KeyReleased:
                switch (event.key.code)
                {
                case sf::Keyboard::Up:
                    menuText.MoveUp();
                    break;

                case sf::Keyboard::Down:
                    menuText.MoveDown();
                    break;
				case sf::Keyboard::Escape:
					menuState = true;
					break;
                case sf::Keyboard::Return:
                    switch (menuText.pressedItem())
                    {
                    case 0: 
                        cout << "Play button was pressed" << endl;
						menuState = false;
                        break;
                    case 1:
                        window.close();
                        break;
                    }

                    break;
                }

                break;

            }

        }

        
		if (clock.getElapsedTime().asSeconds() > 3 && collition == true)
		{
			menuState = true;
			newGame = true;
			collition = false;
			

		}
		else if (collition == true)
		{
			goto end;
		}
		window.clear();
		if (menuState)
		{
			window.draw(background);
			menuText.draw(window);
	    }
		else
		{
			
			logic->SetPlayerDir();
			logic->DrawSprites();
			logic->SpawnRocks();
			logic->SetDiffuculty();
			
			if (logic->CheckCollition())
			{
				window.draw(GameOver);
				window.display();
				collition = true;
				clock.restart().asSeconds();
				window.display();
				
			}
		}
		
        window.display();
		
		end:
		{}
    }

    return 0;
}