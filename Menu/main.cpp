#include <iostream>
#include "TextureManager.h"
#include "ResourceManager.h"
#include "game.h"
#include "MenuState.h"

int main()
{
    // Pseudo-code for now
    Game game;

    // Creates a pointer at game objects address to enter the menu
    game.pushGameState(new MenuState(&game)); 

    game.gameLoop();


    TextureManager txtman;
    txtman.AddResource("Background");


    sf::Sprite sprite;

    sprite.setTexture(*(txtman.GetResource("Background")));



    sf::RenderWindow window(sf::VideoMode(1080, 720), "SFML works!");


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        window.clear();
        window.draw(sprite);
        window.display();
    }

    txtman.ReleaseResource("Background");


    return 0;
}
