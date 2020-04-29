//
// Created by Cameron on 4/26/2020.
//

#pragma once
#include "TextureManager.h"
#include "SFML/Graphics.hpp"
#include "ResourceManager.h"

// Manages textures
class TextureManager: public ResourceManager<TextureManager, sf::Texture>
{
public:
    // Constructor so if we have lots of images in our texture.txt it will not load all images at once
    // Images are loaded when needed
    // We allocate and de-allocate from the heap as needed
    TextureManager(): ResourceManager("textures.txt"){}

    sf::Texture* load(const string& fileName)
    {
        sf::Texture* text = new sf::Texture(); // Allocate memory on the heap
           
        // If the text fails to properly load it deletes the allocated memory and sets it back to NULL
        if (!text->loadFromFile(fileName))
        {
            delete text;
            text = NULL;

            cerr << "Texture failed to properly load"; // Error message
            cout << endl;
        }

        return text;
    }
};

