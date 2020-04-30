#include <SFML/Graphics.hpp>
#include "GameMenu.h"

#include <iostream>

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Dodger");

    GameMenu menuText(window.getSize().x, window.getSize().y);

    sf::Texture texture;
    texture.loadFromFile("background.png");
    sf::Sprite background(texture);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::KeyReleased:
                switch (event.key.code)
                {
                case sf::Keyboard::Up:
                    menuText.MoveUp();
                    break;

                case sf::Keyboard::Down:
                    menuText.MoveDown();
                    break;

                case sf::Keyboard::Return:
                    switch (menuText.pressedItem())
                    {
                    case 0: 
                        cout << "Play button was pressed" << endl;
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

        window.clear();
        window.draw(background);
        menuText.draw(window);
        window.display();
    }

    return 0;
}