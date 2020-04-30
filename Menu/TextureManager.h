//
// Created by Cameron on 4/26/2020.
//

#pragma once

#include "SFML/Graphics.hpp"
#include "ResourceManager.h"

// Manages textures
class TextureManager: public ResourceManager<TextureManager, sf::Texture>
{
public:
    // Constructor so if we have lots of images in our texture.txt it will not load all images at once
    // Images are loaded when needed
    // We allocate and de-allocate from the heap as needed
    TextureManager(): ResourceManager("data/textures.txt"){}

    sf::Texture* load(const string& fileName)
    {
        // Allocating memory on the heap
        sf::Texture* text = new sf::Texture(); 
           
        // If the text fails to properly load it deletes the allocated memory and sets it back to NULL
        if (!text->loadFromFile("data/" + fileName))
        {
            delete text;
            text = NULL;

            cerr << "Texture failed to properly load"; // Error message
            cout << endl;
        }
        
        // Returns texture if texture did not fail
        return text;
    }
};

